#include"../includes/GLAD/glad.h"
#include"../includes/GLFW/glfw3.h"

#include <iostream>

#include"../Platform/OpenGL/OpenGL_Shader.h"
#include"../Platform/OpenGL/OpenGL_Window.h"
#include"../Platform/OpenGL/OpenGL_App.h"

using namespace OpenGL;
using Window = OpenGL_Window;
using Shader = OpenGL_Shader;
using Application = OpenGL_App;

// Draw mod defines wether to draw triangle (1) or quad (0) using array method..
#define DRAW_MOD 0

#define SCR_WIDTH 800
#define SCR_HEIGHT 600

class SandboxApp : OpenGL_App
{
	public:
	SandboxApp(ApplicationInfo appInfo):OpenGL_App(appInfo) {}
	~SandboxApp() {	}

	void Initialize() override 
	{

	}

	void Loop() override 
	{
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

		Shader *temp = GetRawShader("../res/Shaders/");

		while (!m_targetWindow->ShouldCloseWindow())
		{
			m_targetWindow->SetColor(1, 1, 1);
			temp->UseProgram();	

			glDrawArrays(GL_TRIANGLES, 0, DRAW_MOD ? 3 : 6);

			m_targetWindow->SwapFrameBuffer();
			glfwPollEvents();
		}
	}
};

int main()
{
	ApplicationInfo appInfo(SCR_WIDTH, SCR_HEIGHT, "Sandbox");
	SandboxApp mainApp(appInfo);

	mainApp.Initialize();
	mainApp.Loop();

	return 0;
}