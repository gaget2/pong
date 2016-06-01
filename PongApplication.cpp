#ifndef _PONGAPPLICATION_CPP
#define _PONGAPPLICATION_CPP

#include "PongApplication.hpp"

namespace crp
{
	/* Application constructor implementations */

	Application::Application(){}

	Application::~Application(){}

	/* Private member function implementations */
	void Application::gameLoop(){

		while( application_running_ ){
			process_events();

			process_logic();

			render();
		}
	}

	void Application::process_events(){

		// Dequeue events from SFML event queue
		while( window_->pollEvent(event_) ){

			// Check if user closes the window
			if( event_.type == sf::Event::Closed ) application_running_ = false;
		}

	}

	void Application::process_logic(){

	}

	void Application::render(){

	}

	void Application::init(){

		// Create window
		window_ = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH_, WINDOW_HEIGHT_), "Pong");
	}

	void Application::cleanup(){
		// Delete window
		delete window_;
		window_ = NULL;
	}

	/* Public member function implementations */

	int Application::run(){

		// Application is running
		application_running_ = true;

		// Initialize
		init();

		// Begin game loop
		gameLoop();

		// Cleanup application
		cleanup();

		application_running_ = false;

		return crp::STATUS_NO_ERROR;
	}

	const bool Application::isRunning() const{
		return application_running_;
	}
}

#endif