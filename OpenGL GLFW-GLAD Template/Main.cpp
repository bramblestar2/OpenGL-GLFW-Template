#include <iostream>

#include "Windows/Window2D.h"
#include "Windows/Window3D.h"
#include "Events/Events.h"
#include "Essentials/Mouse/Mouse.h"
#include "View/View.h"

void example2D();
void example3D();
void drawCube(const float width, const float length, const float height,
              const float xpos, const float ypos, const float zpos,
              const float r, const float g, const float b, const float a);

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
    Window3D window(600, 500, "Window", true);
    window.setDecorated(false);
    glfwSwapInterval(1);

    Events event;
    event.setEventWindow(window.getWindow());

    int windowWidth, windowHeight;
    window.getSize(&windowWidth, &windowHeight);
    Camera c1(Vec2f(windowWidth, windowHeight));
    c1.enableDepth();
    c1.setViewDistance(1, 500);
    c1.setPosition(glm::vec3(-30,0,5));
    float camSpeed = 1;
    c1.setSpeed(camSpeed);

    window.setCamera(&c1);

    //Mouse movement for camera
    Mouse m;
    
    double mouse_lastx = m.getPosition().x;
    double mouse_lasty = m.getPosition().y;

    double last_frame = glfwGetTime();

    GLfloat light0_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };

    GLfloat light0_position[] = { 0.0, 0.0, 1.0, 0.0 };
    glShadeModel(GL_SMOOTH);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    //glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 45);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);

    while (window.isOpen())
    {
        //Set delta time
        double dt = glfwGetTime() - last_frame;
        last_frame = glfwGetTime();

        c1.setDeltaTime(dt * 100);

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
                    case GLFW_KEY_LEFT_CONTROL:
                        c1.setSpeed(camSpeed * 2);
                        break;
                    case GLFW_KEY_TAB:
                        c1.setSpeed(camSpeed / 2);
                        break;
                    }
                }
                else if (event.event().keys.action == GLFW_RELEASE)
                {
                    switch (event.event().keys.key)
                    {
                    case GLFW_KEY_LEFT_CONTROL:
                        c1.setSpeed(camSpeed);
                        break;
                    case GLFW_KEY_TAB:
                        c1.setSpeed(camSpeed);
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


        for (int x = 0; x < 20; x++)
            for (int z = 0; z < 20; z++)
            {
                drawCube(10, 10, 10, x * 11, sin(glfwGetTime() + (float)(x + z)/ 3) * 10, z * 11,
                         fmod(1 / (float)10 * (x + z), 1) + 0.1, 
                         fmod(1 / (float)10 * (z * x), 1) + 0.1, 
                         fmod(1 / (float)10 * (z), 1) + 0.1, 
                         1);
            }

        //drawCube(10, 10, 10, 0, 0, 0, 1, 1, 1 ,1);
        //drawCube(10, 10, 20, 11, 0, 0, 1, 1, 0 ,1);
        //drawCube(10, 10, 30, 22, 0, 0, 1, 1, .5 ,1);
        //drawCube(10, 10, 40, 33, 0, 0, 1, 0, 1 ,1);
        //drawCube(44, 10, 10, 0, 60, 0, 0, 1, 1 ,1);

        window.display();
    }
}

void drawCube(const float width, const float length, const float height, 
              const float xpos, const float ypos, const float zpos,
              const float r, const float g, const float b, const float a)
{
    GLfloat cube[] =
    {
        //Position                                  Color           Normals
        //Front           
         xpos,ypos,zpos,                            r, g, b, a,     0,0,-1,
         width+xpos,ypos,zpos,                      r, g, b, a,     0,0,-1,
         width+xpos,height+ypos,zpos,               r, g, b, a,     0,0,-1,
         xpos,height+ypos,zpos,                     r, g, b, a,     0,0,-1,
        //Back                                                      
         xpos,   ypos, zpos+length,                 r, g, b, a,     0,0,1,
         width+xpos,   ypos, zpos+length,           r, g, b, a,     0,0,1,
         width+xpos,  height+ypos, zpos+length,     r, g, b, a,     0,0,1,
         xpos,  height+ypos, zpos+length,           r, g, b, a,     0,0,1,
        //Left                                                      
         xpos,   ypos,   zpos,                      r, g, b, a,     -1,0,0,
         xpos,   ypos, length+zpos,                 r, g, b, a,     -1,0,0,
         xpos,  height+ypos, length+zpos,           r, g, b, a,     -1,0,0,
         xpos,  height+ypos,   zpos,                r, g, b, a,     -1,0,0,
        //Right                                                     
         width+xpos,   ypos,   zpos,                r, g, b, a,     1,0,0,
         width+xpos,   ypos, length+zpos,           r, g, b, a,     1,0,0,
         width+xpos,  height+ypos, length+zpos,     r, g, b, a,     1,0,0,
         width+xpos,  height+ypos,   zpos,          r, g, b, a,     1,0,0,
        //Bottom                                                    
         xpos,   ypos,   zpos,                      r, g, b, a,     0,-1,0,
         xpos,   ypos, length+zpos,                 r, g, b, a,     0,-1,0,
         width+xpos,   ypos, length+zpos,           r, g, b, a,     0,-1,0,
         width+xpos,   ypos,   zpos,                r, g, b, a,     0,-1,0,
        //Top                                                       
         xpos,  height+ypos,   zpos,                r, g, b, a,     0,1,0,
         xpos,  height+ypos, length+zpos,           r, g, b, a,     0,1,0,
         width+xpos,  height+ypos, length+zpos,     r, g, b, a,     0,1,0,
         width+xpos,  height+ypos,   zpos,          r, g, b, a,     0,1,0,
    };

    // Enable position and color vertex components
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);

    glVertexPointer(3, GL_FLOAT, 10 * sizeof(GLfloat), cube);
    glColorPointer(4, GL_FLOAT, 10 * sizeof(GLfloat), cube + 3);
    glNormalPointer(GL_FLOAT, 10 * sizeof(GLfloat), cube + 7);

    // Disable normal and texture coordinates vertex components
    //glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);


    glDrawArrays(GL_QUADS, 0, 24);
}