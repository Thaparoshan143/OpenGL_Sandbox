#pragma once

#include<iostream>
#include <string>
#include <fstream>
#include <sstream>

#include"../../includes/GLAD/glad.h"
#include"../../includes/GLFW/glfw3.h"

typedef std::string str;
typedef unsigned int uint;

namespace Sandbox
{
	class Shader
	{
		public:
		Shader();
		Shader(str fp);

		uint CreateProgram(bool preserve=false);
		void UpdatePath(str path);
		uint GetProgramID();
		void DeleteProgram();
		void UseProgram();

		private:
		str m_dirPath;
		uint m_programID;

		uint compileShader(uint t);
		str parseShader(str sha);
	};
}