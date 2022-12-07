#include <iostream>
#include "Window.h"

//https://www.glfw.org/docs/3.0/window.html#:~:text=Window%20related%20hints%20The%20GLFW_RESIZABLE%20hint%20specifies%20whether,will%20still%20be%20resizable%20using%20the%20glfwSetWindowSize%20function.

int main()
{
    Window window(300,300);

    window.run();

    return 0;
}