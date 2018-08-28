#pragma once
#include <System/Scene.hpp>
#include <object/cube.hpp>
#include <object/texture.hpp>

#include <glm/glm.hpp>

#include <array>
#include <memory>

class Shader;
class Camera;

class CoordinateSystemScene : public Scene
{
public:
	CoordinateSystemScene();
	~CoordinateSystemScene();

	void Init();
	void Update();
	void Render();

private:
	std::shared_ptr<Cube> _cube;
	std::shared_ptr<Cube> _cube2;
	
	std::shared_ptr<Shader> _shader;
	std::shared_ptr<Texture> _texture;

	std::shared_ptr<Camera> _camera;
};
