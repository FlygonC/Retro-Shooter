#pragma once

class StateMachine;
/*
BaseState is the abstract base class for states to be handled by the StateMachine Class
*/
class BaseState {
public:
	BaseState(void) {};
	~BaseState(void) {};

	virtual void Initialize() = 0;
	virtual void Update(float fTimeStep, StateMachine* pSM) = 0;
	virtual void Draw() = 0;
	virtual void Destroy() = 0;
};