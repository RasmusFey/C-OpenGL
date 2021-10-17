//
// Created by Rasmus Fey on 03/10/2021.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fcntl.h>
#include <fstream>
#include "utils.h"

#define nullptr NULL

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::ostringstream;


void error_callback(int error, const char* description) {
    fprintf(stderr, "Error Code: %i\nError: %s\n", error, description);
}


/**
 * Initiates the state machines and opens a window.
 * @param fullscreen Whether to make the window fullscreen. This makes width and height obsolete.
 * @param width The width of the window.
 * @param height The height of the window.
 * @return The pointer to the created GLFWwindow.
 */
GLFWwindow* setup(bool fullscreen, int width, int height) {
    glfwSetErrorCallback(error_callback);

    if(!glfwInit()) {
        std::cout << "Something went horribly wrong and we were unable to initialize GLFW." << std::endl;
        return nullptr;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow* window;
    if(fullscreen) {
        const GLFWvidmode mode = *glfwGetVideoMode(glfwGetPrimaryMonitor());
         window = glfwCreateWindow(mode.width, mode.height,"test", glfwGetPrimaryMonitor(), nullptr);
    } else {
        window = glfwCreateWindow(width, height, "test", nullptr, nullptr);
    }

    if(!window) {
        std::cout << "Something went wrong creating the window." << std::endl;
        return nullptr;
    }

    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK) {
        return nullptr;
    }

    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    glfwSwapInterval(1); // "vsync"

    return window;
}

string readFileIntoString(const string& path) {
    ifstream input_file(path);

    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
        << path << "'" << endl;
        exit(EXIT_FAILURE);
    }

    string out = {(std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>()};
    #ifdef VERBOSE
    cout << out << endl;
    #endif
    return out;
}
