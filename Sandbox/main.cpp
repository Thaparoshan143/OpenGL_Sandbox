#include"../includes/GLAD/glad.h"
#include"../includes/GLFW/glfw3.h"

#include <iostream>

#include"./Helpers/Shader.h"
#include"./Helpers/Window.h"

using namespace Sandbox;

// Draw mod defines wether to draw triangle (1) or quad (0) using array method..
#define DRAW_MOD 1

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

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	Shader sh("../res/Shaders/");
	sh.CreateProgram();

	float triangleVerts[] = {
		0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,	//0
		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,	//1	
		0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,	//2
	};

	float quadVerts[] = {
	0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,	//0
	0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,	//1	
	-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,	//2
	0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,	//3
	-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,	//4
	-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,	//5
	};

	float *Vertices = DRAW_MOD ? triangleVerts  : quadVerts;
	int verticesSize = (DRAW_MOD ? 18 : 36) * sizeof(float); 

	uint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	uint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, verticesSize, Vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (const void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (const void*)(sizeof(float)*3));
	glEnableVertexAttribArray(1);

	while (!mainWindow.ShouldCloseWindow())
	{
		mainWindow.SetColor(1, 1, 1, 1);
		sh.UseProgram();

		glDrawArrays(GL_TRIANGLES, 0, DRAW_MOD ? 3 : 6);

		mainWindow.SwapFrameBuffer();
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}