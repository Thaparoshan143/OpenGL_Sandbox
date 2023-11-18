#pragma once
// main opengl dependencies
#include"../../includes/GLAD/glad.h"
#include"../../includes/GLFW/glfw3.h"

#include<iostream>
#include<map>

typedef std::string str;
typedef unsigned int uint;

namespace Sandbox
{
    class Window
    {
        public:
        Window();
        // takes arguemnt for the windows like height, width and title to display in it. Note: other two arguement are ignored monitor and share
        Window(int width, int height, str title);

        GLFWwindow *GetWindow();
        
        void SetActive();
        bool ShouldCloseWindow();
        void SetColor(float r, float g, float b, float a);
        void SwapFrameBuffer();
        void WaitForSecond(double sec);
        
        private:
        GLFWwindow *m_window;

        // Helper methods
        void initializeWindow(int w, int h, const char *title);
    };
}