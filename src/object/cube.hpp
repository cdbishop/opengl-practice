#pragma once

#include <Object/mesh.hpp>

class Cube : public Mesh {
public:
	static std::initializer_list<VertexPosTex> data;

	Cube(unsigned int texture);
};