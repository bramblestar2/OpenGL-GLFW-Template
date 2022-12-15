#include <iostream>

#include "Windows/Window2D.h"
#include "Events/Events.h"


int main()
{
    Window2D window(300, 200, "Window");
    glfwSwapInterval(1);

    Events event;
    event.setEventWindow(window.getWindow());
    while (window.isOpen())
    {
        //EVENTS
        while (event.pollEvents())
        {
            switch (event.type())
            {
            case EventTypes::Key:
                if (event.event().keys.action == GLFW_PRESS)
                {
                    switch (event.event().keys.key)
                    {
                    case GLFW_KEY_ESCAPE:
                        window.close();
                        break;
                    }
                }
                break;
            }
        }

        window.clear();

        window.display();
    }

    return 0;
}