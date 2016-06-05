//#ifndef PONGAPPLICATION_CPP
//#define PONGAPPLICATION_CPP

#include "PongApplication.hpp"

namespace crp
{
	/* Application constructor implementations */

	Application::Application(){

	}

	Application::~Application(){}

	/* Private member function implementations */
	void Application::gameLoop(){
		std::cout << "Begin Application::gameLoop()"<< std::endl;
		while( not stateManager_.isEmpty() ){
			// get active state
			GameState & state = stateManager_.getActiveState();

			std::cout << "Application::gameLoop() - calling state.init()"<< std::endl;
			// init state if needed
			state.init();

			std::cout << "Application::gameLoop() - window->pollEvent"<< std::endl;
			// run state
			window_->pollEvent(event_);

			std::cout << "Application::gameLoop() - state.process_events()"<< std::endl;
			state.process_events(event_);

			std::cout << "Application::gameLoop() - state.process_logic()"<< std::endl;
			state.process_logic();

			std::cout << "Application::gameLoop() - state.render()"<< std::endl;
			state.render();

			// cleanup state if needed
			if( state.isDeinit() )
				stateManager_.removeActiveState();
			else if( state.isPaused() )
				stateManager_.deactivateActiveState();

			window_->setFramerateLimit(60);
		}
	}

	void Application::init(){
		std::cout << "Begin Application::init()" << std::endl;

		std::cout << "Application::init() - creating window_"<< std::endl;

		// Create window
		window_ = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH_, WINDOW_HEIGHT_), "Pong");

		std::cout << "Application::init() - creating initial splash state" << std::endl;
		// Create initial splash state
		SplashState * initState = new SplashState("SplashState", *window_);

		// Add this initial state
		stateManager_.addActiveState(initState);

		// Internal cleanup
		//delete initState;
		//initState = NULL;
	}

	void Application::cleanup(){
		// Delete window
		delete window_;
		window_ = NULL;

	}

	/* Public member function implementations */

	int Application::run(){
		std::cout << "Begin Application::run()" << std::endl;

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

	sf::RenderWindow * Application::getWindow() const{
		return window_;
	}
}

//#endif