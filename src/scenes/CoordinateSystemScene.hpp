#pragma once
#include <System/Scene.hpp>
#include <object/cube.hpp>

#include <glm/glm.hpp>

#include <array>

class Shader;
class Camera;

class CoordinateSystemScene : public Scene
{
public:
	CoordinateSystemScene();
	~CoordinateSystemScene();

	void Init();
	void createTexture();
	void Update();
	void Render();

private:
	std::shared_ptr<Cube> _cube;
	std::shared_ptr<Cube> _cube2;
	
	std::shared_ptr<Shader> _shader;
	unsigned int _texture;

	glm::mat4 _model;
	//glm::mat4 _view;
	//glm::mat4 _projection;
	std::shared_ptr<Camera> _camera;
};
