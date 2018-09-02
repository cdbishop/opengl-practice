#pragma once

#include <Object/mesh.hpp>

#include <system/VertexPosNormal.hpp>
#include <system/VertexPosTex.hpp>

class Cube : public Mesh {
public:
	static const std::initializer_list<VertexPosTex> data_pt;
	static const std::initializer_list<VertexPosNormal> data_pn;

	Cube(const std::initializer_list<VertexPosTex>& data);
	Cube(const std::initializer_list<VertexPosTex>& data, std::shared_ptr<Texture> texture, glm::vec3 colour = glm::vec3(1.0f, 1.0f, 1.0f));
};