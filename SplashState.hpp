#ifndef SPLASHSTATE_HPP
#define SPLASHSTATE_HPP

#include "GameState.hpp"

namespace crp
{
	class Application;
	
	class SplashState : public crp::GameState{
	private:

		const std::string stateName_;

		sf::Texture * splashLogo_;
		sf::Sprite * logoSprite_;
		sf::Color color_;

		int frameCount_;

	public:
		SplashState( std::string stateName, Application & theApp );

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
}

#endif