#pragma once
#include <map>
#include <limits>
#include <functional>

#include <glad/glad.h>

#include <glm/glm.hpp>

#include "..\Math\Vector.hpp"

class Shader
{
public:
	typedef std::function<void(const std::string& variable, Shader*)> UniformCallback;

	Shader(unsigned int program);
	~Shader();

	template<typename T>
	void SetUniformValue(const std::string& variable, const T& value);

	template<typename T>
	void SetUniformValuePtr(const std::string& variable, const T& value);

	void SetVariableCb(const std::string& variable, UniformCallback callback);

	void UpdateUniforms();

	unsigned int GetId();

private:
	void UpdateUniform(const std::string& variable);

	template<typename T, typename IsVector3 = typename std::enable_if<std::is_same<T, glm::vec3>::value>::type>
	void SetUniform(const std::string& variable, const T& value);

	template<typename T, typename IsIntegral = typename std::enable_if<std::is_integral<T>::value && !std::is_floating_point<T>::value>::type>
	void SetUniform(const std::string& variable, T value);

	template<typename T, typename IsFloat = typename std::enable_if<std::is_floating_point<T>::value && !std::is_integral<T>::value>::type>
	void SetUniform(const std::string& variable, T value);

	template<typename T, typename IsFloatPtr = typename std::enable_if<std::is_same<T, float*>::value>::type>
	void SetUniformPtr(const std::string& variable, T value);

private:
	unsigned int _program;
	std::map<std::string, unsigned int> _uniforms;

	std::map<std::string, UniformCallback> _uniform_callbacks;
};

template<typename T>
inline void Shader::SetUniformValue(const std::string & variable, const T & value)
{
	if (!_uniforms.count(variable)) {
		_uniforms[variable] = glGetUniformLocation(_program, variable.c_str());
	/*	if (!_uniforms[variable]) {
			throw std::runtime_error("Unable to find variable: " + variable + " in shader");
		}*/
	}

	SetUniform(variable, value);
}

template<typename T>
inline void Shader::SetUniformValuePtr(const std::string & variable, const T & value)
{
	if (!_uniforms.count(variable)) {
		_uniforms[variable] = glGetUniformLocation(_program, variable.c_str());
		//if (!_uniforms[variable]) {
		//	throw std::runtime_error("Unable to find variable: " + variable + " in shader");
		//}
	}

	SetUniformPtr(variable, value);
}

template<typename T, typename IsVector3>
inline void Shader::SetUniform(const std::string & variable, const T & value)
{
	glUniform3f(_uniforms[variable], value.x, value.y, value.z);
}

template<typename T, typename IsIntegral>
void Shader::SetUniform(const std::string& variable, T value) {
	glUniform1i(_uniforms[variable], value);
}

template<typename T, typename IsFloatPtr>
void Shader::SetUniformPtr(const std::string& variable, T value) {
	glUniformMatrix4fv(_uniforms[variable], 1, GL_FALSE, value);
}
