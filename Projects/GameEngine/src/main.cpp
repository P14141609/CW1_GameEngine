/**
@file main.cpp
*/

/*! \mainpage
*
* Games Programming - Coursework Submission 1 - Game Engine
*/

// Imports
#include "scene.h"
#include <iostream>
// OpenGL
#include "gl_core_4_3.hpp"
#include <GLFW/glfw3.h>

// Global Variables
GLFWwindow *g_window; // Declares GLFWwindow for display

//!< Called upon key event
static void onKeyEvent(GLFWwindow* window, int key, int cancode, int action, int mods)
{
	// If Spacebar released
	if (key == GLFW_KEY_SPACE && action == GLFW_RELEASE)
		return; // TEMPORARY EXAMPLE OF USAGE
}

//!< Entry point for the application
int main()
{
	// Initialises GLFW - Quits if fail
	if (!glfwInit()) exit(EXIT_FAILURE);

	// Setup for OpenGL 4.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, FALSE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, TRUE);

	// Creates a display window
	g_window = glfwCreateWindow(1280, 720, std::string("Games Programming - Coursework Submission 1 - Game Engine").c_str(), NULL, NULL);
	
	// If window does not exist
	if (!g_window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(g_window);
	
	// Key handling
	glfwSetKeyCallback(g_window, onKeyEvent);
	
	// Defines scene
	Scene scene = Scene();

	// Main loop
	while (!glfwWindowShouldClose(g_window) && !glfwGetKey(g_window, GLFW_KEY_ESCAPE)) 
	{
		// Update
		scene.update((float)glfwGetTime());
		
		// Render
		scene.render();

		// GLFW processes
		glfwSwapBuffers(g_window);
		glfwPollEvents();
	}
	
	// Close window and terminate GLFW
	glfwTerminate();

	// Finishes 'main' with return
    return 0;
}

