#pragma once

#include "BaseState.h"
#include "AIE.h"
#include "GameState.h"
#include <cstdlib>

class GameEndState : public BaseState {
public:
	GameEndState(void);
	~GameEndState(void);

	void Initialize();
	void Update(float fTimeStep, StateMachine* pSM);
	void Draw();
	void Destroy();
};