//#ifndef STATEMANAGER_CPP
//#define STATEMANAGER_CPP

#include "States.hpp"

namespace crp
{
	StateManager::StateManager()
	{}
	StateManager::~StateManager(){
		// Drop all active states
	    while(not stateStack.empty())
	    {
	      // Retrieve the currently active state
	      GameState* state = stateStack.back();
	 
	      // Pop the currently active state off the stack
	      stateStack.pop_back();

	      // Pause the currently active state
	      state->pause();

	      // De-initialize the state
	      state->deinit();

	      // Handle the cleanup before we pop it off the stack
	      state->cleanup();

	      // Just delete the state now
	      delete aState;

	      // Don't keep pointers around we don't need
	      aState = NULL;
	    }

	    // Delete all our dropped states
	    while(not deadStateStack.empty())
	    {
	      // Retrieve the currently active state
	      GameState* state = deadStateStack.back();

	      // Pop the currently active state off the stack
	      deadStateStack.pop_back();

	      // Pause the currently active state
	      state->Pause();

	      // De-initialize the state
	      state->DeInit();

	      // Handle the cleanup before we pop it off the stack
	      state->Cleanup();

	      // Just delete the state now
	      delete state;

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