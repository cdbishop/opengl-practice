#include "Application.hpp"
#include <iostream>


Application::Application(unsigned int width, unsigned int height)
	:_width(width),
	_height(height),
	_window(NULL)
{
	//_currentScene->SetApp(this);

	Init();

	_shaderManager = std::make_shared<ShaderManager>("../Debug");

	//_currentScene->Init();
}

Application::~Application()
{
	glfwTerminate();
}

void Application::Init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	_window = glfwCreateWindow(_width, _height, "OpenGLTut", NULL, NULL);
	if (_window == NULL) {
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW Window");		
	}

	glfwMakeContextCurrent(_window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {		
		throw std::runtime_error("Failed to initialize GLAD");
	}

	glViewport(0, 0, _width, _height);

	glfwSetWindowUserPointer(_window, this);

	glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);

	int maxAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &maxAttributes);
	std::cout << "Max vertex attributes supported: " << maxAttributes << std::endl;
}

void Application::Run()
{
	while (!glfwWindowShouldClose(_window)) {
		Update();
		Render();
	}
}

void Application::RegisterScene(const std::string& sceneName, std::unique_ptr<Scene> scene)
{
	_scenes[sceneName] = std::move(scene);
	_scenes[sceneName]->SetApp(this);
}

void Application::SetScene(const std::string & sceneName)
{
	_currentScene = sceneName;
	_scenes[_currentScene]->Init();
}

std::shared_ptr<ShaderManager> Application::GetShaderManager()
{
	return _shaderManager;
}

void Application::Update()
{
	_scenes[_currentScene]->Update();
}

void Application::OnFrameBufferResize(int width, int height)
{
	glViewport(0, 0, width, height);
}

void Application::PreRender()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Application::Render()
{
	PreRender();
	_scenes[_currentScene]->Render();
	PostRender();
}

void Application::PostRender()
{
	glfwSwapBuffers(_window);
	glfwPollEvents();
}
