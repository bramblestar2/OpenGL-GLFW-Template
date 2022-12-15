#include <iostream>

//https://www.glfw.org/docs/3.0/window.html#:~:text=Window%20related%20hints%20The%20GLFW_RESIZABLE%20hint%20specifies%20whether,will%20still%20be%20resizable%20using%20the%20glfwSetWindowSize%20function.
#include "Window2D.h"
#include "Events.h"


int main()
{
    Window2D window(300, 200, "Something");

    Events event;
    event.setEventWindow(window.getWindow());
    while (window.isOpen())
    {
        glfwPollEvents();
        while (event.pollEvents())
        {
            switch (event.getEvent().type)
            {
            case EventTypes::CursorMoved:
                double xpos = event.getEvent().event.cursorMoved.xpos;
                double ypos = event.getEvent().event.cursorMoved.ypos;
                std::cout << xpos << " - " << ypos << std::endl;
                break;
            }
        }

        window.clear(20, 20, 20, 255);

        window.display();
    }

    return 0;
}