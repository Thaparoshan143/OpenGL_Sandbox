#include"OpenGL_Application.h"

namespace OpenGL
{
	OpenGL_Application::OpenGL_Application(ApplicationInfo &appInfo)
	{
		std::cout << "OpenGL Application created!" << std::endl;
		this->m_window = new OpenGL_Window(*this, appInfo);
		initializeGLEnable();
	}

	OpenGL_Application::~OpenGL_Application()
	{
		delete this->m_window;
		glfwTerminate();
	}

	void OpenGL_Application::SetWindow(OpenGL_Window *targetWin)
	{
		this->m_window = targetWin;
	}

	uint OpenGL_Application::GetShaderID(String path)
	{
		return GetRawShader(path)->GetProgramID();
	}

	OpenGL_Shader* OpenGL_Application::GetRawShader(String path)
	{
		if(m_shaderList.count(path) == 0)
		{
			m_shaderList.insert({path, OpenGL_Shader(path)});
			m_shaderList[path].CreateProgram();
		}

		return &m_shaderList[path];
	}

	void OpenGL_Application::initializeGLEnable()
	{
		glEnable(GL_BLEND);
		glEnable(GL_LINE_SMOOTH); 
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
}