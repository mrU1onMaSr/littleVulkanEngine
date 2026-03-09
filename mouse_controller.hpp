#pragma once

#include "lve_game_object.hpp"
#include <GLFW/glfw3.h>


namespace lve {
    class MouseController{
        public:

        void rotateCamWithMouse(GLFWwindow *window, float dt, LveGameObject& gameObject);

        float mouseSensivity = 0.007f;
        
    };
}