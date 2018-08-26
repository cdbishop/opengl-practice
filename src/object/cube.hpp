#pragma once

#include <Object/mesh.hpp>

class Cube : public Mesh {
public:
	static const std::initializer_list<VertexPosTex> data;

	Cube();
	Cube(std::shared_ptr<Texture> texture, glm::vec3 colour = glm::vec3(1.0f, 1.0f, 1.0f));
};