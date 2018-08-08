#pragma once
#include <System/Scene.hpp>

#include <glm/glm.hpp>

#include <array>

class Shader;

class CoordinateSystemScene : public Scene
{
public:
	CoordinateSystemScene();
	~CoordinateSystemScene();

	void Init();
	void Update();
	void Render();

private:
	std::array<float, 180> _vertices;
	
	unsigned int _vertex_buffer;
	unsigned int _vertex_array;
	
	std::shared_ptr<Shader> _shader;
	unsigned int _texture;

	glm::mat4 _model;
	glm::mat4 _view;
	glm::mat4 _projection;
};
