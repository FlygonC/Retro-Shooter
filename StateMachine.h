#pragma once

#include "BaseState.h"
#include <list>
/*
The StateMachine handles all the states(all derived from BaseState) of the game, creating, destroying and handling all within a list(stateStack).
StateMachines functions take parameters of pointers to BaseState so that they can handle derivitives of BaseState
See StateMachine.cpp
*/
class StateMachine {
public:
	StateMachine(void);
	~StateMachine(void);

	void PushState(BaseState* gameState);
	BaseState* PopState();
	BaseState* SwitchState(BaseState* gameState);

	void Update(float fTimeStep);
	void Draw();
private:
	std::list<BaseState*> stateStack;
};