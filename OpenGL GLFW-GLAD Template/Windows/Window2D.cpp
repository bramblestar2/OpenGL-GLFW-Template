#include "Window2D.h"
#include <iostream>

Window2D::Window2D(const unsigned int _Width, 
                   const unsigned int _Height, 
                   const std::string _Title,
                   const bool _IsTransparent)
{
    view = nullptr;
    window = nullptr;

    //INITIALIZE GLFW
    if (!glfwInit())
        return;

    setContext(0,0,3,3);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, _IsTransparent);

    window = glfwCreateWindow(_Width, _Height, _Title.c_str(), nullptr, nullptr);

    //Set position of window to the center of screen
    int count;
    GLFWmonitor** monitors = glfwGetMonitors(&count);

    int xpos, ypos, width, height;
    glfwGetMonitorWorkarea(monitors[0], &xpos, &ypos, &width, &height);
    glfwSetWindowPos(window, width / 2 - (_Width / 2), height / 2 - (_Height / 2));

    glfwMakeContextCurrent(window);
}

Window2D::Window2D()
{
    view = nullptr;
    window = nullptr;
}

Window2D::~Window2D()
{
    glfwTerminate();
}

void Window2D::setSize(const unsigned int _Width, const unsigned int _Height)
{
    glfwSetWindowSize(window, _Width, _Height);
}

void Window2D::setTitle(const std::string _Title)
{
    glfwSetWindowTitle(window, _Title.c_str());
}

void Window2D::setPosition(const int _X, const int _Y)
{
    glfwSetWindowPos(window, _X, _Y);
}

void Window2D::move(const int _X, const int _Y)
{
    Vec2i window_pos;
    getPosition(&window_pos.x, &window_pos.y);
    glfwSetWindowPos(window, window_pos.x + _X, window_pos.y + _Y);
}

void Window2D::setIcon(const int _Count, GLFWimage* _Images)
{
    glfwSetWindowIcon(window, _Count, _Images);
}

void Window2D::setAspectRatio(const int _Numer, const int _Denom)
{
    glfwSetWindowAspectRatio(window, _Numer, _Denom);
}

void Window2D::setView(View* _View)
{
    view = _View;
}

void Window2D::setVisibility(const bool _IsVisible)
{
    _IsVisible ? glfwShowWindow(window) : glfwHideWindow(window);
}

void Window2D::setResizable(const bool _IsResizable)
{
    glfwSetWindowAttrib(window, GLFW_RESIZABLE, _IsResizable);
}

void Window2D::setFloating(const bool _IsFloating)
{
    glfwSetWindowAttrib(window, GLFW_FLOATING, _IsFloating);
}

void Window2D::setDecorated(const bool _IsDecorated)
{
    glfwSetWindowAttrib(window, GLFW_DECORATED, _IsDecorated);
}

void Window2D::setSampling(const int _SamplingCount)
{
    glfwSetWindowAttrib(window, GLFW_SAMPLES, _SamplingCount);
}

void Window2D::setContext(const int depthBits, const int stencilBits,
    const int majorVersion, const int minorVersion)
{
    glfwSetWindowAttrib(window, GLFW_DEPTH_BITS, depthBits);
    glfwSetWindowAttrib(window, GLFW_STENCIL_BITS, stencilBits);
    glfwSetWindowAttrib(window, GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
    glfwSetWindowAttrib(window, GLFW_CONTEXT_VERSION_MINOR, minorVersion);
}

void Window2D::getSize(int* _Width, int* _Height)
{
    glfwGetWindowSize(window, _Width, _Height);
}

void Window2D::getPosition(int* _X, int* _Y)
{
    glfwGetWindowPos(window, _X, _Y);
}

GLFWwindow* Window2D::getWindow()
{
    return window;
}

bool Window2D::isVisible()
{
    return glfwGetWindowAttrib(window, GLFW_VISIBLE);
}

bool Window2D::isFocused()
{
    return glfwGetWindowAttrib(window, GLFW_FOCUSED);
}

bool Window2D::isOpen()
{
    return glfwWindowShouldClose(window) == 0 ? true : false;
}

void Window2D::close()
{
    glfwSetWindowShouldClose(window, 1);
}

void Window2D::clear(const float _R, const float _G, const float _B, const float _A)
{
    glClearColor(_R / 255, _G / 255, _B / 255, _A / 255);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window2D::clear()
{
    clear(0,0,0,255);
}

void Window2D::display()
{   
    if (view != nullptr)
        view->update();

    glfwSwapBuffers(window);
}