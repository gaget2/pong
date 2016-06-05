//#ifndef STATEMANAGER_CPP
//#define STATEMANAGER_CPP

#include "States.hpp"

namespace crp
{
	StateManager::StateManager()
	{}
	StateManager::~StateManager(){
		std::cout << "Begin StateManager::~StateManager()"<< std::endl;
		// Drop all active states
	    while(not stateStack.empty())
	    {
	    	std::cout << "StateManager::~StateManager() - GameState* state = stateStack.back(); " << std::endl;
			// Retrieve the currently active state
			GameState* state = stateStack.back();

			std::cout << "StateManager::~StateManager() - stateStack.pop_back();" << std::endl;
			// Pop the currently active state off the stack
			stateStack.pop_back();

			std::cout << "StateManager::~StateManager() - state->pause();" << std::endl;
			// Pause the currently active state
			state->pause();

			std::cout << "StateManager::~StateManager() - state->deinit();" << std::endl;
			// De-initialize the state
			state->deinit();

			std::cout << "StateManager::~StateManager() - state->cleanup();" << std::endl;
			// Handle the cleanup before we pop it off the stack
			state->cleanup();

			std::cout << "StateManager::~StateManager() - delete state;" << std::endl;
			// Just delete the state now
			delete state;

			std::cout << "StateManager::~StateManager() - state = NULL;" << std::endl;
			// Don't keep pointers around we don't need
			state = NULL;
	    }

	    // Delete all our dropped states
	    while(not deadStateStack.empty())
	    {
	    	std::cout << "StateManager::~StateManager() - GameState* state = deadStateStack.back();" << std::endl;
			// Retrieve the currently active state
			GameState* state = deadStateStack.back();

			std::cout << "StateManager::~StateManager() - deadStateStack.pop_back();" << std::endl;
			// Pop the currently active state off the stack
			deadStateStack.pop_back();

			std::cout << "StateManager::~StateManager() - state->pause();" << std::endl;
			// Pause the currently active state
			state->pause();

			std::cout << "StateManager::~StateManager() - state->deinit();" << std::endl;
			// De-initialize the state
			state->deinit();

			std::cout << "StateManager::~StateManager() - state->cleanup();" << std::endl;
			// Handle the cleanup before we pop it off the stack
			state->cleanup();

			std::cout << "StateManager::~StateManager() - delete state;" << std::endl;
			// Just delete the state now
			delete state;

			std::cout << "StateManager::~StateManager() - state = NULL;" << std::endl;
			// Don't keep pointers around we don't need
			state = NULL;
	    }
	}

	crp::GameState& StateManager::getActiveState() {
		std::cout << "Begin StateManager::getActiveState()" << std::endl;
		return *stateStack.back();
	}

	void StateManager::addActiveState(GameState * state){
		std::cout << "Begin StateManager::addActiveState()" << std::endl;
		if( not stateStack.empty() )
			stateStack.back()->pause();

		stateStack.push_back(state);

		stateStack.back()->init();
	}

	void StateManager::deactivateActiveState(){
		std::cout << "Begin StateManager::deactivateActiveState()"<< std::endl;
		if( not stateStack.empty() ){
			// Get the current active state
			GameState * state = stateStack.back();

			// Pause this state
			state->pause();

			// Remove this state from the active position
			stateStack.pop_back();

			// And put it in the inactive state position
			stateStack.insert(stateStack.begin(), state);

			state = NULL;
		}
	}

	void StateManager::removeActiveState(){
		std::cout << "Begin StateManager::removeActiveState()"<< std::endl;
		if( not stateStack.empty() ){
			GameState * state = stateStack.back();

			state->pause();

			state->deinit();

			stateStack.pop_back();

			deadStateStack.push_back(state);

			state = NULL;
		}
	}

	const bool StateManager::isEmpty() const{
		return stateStack.empty();
	}
}

//#endif