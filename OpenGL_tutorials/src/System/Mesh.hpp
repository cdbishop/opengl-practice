#pragma once

#include <System/VertexPosTex.hpp>

#include <vector>

class Mesh {
public:
	Mesh(std::initializer_list<VertexPosTex> data);
	virtual ~Mesh();

private:
	std::vector<VertexPosTex> _vertices;

	unsigned int _vertex_buffer;
	unsigned int _vertex_array;
};