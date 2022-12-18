#include <iostream>

#include "Windows/Window2D.h"
#include "Windows/Window3D.h"
#include "Events/Events.h"
#include "Essentials/Mouse/Mouse.h"
#include "View/View.h"

void example2D();
void example3D();

int main()
{
    example2D();

    //example3D();

    return 0;
}

void example2D()
{
    Window2D window(300, 300, "Window", true);
    window.setDecorated(false);
    glfwSwapInterval(1);

    Events event;
    event.setEventWindow(window.getWindow());

    View v1(Vec2f(300, 300));
    window.setView(&v1);

    Mouse m;

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

        window.clear(10, 10, 10, 0);

        float xpos, ypos;
        xpos = sin(glfwGetTime());
        ypos = cos(glfwGetTime());

        Vec2i pos, size;
        window.getPosition(&pos.x, &pos.y);
        window.getSize(&size.x, &size.y);
        Vec2i windowCenterPos = Vec2i(pos.x + (size.x / 2), pos.y + (size.y / 2));
        window.move((m.getPosition().x - windowCenterPos.x) / 10 + (xpos * (size.x / 20)),
            (m.getPosition().y - windowCenterPos.y) / 10 + (ypos * (size.y / 20)));

        glBegin(GL_QUADS);
        glColor3d(abs(xpos) / 1.f, abs(ypos) / 1.f, abs(xpos + ypos) / 1.f);
        glVertex2f(100 + (xpos * 100), 100 + (ypos * 100));
        glVertex2f(100 + (xpos * 100), 200 + (ypos * 100));
        glVertex2f(200 + (xpos * 100), 200 + (ypos * 100));
        glVertex2f(200 + (xpos * 100), 100 + (ypos * 100));
        glEnd();

        window.display();
    }
}

void example3D()
{
    Window3D window;
}
