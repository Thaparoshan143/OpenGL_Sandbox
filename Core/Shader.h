#pragma once

#include "../includes/GLM/glm/gtc/matrix_transform.hpp"
#include "../includes/GLM/glm/gtc/type_ptr.hpp"

#include"./Types.h"

namespace Interface
{
	class IShader
	{
		public:
		IShader(String path = "../res/Shaders/") {	m_dirPath = path;	}

		virtual uint CreateProgram() = 0;
		virtual void DeleteProgram() = 0;
		virtual void UseProgram() = 0;
		void SetPath(String path) {	m_dirPath = path;	};
		inline uint GetProgramID() {	return m_programID;	};

		protected:
		String m_dirPath;
		uint m_programID;
	};
}