#include "mesh.hpp"

#include <glad/glad.h>

#include <glm/gtc/matrix_transform.hpp>

Mesh::Mesh(std::initializer_list<VertexPosTex> data)
	:Mesh(std::move(data), nullptr) {
}

Mesh::Mesh(std::initializer_list<VertexPosTex> data, std::shared_ptr<Texture> texture)
	:_vertices(std::move(data)),
	_texture(texture),
	_num_triangles(static_cast<unsigned int>(_vertices.size())),
	_colour(glm::vec3(1.0f, 1.0, 1.0f)) {

	glGenVertexArrays(1, &_vertex_array);
	glGenBuffers(1, &_vertex_buffer);

	glBindVertexArray(_vertex_array);

	glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(VertexPosTex), &_vertices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	_matrix = glm::mat4();
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &_vertex_array);
	glDeleteBuffers(1, &_vertex_buffer);
}

void Mesh::SetColour(glm::vec3 colour)
{
	_colour = colour;
}

const glm::vec3 & Mesh::GetColour() const
{
	return _colour;
}

void Mesh::Translate(glm::vec3 movement)
{
	_matrix = glm::translate(_matrix, movement);
}

void Mesh::Rotate(glm::vec3 axis, float angle)
{
	_matrix = glm::rotate(_matrix, angle, axis);;

}

void Mesh::Draw(std::shared_ptr<Shader> shader, std::shared_ptr<Camera> camera)
{
	glUseProgram(shader->GetId());

	glm::mat4 mvp = camera->GetProjection() * camera->GetView() * GetMatrix();
	shader->SetUniformValuePtr("mvp", glm::value_ptr(mvp));

	if (_texture) {
		glBindTexture(GL_TEXTURE_2D, _texture->Id());
		shader->SetUniformValue("inTexture", 0);
	}

	shader->SetUniformValue("objectColour", _colour);

	shader->UpdateUniforms();

	glBindVertexArray(_vertex_array);
	glDrawArrays(GL_TRIANGLES, 0, _num_triangles);
}
