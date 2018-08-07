#include "TriangleScene.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include "System/Application.hpp"
#include "System/ShaderManager.hpp"
#include "Math/Vector.hpp"

TriangleScene::TriangleScene()
	:_vertices(
		{{ -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
		0.0f, 0.5f, 0.0f,  0.0f, 0.0f, 1.0f}})
{
}

TriangleScene::~TriangleScene()
{
	glDeleteVertexArrays(1, &_vertex_array);
	glDeleteBuffers(1, &_vertex_buffer);
}

void TriangleScene::Init()
{
	glGenVertexArrays(1, &_vertex_array);
	glGenBuffers(1, &_vertex_buffer);
	
	glBindVertexArray(_vertex_array);

	glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
		
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//_shader = GetApplication()->GetShaderManager()->CreateProgram("colour", "colour");
	_shader = GetApplication()->GetShaderManager()->CreateProgram("multicolour", "multicolour");
}

void TriangleScene::Update()
{
}

void TriangleScene::Render()
{
	glUseProgram(_shader->GetId());

	float timeValue = static_cast<float>(glfwGetTime());
	float greenValue = (sinf(timeValue) / 2.0f) + 0.5f;
	//_shader->SetUniformValue("col", Vector<4>(0.0f, greenValue, 0.0f, 0.0f));

	glBindVertexArray(_vertex_array);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
