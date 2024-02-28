#include"OpenGL_App.h"

namespace OpenGL
{
	OpenGL_App::OpenGL_App(ApplicationInfo &appInfo) 
	{
		std::cout << "OpenGL Application created!" << std::endl;
		this->m_targetWindow = new OpenGL_Window(appInfo, this);
		this->m_targetWindow->m_winInfo = appInfo;
		initializeGLEnable();
	}

	OpenGL_App::~OpenGL_App()
	{
		glfwTerminate();
		delete[] this->m_targetWindow;
	}

	void OpenGL_App::UpdateTarget(OpenGL_Window *targetWindow)
	{
		m_targetWindow = targetWindow;
		m_targetWindow->m_winInfo = targetWindow->m_winInfo;
	}

	void* OpenGL_App::GetReference(Abs::AppRef appRef)
	{
		if(appRef==Abs::AppRef::SELF)
		{
			return (OpenGL_App*)this;
		}
		std::cout << "Error while passing references..." << std::endl;
		return nullptr;
	}

	ApplicationInfo OpenGL_App::GetAppInfo()
	{
		return m_targetWindow->GetWindowInfo();
	}

	void OpenGL_App::initializeGLEnable()
	{
		glEnable(GL_BLEND);
		glEnable(GL_LINE_SMOOTH); 
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
}