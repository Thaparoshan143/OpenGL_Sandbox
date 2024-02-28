#include"Shader.h"

namespace Sandbox
{
	Shader::Shader()
	{
		// using the default path
		m_dirPath = "../res/Shaders/";
		m_programID = 0;
	}

	Shader::Shader(str dp)
	{
		m_dirPath = dp;
		m_programID = 0;
	}

	uint Shader::CreateProgram(bool preserve)
	{
		if(this->m_programID!=0)
		{
			std::cout << "Program already created!!" << std::endl;
			return this->m_programID;
		}
		m_programID = glCreateProgram();

		uint vs = compileShader(GL_VERTEX_SHADER);
		uint fs = compileShader(GL_FRAGMENT_SHADER);

		glAttachShader(m_programID, vs);
		glAttachShader(m_programID, fs);
		glLinkProgram(m_programID);
		glValidateProgram(m_programID);

		if(!preserve)
		{
			glDeleteShader(vs);
			glDeleteShader(fs);
		}
		
		return m_programID;
	}

	void Shader::UpdatePath(str path)
	{
		this->m_dirPath = path;
	}

	uint Shader::GetProgramID()
	{
		if(m_programID!=0)
		{
			return m_programID;
		}
		else
		return this->CreateProgram();
	}

	void Shader::DeleteProgram()
	{
		glDeleteProgram(m_programID);
	}

	void Shader::UseProgram()
	{
		glUseProgram(this->m_programID);
	}


	uint Shader::compileShader(uint t)
	{
		uint id = glCreateShader(t);
		std::string s = (t==GL_VERTEX_SHADER)?parseShader("ver.shader"):parseShader("frag.shader");
		const char *src = s.c_str();
		glShaderSource(id, 1, &src ,NULL);
		glCompileShader(id);

		int result;
		char infoLog[512];
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);

		if (result == GL_FALSE)
		{
			glGetShaderInfoLog(id, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::" << (t == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << "::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		return id;
	}

	str Shader::parseShader(str sha)
	{
		std::ifstream verSrc(this->m_dirPath+sha);
		std::string line;
		std::stringstream s;
		while(getline(verSrc,line))
		{
			s << line << "\n";
		}
		return s.str();
	}
}