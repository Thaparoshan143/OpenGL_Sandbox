#pragma once

#include"../../Core/Application.h"

#include"./OpenGL_Window.h"

// using same info mode for both, contains width, height and the title of window
typedef WindowInfo ApplicationInfo;

namespace OpenGL
{
	class OpenGL_App : public Abs::Application
	{
		public:
		OpenGL_App(ApplicationInfo &appInfo);
		~OpenGL_App();

		void UpdateTarget(OpenGL_Window *targetWindow);
		void* GetReference(Abs::AppRef appRef);
		uint GetShaderID(String path) {	return m_targetWindow->GetShaderID(path);	}
		OpenGL_Shader* GetRawShader(String path) {	return m_targetWindow->GetRawShader(path);	}
		inline ApplicationInfo GetAppInfo();

		public:
		OpenGL_Window *m_targetWindow;

		// might not be necessary once actual application is made out for the application based working...
		void initializeGLEnable();
	};

}