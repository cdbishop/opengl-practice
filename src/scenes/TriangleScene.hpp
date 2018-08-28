#pragma once
#include <System/Scene.hpp>

#include <array>
#include <memory>

class Shader;

class TriangleScene : public Scene
{
public:
	TriangleScene();
	~TriangleScene();

	void Init();
	void Update();
	void Render();

private:
	std::array<float, 18> _vertices;
	unsigned int _vertex_buffer;
	unsigned int _vertex_array;
	std::shared_ptr<Shader> _shader;
};
