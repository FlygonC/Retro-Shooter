#pragma once

#include "BaseState.h"

class MainMenuState : public BaseState {
public:
	MainMenuState(void);
	~MainMenuState(void);

	void Initialize();
	void Update(float fTimeStep, StateMachine* pSM);
	void Draw();
	void Destroy();
private:
	unsigned int MenuScreenBG;
};