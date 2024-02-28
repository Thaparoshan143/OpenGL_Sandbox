#include"Window.h"

namespace Sandbox
{
    Window::Window()
    {
        // Making screen of default size
        initializeWindow(500, 500, "Untitled Screen");
    }

    Window::Window(int width, int height, str title)
    {
        initializeWindow(width,height,title.c_str());
    }

    GLFWwindow *Window::GetWindow()
    {
        return m_window;
    }

    void Window::SetActive()
    {
        glfwMakeContextCurrent(m_window);
    }

    bool Window::ShouldCloseWindow()
    {
        return glfwWindowShouldClose(m_window);
    }

    void Window::SetColor(float r, float g, float b, float a)
    {
        glClearColor(r,g,b,a);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::SwapFrameBuffer()
    {
        glfwSwapBuffers(m_window);
    }

    void Window::WaitForSecond(double msec)
    {
        double end = clock() *1000/ CLOCKS_PER_SEC + msec;
        while ((clock() *1000/ CLOCKS_PER_SEC) < end);
    }

    // Helpers
    void Window::initializeWindow(int w, int h, const char *title)
    {
        if(title==nullptr)
            m_window=glfwCreateWindow(w,h,"Untitled Screen",NULL,NULL);
        else if(title!=nullptr)
            m_window=glfwCreateWindow(w,h,title,NULL,NULL);

        if(m_window==nullptr)
        {
            glfwTerminate();
            std::cout << "Failed to create window" << std::endl;
            exit(0);
        }
    }
}