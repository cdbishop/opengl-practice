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

	_texture = std::make_shared<Texture>("./bin/data/textures/wall.jpg");
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

