#include "cube.hpp"
#include "cube.hpp"

#include<glm/glm.hpp>

const std::initializer_list<VertexPosTex> Cube::data = {
	{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f) },
	{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f) },
	{ glm::vec3(0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f) },
	{ glm::vec3(0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f), },
	{ glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(0.0f, 1.0f), },
	{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f) },

	{ glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f) },
	{ glm::vec3(0.5f, -0.5f,  0.5f), glm::vec2(1.0f, 0.0f) },
	{ glm::vec3(0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 1.0f) },
	{ glm::vec3(0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 1.0f) },
	{ glm::vec3(-0.5f,  0.5f,  0.5f),  glm::vec2(0.0f, 1.0f) },
	{ glm::vec3(-0.5f, -0.5f,  0.5f),  glm::vec2(0.0f, 0.0f) },

	{ glm::vec3(-0.5f,  0.5f,  0.5f),  glm::vec2(1.0f, 0.0f) },
	{ glm::vec3(-0.5f,  0.5f, -0.5f),  glm::vec2(1.0f, 1.0f) },
	{ glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec2(0.0f, 1.0f) },
	{ glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec2(0.0f, 1.0f) },
	{ glm::vec3(-0.5f, -0.5f,  0.5f),  glm::vec2(0.0f, 0.0f) },
	{ glm::vec3(-0.5f,  0.5f,  0.5f),  glm::vec2(1.0f, 0.0f) },

	{ glm::vec3(0.5f,  0.5f,  0.5f),  glm::vec2(1.0f, 0.0f) },
	{ glm::vec3(0.5f,  0.5f, -0.5f),  glm::vec2(1.0f, 1.0f) },
	{ glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec2(0.0f, 1.0f) },
	{ glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec2(0.0f, 1.0f) },
	{ glm::vec3(0.5f, -0.5f,  0.5f),  glm::vec2(0.0f, 0.0f) },
	{ glm::vec3(0.5f,  0.5f,  0.5f),  glm::vec2(1.0f, 0.0f) },

	{ glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec2(0.0f, 1.0f) },
	{ glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec2(1.0f, 1.0f) },
	{ glm::vec3(0.5f, -0.5f,  0.5f),  glm::vec2(1.0f, 0.0f) },
	{ glm::vec3(0.5f, -0.5f,  0.5f),  glm::vec2(1.0f, 0.0f) },
	{ glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f) },
	{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f) },

	{ glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(0.0f, 1.0f) },
	{ glm::vec3(0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f) },
	{ glm::vec3(0.5f,  0.5f,  0.5f),  glm::vec2(1.0f, 0.0f) },
	{ glm::vec3(0.5f,  0.5f,  0.5f),  glm::vec2(1.0f, 0.0f) },
	{ glm::vec3(-0.5f,  0.5f,  0.5f),  glm::vec2(0.0f, 0.0f) },
	{ glm::vec3(-0.5f,  0.5f, -0.5f),  glm::vec2(0.0f, 1.0f) } };

Cube::Cube()
	:Mesh(Cube::data) {

}

Cube::Cube(std::shared_ptr<Texture> texture, glm::vec3 colour)
	:Mesh(Cube::data, texture)
{
	SetColour(colour);
}
