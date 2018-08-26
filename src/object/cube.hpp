#pragma once

#include <System/Mesh.hpp>

class Cube : public Mesh {
public:
	static std::initializer_list<VertexPosTex> data;

	Cube(unsigned int texture);

private:
};