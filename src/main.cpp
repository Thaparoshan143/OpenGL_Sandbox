#include"../includes/GLAD/glad.h"
#include"../includes/GLFW/glfw3.h"

#include <iostream>

#include"./Helpers/Shader.h"
#include"./Helpers/Window.h"

using namespace Sandbox;

bool initializeGLFW()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
	if(!glfwInit())
	{
		return false;
	}
	return true;
}

#define SCR_WIDTH 800
#define SCR_HEIGHT 600

int main()
{
	if(!initializeGLFW())
	{
		return -1;
	}

	Window mainWindow(SCR_WIDTH, SCR_HEIGHT,"Sandbox");
	mainWindow.SetActive();
	
	Shader sh("../res/Shaders");
	sh.CreateProgram();

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	float boxVertices[] = {
		-1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,	//0
		-1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,	//1	
		-0.7f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,	//2
		-0.7f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f	//3
	};

	while (!mainWindow.ShouldCloseWindow())
	{
		mainWindow.SetColor(1, 1, 1, 1);

		mainWindow.SwapFrameBuffer();
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}