/**
@file main.cpp
*/

/*! \mainpage
*
* Games Programming - Coursework Submission 1 - Game Engine
*/

#include <stdio.h>
#include <tchar.h>
#include <SFML\glew.h>		
#include <SFML\OpenGL.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\wglext.h>
#include <SFML\glext.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include "glm.hpp"

// Imports
#include "scene.h"

const unsigned int WINDOW_WIDTH = 1280;
const unsigned int WINDOW_HEIGHT = 720;
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
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "Games Programming - Coursework Submission 1 - Game Engine", 7U, context);

	// Initialises a clock for the update loop
	sf::Clock clock;
	// Declares var to track elapsed time
	sf::Time elapsedTime;
	
	// Defines scene
	Scene scene = Scene((float)(WINDOW_WIDTH/WINDOW_HEIGHT));
	
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

				// Else
				else
				{
					// Pass key to Scene for processing
					scene.processKeyInput(event.key.code);
				}
			}

			// Resize event : adjust viewport
			if (event.type == sf::Event::Resized)
			{
				glViewport(0, 0, event.size.width, event.size.height);

				for (std::shared_ptr<Camera> camera : scene.getCameras())
				{
					camera->resize(float(event.size.width / event.size.height));
				}
			}
		}

		// Gets elapsed time from clock
		elapsedTime = clock.getElapsedTime();

		// Triggers the update loop REFRESH_RATE times a second
		if (elapsedTime.asMilliseconds() > 1000 / REFRESH_RATE)
		{
			// Restarts the clock
			clock.restart();

			// Updates the Scene with elapsed time
			scene.update(elapsedTime.asSeconds());
		}
		// Clears window making it entirely black
		window.clear(sf::Color(0, 0, 0, 255));

		window.pushGLStates();

		// Draws the Scene
		scene.render();

		window.resetGLStates();
		window.popGLStates();

		// Displays the current frame
		window.display();
	}

	// Finishes 'main' with return
	return 0;
}

