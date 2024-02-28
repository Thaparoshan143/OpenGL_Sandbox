#include"OpenGL_Window.h"

namespace OpenGL
{
	GLFWwindow* OpenGL_Window::m_window = nullptr;
	OpenGL_Window::OpenGL_Window(WindowInfo &wi, Abs::Application *targetApp)
	{
		m_targetApp = targetApp;
		this->m_winInfo = wi;
		m_keySubscriber = nullptr;
		initializeOpenGLWindow(wi.width, wi.height, wi.title);
		// Not well defined for now, later debug and find why?
		#ifdef __APPLE__
			glViewport(0, 0, wi.width*2.0, wi.height*2.0);
		#else
			glViewport(0, 0, wi.width, wi.height);
		#endif
	}

	OpenGL_Window::~OpenGL_Window()
	{
		glfwTerminate();
	}

	void OpenGL_Window::SetActive()
	{
		glfwMakeContextCurrent(this->m_window);		
	}

	void OpenGL_Window::SetColor(float r, float g, float b, float a)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(r, g, b, a);
	}

	void OpenGL_Window::SwapFrameBuffer()
	{
		glfwSwapBuffers(this->m_window);
	}

	uint OpenGL_Window::GetShaderID(String path)
	{
		return GetRawShader(path)->GetProgramID();
	}

	OpenGL_Shader* OpenGL_Window::GetRawShader(String path)
	{
		if(m_shaderList.count(path)==0)
		{
			m_shaderList.insert({path, OpenGL_Shader(path)});
			m_shaderList[path].CreateProgram();
		}

		return &m_shaderList[path];
	}

	void OpenGL_Window::initializeOpenGLWindow(int w, int h, String t)
	{
		// loading basic glfw library and more
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_SAMPLES, 4);

		#ifdef __APPLE__
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		#endif
		if(!glfwInit())
		{
			exit(-1);
		}

		this->m_window = glfwCreateWindow(w, h, t.c_str(), NULL, NULL);
		this->SetActive();

		// loader glad check if everything is loaded for use 
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			exit(-2);
		}
		
		// Setting user pointer is left to do properly
		glfwSetWindowUserPointer(this->m_window, this);

		// Registering all the callbacks for mouse and keyboard (static method inside OpenGL_Inp)
		glfwSetMouseButtonCallback(this->m_window, static_mouse_button_callback);
		glfwSetCursorPosCallback(this->m_window, static_mouse_position_callback);
		// For now using charkey callback for easy key mapping rather than mod based key callback
		glfwSetKeyCallback(this->m_window, static_key_callback);
		glfwSetCharCallback(this->m_window, static_charkey_callback);

		glfwSetFramebufferSizeCallback(this->m_window, static_framesize_callback);
	}

	void OpenGL_Window::listenActiveKeyInterrupts(int key, int mod)
	{
		if(key==GLFW_KEY_ENTER)
		{
			std::cout << "Enter key pressed!!" << std::endl;
			m_keySubscriber = nullptr;
		}
		else if(key==GLFW_KEY_BACKSPACE)
		{
			if(m_lastStringScan.size()!=0)
			{
				m_lastStringScan.pop_back();
				*m_keySubscriber = m_lastStringScan;
			}
			else
			{
				std::cout << "No input to clear!!" << std::endl;
			}
		}
		std::cout << m_lastStringScan << std::endl;
	}

	void OpenGL_Window::listenActiveKeyInterrupts(uint charKey)
	{
		m_lastStringScan += char(charKey);
		*m_keySubscriber = m_lastStringScan;
	}


	// All the static methods for input definition 
	static void static_mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
    {

    }

	static void static_mouse_position_callback(GLFWwindow *window, double xpos, double ypos)
	{

	}

	static void static_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
	{

	}

	static void static_charkey_callback(GLFWwindow *window, uint charKey)
	{

	}

	static void static_framesize_callback(GLFWwindow *window, int width, int height)
	{

	}
}