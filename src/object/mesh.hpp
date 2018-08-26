#pragma once

#include <System/VertexPosTex.hpp>
#include <System/Shader.hpp>
#include <System/Camera.hpp>
#include <object/texture.hpp>

#include <vector>
#include <memory>


class Mesh {
public:
	Mesh(std::initializer_list<VertexPosTex> data);
	Mesh(std::initializer_list<VertexPosTex> data, std::shared_ptr<Texture> texture);
	virtual ~Mesh();

	void SetColour(glm::vec3 colour);
	const glm::vec3& GetColour() const;

	void Translate(glm::vec3 movement);

	void Rotate(glm::vec3 axis, float angle);

	const glm::mat4& GetMatrix() const {
		return _matrix;
	}

	void Draw(std::shared_ptr<Shader> shader, std::shared_ptr<Camera> camera);

private:
	std::vector<VertexPosTex> _vertices;
	std::shared_ptr<Texture> _texture;
	glm::vec3 _colour;

	glm::mat4 _matrix;

	unsigned int _vertex_buffer;
	unsigned int _vertex_array;

	unsigned int _num_triangles;
};