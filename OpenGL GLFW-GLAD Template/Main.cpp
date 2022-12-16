#include <iostream>

#include "Windows/Window2D.h"
#include "Events/Events.h"
#include "Essentials/Mouse/Mouse.h"
#include "View/View.h"

int main()
{
    Window2D window(300, 300, "Window");
    glfwSwapInterval(1);

    Events event;
    event.setEventWindow(window.getWindow());

    View v1(Vec2f(300,300));
    window.setView(&v1);

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

        window.clear(0,0,0,0);

        float xpos, ypos;
        xpos = sin(glfwGetTime());
        ypos = cos(glfwGetTime());

        glBegin(GL_QUADS);
        glColor3d(abs(xpos) / 1.f, abs(ypos) / 1.f, abs(xpos + ypos) / 1.f);
        glVertex2f(100 + (xpos * 100), 100 + (ypos * 100));
        glVertex2f(100 + (xpos * 100), 200 + (ypos * 100));
        glVertex2f(200 + (xpos * 100), 200 + (ypos * 100));
        glVertex2f(200 + (xpos * 100), 100 + (ypos * 100));
        glEnd();

        window.display();
    }

    return 0;
}