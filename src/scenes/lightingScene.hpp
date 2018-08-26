#pragma once
#include <System/Scene.hpp>
#include <object/cube.hpp>

#include <glm/glm.hpp>

#include <array>

class Shader;
class Camera;

class LightingScene : public Scene
{
public:
	LightingScene();
	~LightingScene();

	void Init();
	void Update();
	void Render();

private:
	std::shared_ptr<Cube> _cube1;
	std::shared_ptr<Cube> _cube2;
	std::shared_ptr<Shader> _lamp_shader;
	std::shared_ptr<Shader> _object_shader;
	std::shared_ptr<Camera> _camera;
};

