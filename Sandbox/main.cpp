#include"../includes/GLAD/glad.h"
#include"../includes/GLFW/glfw3.h"

#include <iostream>

#include"../Platform/OpenGL/OpenGL_Shader.h"
#include"../Platform/OpenGL/OpenGL_Window.h"
#include"../Platform/OpenGL/OpenGL_Application.h"
#include"../Platform/OpenGL/OpenGL_Buffer.h"

#define TESTMODE
#include"../Util/VertexGenerator.cpp"

using namespace OpenGL;
using Window = OpenGL_Window;
using Shader = OpenGL_Shader;
using Application = OpenGL_Application;

// Draw mod defines wether to draw triangle (1) or quad (0) using array method..
#define DRAW_MOD 0

#define SCR_WIDTH 800
#define SCR_HEIGHT 600

class SandboxApp : OpenGL_Application
{
	public:
	SandboxApp(ApplicationInfo appInfo):OpenGL_Application(appInfo) {}
	~SandboxApp() {		}

	void Initialize() override 
	{

	}

	void Loop() override 
	{
		float *quadVerts = get_quad_buffer(fVec2(0.5), fVec2(0.8), Color3(1.0, 0.5, 0.2));
		uint *quadIBO = get_quad_index();

		VertexArrayObject VAO(BufferLayout::PPP_RGB);
		VertexBufferObject VBO;
		IndexBufferObject IBO;
		VAO.Bind();
		IBO.PushData(quadIBO, 6);
		VBO.PushData(quadVerts, 36);
		VBO.OffloadData();
		IBO.OffloadData();
		VAO.SetVertexAttributePointer();

		Shader *temp = this->GetRawShader("../res/Shaders/");

		while (!m_window->ShouldCloseWindow())
		{
			m_window->SetColor(1, 1, 1, 1);
			temp->UseProgram();	

			glDrawElements(GL_TRIANGLES, 100, GL_UNSIGNED_INT, 0);

			m_window->SwapFrameBuffer();
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