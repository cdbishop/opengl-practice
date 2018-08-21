#include "Mesh.hpp"

#include <glad/glad.h>

Mesh::Mesh(std::initializer_list<VertexPosTex> data)
	:_vertices(std::move(data)) {

	glGenVertexArrays(1, &_vertex_array);
	glGenBuffers(1, &_vertex_buffer);

	glBindVertexArray(_vertex_array);

	glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices.data(), GL_STATIC_DRAW);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &_vertex_array);
	glDeleteBuffers(1, &_vertex_buffer);
}
