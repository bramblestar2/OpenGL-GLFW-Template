#include <iostream>

#include "Windows/Window2D.h"
#include "Events/Events.h"
#include "Essentials/Mouse/Mouse.h"

int main()
{
    Window2D window(300, 300, "Window", true);
    window.setDecorated(false);
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
        
        window.clear(0,0,0, 0);

        float xpos, ypos;
        xpos = sin(glfwGetTime());
        ypos = cos(glfwGetTime());
        glBegin(GL_QUADS);
        glColor3d(abs(xpos) / 1.f, abs(ypos) / 1.f, abs(xpos + ypos) / 1.f);
        glVertex2d(-0.5 + xpos,  0.5 + ypos);
        glVertex2d( 0.5 + xpos,  0.5 + ypos);
        glVertex2d( 0.5 + xpos, -0.5 + ypos);
        glVertex2d(-0.5 + xpos, -0.5 + ypos);
        glEnd();

        window.display();
    }

    return 0;
}