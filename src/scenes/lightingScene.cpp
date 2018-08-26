#include "LightingScene.hpp"

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

LightingScene::LightingScene()
{
}

LightingScene::~LightingScene()
{
}

void LightingScene::Init()
{
	GetApplication()->EnableDepthBuffer();

	_cube1 = std::make_shared<Cube>(nullptr, glm::vec3(1.0f, 1.0f, 1.0f));
	_cube2 = std::make_shared<Cube>(nullptr, glm::vec3(0.5f, 0.5f, 0.2f));

	_lamp_shader = GetApplication()->GetShaderManager()->CreateProgram("colour_transform", "colour_transform");
	_object_shader = GetApplication()->GetShaderManager()->CreateProgram("ambient_transform", "ambient_transform");

	_cube1->Rotate(glm::vec3(1.0f, 0.0f, 0.0f), glm::radians(-55.0f));
	_cube1->Translate(glm::vec3(-5.0f, 0.0f, 0.0f));

	_cube2->Rotate(glm::vec3(1.0f, 0.0f, 0.0f), glm::radians(-55.0f));
	_cube2->Translate(glm::vec3(2.0f, 0.0f, 0.0f));

	_camera = std::make_shared<FPSCamera>(glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, -1.0f),
		glm::vec3(0.0f, 1.0f, 0.0f), GetApplication()->GetAspectRatio(), 0.1f, 100.0f, GetApplication());

	_object_shader->SetVariableCb("lightColour", [&](const std::string& variable, Shader* shader) {
		shader->SetUniformValue(variable, _cube1->GetColour());
	});

	_object_shader->SetUniformValue("ambientStrength", 0.1f);
}

void LightingScene::Update()
{
	_camera->Update();
}

void LightingScene::Render()
{
	_cube1->Draw(_lamp_shader, _camera);
	_cube2->Draw(_object_shader, _camera);
}

