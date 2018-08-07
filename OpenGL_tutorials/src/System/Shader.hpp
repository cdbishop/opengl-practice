#pragma once
#include <map>

#include <glad/glad.h>

#include "..\Math\Vector.hpp"

class Shader
{
public:
	Shader(unsigned int program);
	~Shader();

	template<typename T>
	void SetUniformValue(const std::string& variable, const T& value);

	unsigned int GetId();

private:
	template<typename T, typename = typename std::enable_if<std::is_same<T, Vector<4>>::value>::type>
	void SetUniform(const std::string& variable, const T& value);

	template<typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
	void SetUniform(const std::string& variable, T value);

private:
	unsigned int _program;
	std::map<std::string, unsigned int> _uniforms;
};

template<typename T>
inline void Shader::SetUniformValue(const std::string & variable, const T & value)
{
	if (!_uniforms.count(variable)) {
		_uniforms[variable] = glGetUniformLocation(_program, variable.c_str());
	}

	SetUniform(variable, value);
}

template<typename T, typename = typename std::enable_if<std::is_same<T, Vector<4>>::value>::type>
void Shader::SetUniform(const std::string& variable, const T& value) {
	glUniform4f(_uniforms[variable], value.x(), value.y(), value.z(), value.w());
}

template<typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
void Shader::SetUniform(const std::string& variable, T value) {
	glUniform1i(_uniforms[variable], value);
}
