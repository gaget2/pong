//#ifndef GAMESTATE_CPP
//#define GAMESTATE_CPP

#include "States.hpp"

namespace crp
{
	GameState::GameState( std::string stateName, sf::RenderWindow * theWindow ) : 
		stateName_(stateName),
		window_(theWindow),
		initialized_(false),
		paused_(false),
		cleanup_(false),
		deinit_(false)

	{

	}

	GameState::~GameState(){
		cleanup();
	}

	void GameState::init(){
		initialized_ = true;
	}

	void GameState::deinit(){
		deinit_ = true;
	}

	void GameState::pause(){
		paused_ = true;
	}

	void GameState::resume(){
		paused_ = false;
	}

	void GameState::process_events(sf::Event & event){
		// Check if user closes the window
		//if( event.type == sf::Event::Closed ) theApp_->application_running_ = false;
	}

	void GameState::cleanup(){
		delete window_;
		window_ = NULL;
	}

	const bool GameState::isPaused() const{
		return paused_;
	}

	const bool GameState::isInit() const{
		return initialized_;
	}

	const bool GameState::isDeinit() const{
		return deinit_;
	}

	const bool GameState::needsCleanup() const{
		return cleanup_;
	}

	const std::string GameState::getStateName() const{
		return stateName_;
	}
}

//#endif