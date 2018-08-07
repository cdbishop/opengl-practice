#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <System/Scene.hpp>
#include <System/ShaderManager.hpp>

#include <memory>

class Application
{
public:
	Application(unsigned int width, unsigned int height);
	virtual ~Application();

	void Run();

	void RegisterScene(const std::string& sceneName, std::unique_ptr<Scene> scene);
	void SetScene(const std::string& sceneName);

	std::shared_ptr<ShaderManager> GetShaderManager();

private:
	void Init();

	static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		Application* pApp = static_cast<Application*>(glfwGetWindowUserPointer(window));	
	}

	void OnFrameBufferResize(int width, int height);

	void Update();

	void PreRender();
	void Render();
	void PostRender();

private:
	unsigned int _width;
	unsigned int _height;
	GLFWwindow* _window;

	std::string _currentScene;
	std::map<std::string, std::unique_ptr<Scene>> _scenes;

	std::shared_ptr<ShaderManager> _shaderManager;
};

