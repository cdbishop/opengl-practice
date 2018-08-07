#include <Windows.h>
#include <stdexcept>
#include <iostream>
#include <System/Application.hpp>

#include <scenes/TriangleScene.hpp>
#include <scenes/TexturedTriangleScene.hpp>


int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	//Application app(800, 600, std::move(std::make_unique<TriangleScene>()));
	Application app(800, 600);
	app.RegisterScene("triangleSceneBlockColor", std::move(std::make_unique<TriangleScene>()));
	app.RegisterScene("triangleSceneMultiColor", std::move(std::make_unique<TriangleScene>()));
	app.RegisterScene("TexturedTriangleScene", std::move(std::make_unique<TexturedTriangleScene>()));
	app.SetScene("TexturedTriangleScene");

	try {
		app.Run();
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Failed to run application: " << e.what() << std::endl;
		return -1;
	}

	return 0;
}
