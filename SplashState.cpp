//#ifndef SPLASHSTATE_CPP
//#define SPLASHSTATE_CPP

#include "States.hpp"

namespace crp
{
	SplashState::SplashState( std::string stateName, sf::RenderWindow & theWindow ) :
		crp::GameState(stateName, theWindow),
		frameCount_(0)
	{
	}

	SplashState::~SplashState(){
		std::cout << "Begin SplashState::~SplashState()" << std::endl;
		//cleanup();
	}

	void SplashState::init(){
		std::cout << "Begin SplashState::init()"<< std::endl;
		if( not initialized_ ){
			initialized_ = true;

			std::cout << "SplashState()::init() - creating objects"<< std::endl;
			// Create SFML objects required to display the splash screen
			splashLogo_ = new sf::Texture();
			logoSprite_ = new sf::Sprite();

			color_ = logoSprite_->getColor();
			splashLogo_->loadFromFile("Assets/logo.png");
			logoSprite_->setTexture(*splashLogo_);
			logoSprite_->setPosition(0, 0);
		}
	}

	void SplashState::reinit(){}

	void SplashState::deinit(){
		deinit_ = true;
	}

	void SplashState::pause(){
		paused_ = true;
	}

	void SplashState::resume(){}

	void SplashState::process_events(sf::Event & event){
		// Check if user closes the window
		if( event.type == sf::Event::Closed ){
			deinit();
			pause();
		}
	}

	void SplashState::process_logic(){
		//At 60 frames per second with a 5 second splash screen, we have 300 frames
		//uses equation alpha = -1/90 * (x - 150)^2 + 255
		color_.a = (-1 * (frameCount_ - 150) * (frameCount_ - 150) / 90) + 255;
		++frameCount_;

		if( frameCount_ > 300 ){
			deinit();
			pause();
		}
	}

	void SplashState::render(){
		window_.clear(sf::Color::Black);
		logoSprite_->setColor(color_);
		window_.draw(*logoSprite_);
		window_.display();
	}

	void SplashState::cleanup(){
		std::cout << "Begin SplashState::cleanup()" << std::endl;
		delete splashLogo_;
		delete logoSprite_;
		splashLogo_ = NULL;
		logoSprite_ = NULL;
	}
}

//#endif