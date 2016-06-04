#ifndef PONGAPPLICATION_HPP
#define PONGAPPLICATION_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "CRconstants.hpp"
#include "States.hpp"

// The namespace bounding the pong application code dependencies
// crp => Code Red Pong
namespace crp
{
	class Application{

	private:

		/* Application constants */

		// Window properties
		const int WINDOW_WIDTH_ = 400;
		const int WINDOW_HEIGHT_ = 300;

		// Application FPS
		const int FPS_ = 60;

		StateManager stateManager_;

		// The exit code that shall be returned after the applicated is finished
		int application_exit_code_;

		// Flag to determine if the application is running, duh!
		bool application_running_;

		// SFML Window object that will be rendered to
		sf::RenderWindow * window_;

		// SFML Event object used to handle events
		sf::Event event_;

		/* Private application functions */

		void gameLoop();

		void init();

		void cleanup();

	public:
		
		Application();
		virtual ~Application();

		// Begins main application logic
		int run();

		sf::RenderWindow * getWindow() const;

		//friend class GameState;
		//friend class SplashState;
	};
}
#endif