#pragma once

#include <System/VertexPosTex.hpp>
#include <System/Shader.hpp>
#include <System/Camera.hpp>
#include <object/texture.hpp>

#include <object/meshBase.hpp>

#include <vector>
#include <memory>

#include <object/mesh/impl.hpp>


class Mesh {
public:
	template<typename T>
	Mesh(std::initializer_list<T> data)
		:Mesh(std::move(data), nullptr) {
	}

	template<typename T>
	Mesh(std::initializer_list<T> data, std::shared_ptr<Texture> texture)
		:_impl(std::make_unique<mesh::Impl<T>>(std::move(data))) {
		_matrix = glm::mat4();
	}

	virtual ~Mesh();

	void SetColour(glm::vec3 colour);
	const glm::vec3& GetColour() const;

	const glm::vec3 GetPosition() const;

	void Translate(glm::vec3 movement);

	void Rotate(glm::vec3 axis, float angle);

	const glm::mat4& GetMatrix() const {
		return _matrix;
	}

	void Draw(std::shared_ptr<Shader> shader, std::shared_ptr<Camera> camera);

private:
	std::unique_ptr<mesh::BaseImpl> _impl;

	std::shared_ptr<Texture> _texture;
	glm::vec3 _colour;

	glm::mat4 _matrix;
};