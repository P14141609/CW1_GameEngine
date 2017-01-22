/**
@file main.cpp
*/

/*! \mainpage
*
* Games Programming - Coursework Submission 1 - Game Engine
*/

#define GL_GLEXT_PROTOTYPES 1		
#define GLEW_STATIC
#include <SFML\glew.h>		
#include <SFML\OpenGL.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\wglext.h>
#include <SFML\glext.h>

#include <vector>
#include "glm.hpp"

// Imports
#include "scene.h"

const unsigned int WINDOW_WIDTH = 1280;
const unsigned int WINDOW_HEIGHT = 720;
const float ASPECT_RATIO = WINDOW_WIDTH / WINDOW_HEIGHT;
const unsigned int REFRESH_RATE = 128;

//!< Entry point for the application
int main()
{
	int depthBits = 24;
	int stencilBits = 8;
	int antiAliasingLevel = 8;
	int majorVersion = 4;
	int minorVersion = 5;

	// Creates the main window
	sf::ContextSettings context(depthBits, stencilBits, antiAliasingLevel, majorVersion, minorVersion);
	// Instantiates window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32U), "Games Programming - Coursework Submission 1 - Game Engine", 7U, context);

	// Checks the window settings
	sf::ContextSettings windowSettings = window.getSettings();

	// Sets up OpenGL after the window is configured
	// Set color and depth clear value
	glClearDepth(1.0f);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
	// Enable Z-buffer read and write
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDepthMask(GL_TRUE);
	
	// Draw single sided faces
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	
	// Setup a perspective projection
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	
	// Defines scene
	Scene scene = Scene(ASPECT_RATIO);
	
	// Sets the viewport width and height to reflect the size of the display
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	// Initialises a clock for the update loop
	sf::Clock clock;
	// Declares var to track elapsed time
	sf::Time elapsedTime;

	// Set the active window before using OpenGL commands
	// It's useless here because active window is always the same,
	// but don't forget it if you use multiple windows or controls
	window.setActive();
	bool g_bWindowActive = true;

	// While the window is open
	while (window.isOpen())
	{
		// Event object for windows event calls
		sf::Event event;
		// Process events
		while (window.pollEvent(event))
		{
			// If Closed event is called
			if (event.type == sf::Event::Closed)
			{
				// Closes window
				window.close();
			}
	
			// If KeyPressed event is called
			if (event.type == sf::Event::KeyPressed)
			{
				// If Esc is pressed
				if (event.key.code == sf::Keyboard::Escape)
				{
					// Closes window
					window.close();
				}
			}
	
			// Resize event : adjust viewport
			if (event.type == sf::Event::Resized)
			{
				// Updates the viewport to reflect the size of the display
				glViewport(0, 0, event.size.width, event.size.height);
	
				for (std::shared_ptr<Camera> pCamera : scene.getCameras())
				{
					// Updates the aspect ratio of every Camera in the Scene
					pCamera->setAspectRatio(float(event.size.width / event.size.height));
				}
			}

			// Focus event
			if (event.type == sf::Event::GainedFocus) g_bWindowActive = true;
			if (event.type == sf::Event::LostFocus)	  g_bWindowActive = false;
		}
	
		// Gets elapsed time from clock
		elapsedTime = clock.getElapsedTime();
	
		// Triggers the update loop REFRESH_RATE times a second
		if (elapsedTime.asMilliseconds() > 1000 / REFRESH_RATE)
		{
			// Restarts the clock
			clock.restart();
	
			// If Window is active
			if (g_bWindowActive)
			{
				// Updates the Scene with elapsed time
				scene.update(elapsedTime.asSeconds());
			}
		}
		
		// Clears window making it entirely black
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
		// Apply some transformations
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		// Draws the Scene
		scene.render();

		window.pushGLStates();
		//SFML STUFF HERE
		window.resetGLStates();
		window.popGLStates();
	
		// Displays the current frame
		window.display();
	}

	// Finishes 'main' with return
	return 0;
}

