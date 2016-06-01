#ifndef _PONGAPPLICATION_HPP
#define _PONGAPPLICATION_HPP

#include <SFML/Graphics.hpp>
#include "Core/CRconstants.hpp"

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

		/* Application variables and objects */

		// Flag to determine if the application is running, duh!
		bool application_running_;

		// The exit code that shall be returned after the applicated is finished
		int application_exit_code_;

		// SFML Window object that will be rendered to
		sf::RenderWindow * window_;

		// SFML Event object used to handle events
		sf::Event event_;

		/* Private application functions */

		void gameLoop();

		void process_events();

		void process_logic();

		void render();

		void init();

		void cleanup();

	public:

		Application();
		virtual ~Application();

		// Begins main application logic
		int run();

		// Is the application running?
		const bool isRunning() const;
	};
}
#endif