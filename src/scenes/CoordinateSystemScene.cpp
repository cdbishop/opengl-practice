#include "CoordinateSystemScene.hpp"

#include "../external/stb_image.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <stdexcept>


#include "System/Application.hpp"
#include "System/ShaderManager.hpp"
#include <System/Camera.hpp>
#include <System/FPSCamera.hpp>
#include "Math/Vector.hpp"

CoordinateSystemScene::CoordinateSystemScene()
{
}

CoordinateSystemScene::~CoordinateSystemScene()
{
}

void CoordinateSystemScene::Init()
{
	GetApplication()->EnableDepthBuffer();

	createTexture();

	_cube = std::make_shared<Cube>(_texture);
	_cube2 = std::make_shared<Cube>(_texture);

	_shader = GetApplication()->GetShaderManager()->CreateProgram("textured_coordsys", "textured_coordsys");

	_cube->Rotate(glm::vec3(1.0f, 0.0f, 0.0f), glm::radians(-55.0f));
	_cube->Translate(glm::vec3(-5.0f, 0.0f, 0.0f));

	_cube2->Rotate(glm::vec3(1.0f, 0.0f, 0.0f), glm::radians(55.0f));
	_cube2->Translate(glm::vec3(0.0f, 0.0f, 0.0f));
	
	_camera = std::make_shared<FPSCamera>(glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, -1.0f),
		glm::vec3(0.0f, 1.0f, 0.0f), GetApplication()->GetAspectRatio(), 0.1f, 100.0f, GetApplication());
}

void CoordinateSystemScene::createTexture()
{
	//texture
	int width, height, nChannels;
	unsigned char* data = stbi_load("./bin/data/textures/wall.jpg", &width, &height, &nChannels, 0);
	if (!data) {
		std::cerr << "Failed to load texture" << std::endl;
		throw std::runtime_error("Failed to load texture");
	}

	glGenTextures(1, &_texture);

	glBindTexture(GL_TEXTURE_2D, _texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);
}

void CoordinateSystemScene::Update()
{
	_cube->Rotate(glm::vec3(1.0f, 0.0f, 0.0f), glm::radians(-0.5f));
	_cube2->Rotate(glm::vec3(1.0f, 0.0f, 0.0f), glm::radians(0.5f));

	_camera->Update();
}

void CoordinateSystemScene::Render()
{
	_cube->Draw(_shader, _camera);

	_cube2->Draw(_shader, _camera);
}

