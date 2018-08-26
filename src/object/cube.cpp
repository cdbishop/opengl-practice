#include "cube.hpp"
#include "cube.hpp"

#include<glm/glm.hpp>

std::initializer_list<VertexPosTex> Cube::data = {
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

Cube::Cube(unsigned int texture)
	:Mesh(Cube::data, texture)
{
}
