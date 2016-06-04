#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "PongApplication.hpp"



namespace crp
{
	class Application;

	class GameState{
	protected:
		const std::string stateName_;
		// The pointer to the application
		Application & theApp_;

		bool paused_;

		bool cleanup_;

	public:

		GameState( std::string stateName, Application & appRef);

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

		virtual const std::string getStateName() const;

	};
}

#endif