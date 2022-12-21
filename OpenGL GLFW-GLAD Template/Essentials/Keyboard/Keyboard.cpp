#include "Keyboard.h"

Keyboard::Keyboard()
{
}

bool Keyboard::isKeyPressed(int _Key)
{
    GLFWwindow* currentContext = glfwGetCurrentContext();
    return glfwGetKey(currentContext, _Key);
}

std::string Keyboard::getKeyName(int _Key, int _Scancode)
{
    return glfwGetKeyName(_Key, _Scancode);
}

int Keyboard::getScancode(int _Key)
{
    return glfwGetKeyScancode(_Key);
}
