#ifndef _STATES_HPP
#define _STATES_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
//#include "PongApplication.hpp"

namespace crp
{	
	// The forward declaration is a result of a circular dependency between
	// the application class and the classes included in this header. 
	class Application;

	class GameState{
	protected:
		const std::string stateName_;
		// The pointer to the application
		//Application * theApp_;
		sf::RenderWindow & window_;

		bool initialized_;
		
		bool paused_;

		bool cleanup_;

		bool deinit_;

	public:

		GameState( std::string stateName, sf::RenderWindow & theWindow );

		virtual ~GameState();

		/**
		* init is responsible for initilizing the state.
		*/
		virtual void init();

		virtual void reinit() = 0;

		virtual void deinit();

		virtual void pause();

		virtual void resume();

		virtual void process_events(sf::Event & event) = 0;

		virtual void process_logic() = 0;

		virtual void render() = 0;

		virtual void cleanup();

		virtual const bool isPaused() const;

		virtual const bool isInit() const;

		virtual const bool isDeinit() const;

		virtual const bool needsCleanup() const;

		virtual const std::string getStateName() const;

	};

	class SplashState : public crp::GameState{
	private:

		sf::Texture * splashLogo_;
		sf::Sprite * logoSprite_;
		sf::Color color_;

		int frameCount_;

	public:
		SplashState( std::string stateName, sf::RenderWindow & theWindow );

		virtual ~SplashState();

		virtual void init();

		virtual void reinit();

		virtual void deinit();

		virtual void pause();

		virtual void resume();

		virtual void process_events(sf::Event & event);

		virtual void process_logic();

		virtual void render();

		virtual void cleanup();

	};

	class StateManager{
	private:
		//Application * theApp_;
		std::vector<GameState*> stateStack;
		std::vector<GameState*> deadStateStack;
	public:
		StateManager();
		~StateManager();

		GameState & getActiveState();

		void addActiveState(GameState * state);

		void deactivateActiveState();

		void removeActiveState();

		const bool isEmpty() const;
	};
}

#endif