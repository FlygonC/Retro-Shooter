#include "StateMachine.h"

StateMachine::StateMachine(void) {}
StateMachine::~StateMachine(void) {}
/*
The StateMachine handles all the states(all derived from BaseState) of the game, creating, destroying and handling all within a list(stateStack).
StateMachines functions take parameters of pointers to BaseState so that they can handle derivitives of BaseState
*/
//PushState lowers the current active state(derived of BaseState) down and creates the new state(defined in the parameters) on the top of the list(stateStack)
void StateMachine::PushState(BaseState* gameState) {
	stateStack.push_back(gameState);
	gameState->Initialize();
}
//PopState removes the top state from the list and returns for deletion
BaseState* StateMachine::PopState() {
	//lastState is pointing to the derivitive of BaseState that is on the bottom of the list
	BaseState* lastState = stateStack.back();
	stateStack.pop_back();
	lastState->Destroy();
	return lastState;
}
//SwitchState stops the current state, returns it for deletion and starts a new state
BaseState* StateMachine::SwitchState(BaseState* gameState) {
	//lastState is pointing to the derivitive of BaseState that is on the bottom of the list
	BaseState* lastState = stateStack.back();
	lastState->Destroy();

	stateStack.pop_back();
	stateStack.push_back(gameState);
	gameState->Initialize();

	return lastState;
}
//Calls the Update() of the current state(derivitive of BaseState(as all))
void StateMachine::Update(float fTimeStep) {
	stateStack.back()->Update(fTimeStep, this);
}
//Calls the Draw() of the current state
void StateMachine::Draw() {
	stateStack.back()->Draw();
}