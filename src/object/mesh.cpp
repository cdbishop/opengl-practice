#include "mesh.hpp"

#include <glad/glad.h>

#include <glm/gtc/matrix_transform.hpp>

Mesh::~Mesh()
{
	
}

void Mesh::SetColour(glm::vec3 colour)
{
	_colour = colour;
}

const glm::vec3 & Mesh::GetColour() const
{
	return _colour;
}

const glm::vec3 Mesh::GetPosition() const {
	return glm::vec3(_matrix[0][0], _matrix[0][1], _matrix[0][2]);
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
	glm::mat4 model = GetMatrix();
	glm::mat4 view = camera->GetView();
	glm::mat4 proj = camera->GetProjection();

	if (shader->HasUniform("mvp"))
		shader->SetUniformValuePtr("mvp", glm::value_ptr(mvp));

	if (shader->HasUniform("model"))
		shader->SetUniformValuePtr("model", glm::value_ptr(model));

	if (shader->HasUniform("view"))
		shader->SetUniformValuePtr("view", glm::value_ptr(view));

	if (shader->HasUniform("projection"))
		shader->SetUniformValuePtr("projection", glm::value_ptr(proj));

	if (_texture) {
		glBindTexture(GL_TEXTURE_2D, _texture->Id());
		shader->SetUniformValue("inTexture", 0);
	}

	shader->SetUniformValue("objectColour", _colour);

	shader->UpdateUniforms();

	glBindVertexArray(_impl->_vertex_array);
	glDrawArrays(GL_TRIANGLES, 0, _impl->_num_triangles);
}
