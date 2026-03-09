#include "mouse_controller.hpp"
#include <GLFW/glfw3.h>

namespace lve {
    void MouseController::rotateCamWithMouse(GLFWwindow *window, float dt, LveGameObject &gameObject){
         
        static double lastX = 0.0;
        static double lastY = 0.0;
        
        double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);

        float dx = static_cast<float>(xPos - lastX);
        float dy = static_cast<float>(yPos - lastY);

        lastX = xPos;
        lastY = yPos;

        gameObject.transform.rotation.x -= mouseSensivity * dy;
        gameObject.transform.rotation.y += mouseSensivity * dx;
        
    }
}