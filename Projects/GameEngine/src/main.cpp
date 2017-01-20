/**
@file main.cpp
*/

/*! \mainpage
*
* Games Programming - Coursework Submission 1 - Game Engine
*/

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

// Imports
#include "stdafx.h"
#include "scene.h"
// SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

//!< Entry point for the application
int main()
{
	// Instantiates window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Games Programming - Coursework Submission 1 - Game Engine", sf::Style::Default);

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
			}

			// Resize event : adjust viewport
			if (event.type == sf::Event::Resized)
			{
				gl::Viewport(0, 0, event.size.width, event.size.height);

				for (std::shared_ptr<Camera> camera : scene.getCameras())
				{
					camera->resize(float(event.size.width/event.size.height))
				}
			}
		}

		// Gets elapsed time from clock
		elapsedTime = clock.getElapsedTime();

		// Triggers the update loop 128 times a second
		if (elapsedTime.asMilliseconds() > 1000 / 128)
		{
			// Restarts the clock
			clock.restart();

			// Updates the Scene with elapsed time
			scene.update(elapsedTime.asSeconds());
		}

		// Clears window making it entirely black
		window.clear(sf::Color(0, 0, 0, 255));

		// Draws the Scene
		scene.render();

		// Displays the current frame
		window.display();
	}

	// Finishes 'main' with return
	return 0;
}

