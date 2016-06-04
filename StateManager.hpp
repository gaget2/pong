#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <vector>
#include "States.hpp"

namespace crp
{

	//class Application;
	
	class StateManager{
	private:
		Application * theApp_;
		std::vector<GameState> stateStack;
	public:
		StateManager(Application * theApp);
		~StateManager();

		GameState & getActiveState() const;

		void addActiveState(GameState & state);

		const bool isEmpty() const;
	};
}

#endif