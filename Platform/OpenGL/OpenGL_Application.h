#pragma once

#include"../../Core/Application.h"

#include"./OpenGL_Window.h"

namespace OpenGL
{
	class OpenGL_Application : public Interface::IApplication
	{
		public:
		OpenGL_Application(ApplicationInfo &appInfo);
		~OpenGL_Application();

		void SetWindow(OpenGL_Window *targetWin);
		uint GetShaderID(String path);
		OpenGL_Shader* GetRawShader(String path);

		std::map<String, OpenGL_Shader> m_shaderList;
		// might not be necessary once actual application is made out for the application based working...
		void initializeGLEnable();
	};

}