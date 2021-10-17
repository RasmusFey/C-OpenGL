//
// Created by Rasmus Fey on 03/10/2021.
//

#ifndef UNTITLED_UTILS_H
#define UNTITLED_UTILS_H
#include <GLFW/glfw3.h>
#define nullptr NULL

void error_callback(int error, const char* description);

/**
 * Initiates the state machines and opens a window.
 * @param fullscreen Whether to make the window fullscreen. This makes width and height obsolete.
 * @param width The width of the window.
 * @param height The height of the window.
 * @return The pointer to the created GLFWwindow.
 */
GLFWwindow* setup(bool fullscreen, int width, int height);

std::string readFileIntoString(const std::string& path);

#endif //UNTITLED_UTILS_H
