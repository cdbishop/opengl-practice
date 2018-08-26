#pragma once

#include <vector>


#include <System/VertexPosTex.hpp>
#include <System/Shader.hpp>

class Mesh {
public:
	Mesh(std::vector<VertexPosTex> vertices, std::vector<unsigned int> indices, unsigned int texture);

	void Draw(Shader shader);

private:
	void Init();

private:
	unsigned int VAO;
	unsigned int VBO;

	std::vector<VertexPosTex> vertices;

};
