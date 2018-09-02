#include "cube.hpp"

#include<glm/glm.hpp>

const std::initializer_list<VertexPosTex> Cube::data_pt = {
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

const std::initializer_list<VertexPosNormal> Cube::data_pn = {
	{ glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec3(0.0f,  0.0f, -1.0f) },
    { glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec3(0.0f,  0.0f, -1.0f) }, 
    { glm::vec3(0.5f,  0.5f, -0.5f),  glm::vec3(0.0f,  0.0f, -1.0f) }, 
    { glm::vec3(0.5f,  0.5f, -0.5f),  glm::vec3(0.0f,  0.0f, -1.0f) }, 
	{ glm::vec3(-0.5f,  0.5f, -0.5f),  glm::vec3(0.0f,  0.0f, -1.0f) }, 
    { glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec3(0.0f,  0.0f, -1.0f) }, 

    { glm::vec3(-0.5f, -0.5f,  0.5f),  glm::vec3(0.0f,  0.0f, 1.0f) },
    { glm::vec3(0.5f, -0.5f,  0.5f),  glm::vec3(0.0f,  0.0f, 1.0f) },
    { glm::vec3(0.5f,  0.5f,  0.5f),  glm::vec3(0.0f,  0.0f, 1.0f) },
    { glm::vec3(0.5f,  0.5f,  0.5f),  glm::vec3(0.0f,  0.0f, 1.0f) },
    { glm::vec3(-0.5f,  0.5f,  0.5f),  glm::vec3(0.0f,  0.0f, 1.0f) },
    { glm::vec3(-0.5f, -0.5f,  0.5f),  glm::vec3(0.0f,  0.0f, 1.0f) },

    { glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f) },
    { glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f) },
    { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f) },
    { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f) },
    { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f) },
    { glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f) },

    { glm::vec3(0.5f,  0.5f,  0.5f),  glm::vec3(1.0f,  0.0f,  0.0f) },
    { glm::vec3(0.5f,  0.5f, -0.5f),  glm::vec3(1.0f,  0.0f,  0.0f) },
    { glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec3(1.0f,  0.0f,  0.0f) },
    { glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec3(1.0f,  0.0f,  0.0f) },
    { glm::vec3(0.5f, -0.5f,  0.5f),  glm::vec3(1.0f,  0.0f,  0.0f) },
    { glm::vec3(0.5f,  0.5f,  0.5f),  glm::vec3(1.0f,  0.0f,  0.0f) },

    { glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, -1.0f,  0.0f) },
    { glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, -1.0f,  0.0f) },
    { glm::vec3(0.5f, -0.5f,  0.5f),  glm::vec3(0.0f, -1.0f,  0.0f) },
    { glm::vec3(0.5f, -0.5f,  0.5f),  glm::vec3(0.0f, -1.0f,  0.0f) },
    { glm::vec3(-0.5f, -0.5f,  0.5f),  glm::vec3(0.0f, -1.0f,  0.0f) },
    { glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, -1.0f,  0.0f) },

    { glm::vec3(-0.5f,  0.5f, -0.5f),  glm::vec3(0.0f,  1.0f,  0.0f) },
    { glm::vec3(0.5f,  0.5f, -0.5f),  glm::vec3(0.0f,  1.0f,  0.0f) },
    { glm::vec3(0.5f,  0.5f,  0.5f),  glm::vec3(0.0f,  1.0f,  0.0f) },
    { glm::vec3(0.5f,  0.5f,  0.5f),  glm::vec3(0.0f,  1.0f,  0.0f) },
    { glm::vec3(-0.5f,  0.5f,  0.5f),  glm::vec3(0.0f,  1.0f,  0.0f) },
    { glm::vec3(-0.5f,  0.5f, -0.5f),  glm::vec3(0.0f,  1.0f,  0.0f) } };

Cube::Cube(const std::initializer_list<VertexPosTex>& data)
	:Mesh(data) {
}

Cube::Cube(const std::initializer_list<VertexPosTex>& data, std::shared_ptr<Texture> texture, glm::vec3 colour)
	:Mesh(data, texture)
{
	SetColour(colour);
}
