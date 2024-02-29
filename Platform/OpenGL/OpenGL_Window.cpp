#include"OpenGL_Window.h"

namespace OpenGL
{
	OpenGL_Window::OpenGL_Window(Interface::IApplication &targetApp, WindowInfo &wi) : IWindow(targetApp)
	{
		this->m_winInfo = wi;
		initializeOpenGLWindow(wi.width, wi.height, wi.title);
		// Yet don't have justifyable answer but the viewport in apple and other system are initialized in different ways
		#ifdef __APPLE__
			glViewport(0, 0, wi.width*2, wi.height*2);
		#else
			glViewport(0, 0, wi.width, wi.height);
		#endif

	}

	void OpenGL_Window::SetColor(float r, float g, float b, float a)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(r, g, b, a);
	}

	void OpenGL_Window::initializeOpenGLWindow(int w, int h, String t)
	{	
		// loading basic glfw library and more
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		#ifdef __APPLE__
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		#endif

		if(!glfwInit())
		{
			exit(-1);
		}

		this->m_glfwWindow = glfwCreateWindow(w, h, t.c_str(), nullptr, nullptr);
		this->SetActive();

		// loader glad check if everything is loaded for use 
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			exit(-2);
		}

		// setting user pointer to the current instance of the window for later access
		glfwSetWindowUserPointer(this->m_glfwWindow, this);
	}
}