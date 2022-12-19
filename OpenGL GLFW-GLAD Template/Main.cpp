#include <iostream>

#include "Windows/Window2D.h"
#include "Windows/Window3D.h"
#include "Events/Events.h"
#include "Essentials/Mouse/Mouse.h"
#include "View/View.h"

void example2D();
void example3D();
void drawCube(const float width, const float length, const float height,
              const float xpos, const float ypos, const float zpos);

int main()
{
    //example2D();

    example3D();

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
    Window3D window(300, 300, "Window");
    glfwSwapInterval(1);

    Events event;
    event.setEventWindow(window.getWindow());

    Camera c1(Vec2f(300,300));
    c1.enableDepth();
    c1.setViewDistance(1, 500);
    c1.setPosition(glm::vec3(-30,0,5));
    window.setCamera(&c1);

    //Mouse movement for camera
    Mouse m;
    
    double mouse_lastx = m.getPosition().x;
    double mouse_lasty = m.getPosition().y;


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
            case EventTypes::MouseButton:
                if (event.event().mouseButton.action == GLFW_PRESS)
                {
                    mouse_lastx = m.getPosition().x;
                    mouse_lasty = m.getPosition().y;
                }
                break;
            }
        }

        if (glfwGetKey(window.getWindow(), GLFW_KEY_W))
            c1.move(Camera_Movement::FORWARD);
        else if (glfwGetKey(window.getWindow(), GLFW_KEY_S))
            c1.move(Camera_Movement::BACKWARD);
        if (glfwGetKey(window.getWindow(), GLFW_KEY_A))
            c1.move(Camera_Movement::LEFT);
        else if (glfwGetKey(window.getWindow(), GLFW_KEY_D))
            c1.move(Camera_Movement::RIGHT);
        if (glfwGetKey(window.getWindow(), GLFW_KEY_SPACE))
            c1.move(Camera_Movement::UP);
        else if (glfwGetKey(window.getWindow(), GLFW_KEY_LEFT_SHIFT))
            c1.move(Camera_Movement::DOWN);

        //Mouse
        if (glfwGetMouseButton(window.getWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
        {
            double mouse_xpos = m.getPosition().x;
            double mouse_ypos = m.getPosition().y;

            float xoffset = mouse_xpos - mouse_lastx;
            float yoffset = mouse_ypos - mouse_lasty;
            mouse_lastx = mouse_xpos;
            mouse_lasty = mouse_ypos;

            float sensitivity = .5;
            xoffset *= sensitivity;
            yoffset *= sensitivity;

            c1.addYaw(xoffset);
            c1.addPitch(-yoffset);

            if (c1.getPitch() > 89.f)
                c1.setPitch(89.f);
            if (c1.getPitch() < -89.f)
                c1.setPitch(-89.f);
        }

        window.clear(0, 0, 0, 0);

        drawCube(10, 10, 10, 0, 0, 0);
        drawCube(10, 10, 20, 11, 0, 0);
        drawCube(10, 10, 30, 22, 0, 0);
        drawCube(10, 10, 40, 33, 0, 0);

        window.display();
    }
}

void drawCube(const float width, const float length, const float height, 
              const float xpos, const float ypos, const float zpos)
{
    GLfloat cube[] =
    {
        //Position                  Color
        //Front           
         xpos,ypos,zpos,              1, 1, 1, 1,
         width+xpos,ypos,zpos,        1, 1, 1, 1,
         width+xpos,height+ypos,zpos, 1, 1, 1, 1,
         xpos,height+ypos,zpos,       1, 1, 1, 1,
        //back            
         xpos,   ypos, zpos+length,              1, 0, 1, 1,
         width+xpos,   ypos, zpos+length,        1, 0, 1, 1,
         width+xpos,  height+ypos, zpos+length,  1, 0, 1, 1,
         xpos,  height+ypos, zpos+length,        1, 0, 1, 1,
        //Left            
         xpos,   ypos,   zpos,                  1, 0, 0, 1,
         xpos,   ypos, length+zpos,             1, 0, 0, 1,
         xpos,  height+ypos, length+zpos,       1, 0, 0, 1,
         xpos,  height+ypos,   zpos,            1, 0, 0, 1,
        //Right           
         width+xpos,   ypos,   zpos,             0, 0, 1, 1,
         width+xpos,   ypos, length+zpos,        0, 0, 1, 1,
         width+xpos,  height+ypos, length+zpos,  0, 0, 1, 1,
         width+xpos,  height+ypos,   zpos,       0, 0, 1, 1,
        //Bottom          
         xpos,   ypos,   zpos,              0, 1, 1, 1,
         xpos,   ypos, length+zpos,         0, 1, 1, 1,
         width+xpos,   ypos, length+zpos,    0, 1, 1, 1,
         width+xpos,   ypos,   zpos,         0, 1, 1, 1,
        //Top             
         xpos,  height+ypos,   zpos,           0, 1, 0, 1,
         xpos,  height+ypos, length+zpos,      0, 1, 0, 1,
         width+xpos,  height+ypos, length+zpos, 0, 1, 0, 1,
         width+xpos,  height+ypos,   zpos,      0, 1, 0, 1,
    };

    // Enable position and color vertex components
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 7 * sizeof(GLfloat), cube);
    glColorPointer(4, GL_FLOAT, 7 * sizeof(GLfloat), cube + 3);

    // Disable normal and texture coordinates vertex components
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);


    glDrawArrays(GL_QUADS, 0, 24);
}