#include <Windows.h>
#include <stdexcept>
#include <iostream>
#include <System/Application.hpp>

#include <scenes/TriangleScene.hpp>
#include <scenes/TexturedQuadScene.hpp>
#include <scenes/TransformationScene.hpp>
#include <scenes/CoordinateSystemScene.hpp>

//int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
int main(int argc, char** argv) {

	Application app(800, 600);
	app.RegisterScene("triangleSceneBlockColor", std::move(std::make_unique<TriangleScene>()));
	app.RegisterScene("triangleSceneMultiColor", std::move(std::make_unique<TriangleScene>()));
	app.RegisterScene("texturedQuadScene", std::move(std::make_unique<TexturedQuadScene>()));
	app.RegisterScene("transformationScene", std::move(std::make_unique<TransformationScene>()));
	app.RegisterScene("coordinateSystemScene", std::move(std::make_unique<CoordinateSystemScene>()));

	app.SetScene("coordinateSystemScene");

	try {
		app.Run();
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Failed to run application: " << e.what() << std::endl;
		return -1;
	}

	return 0;
}
