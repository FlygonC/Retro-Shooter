#pragma once

#include "BaseState.h"
#include "Player.h"
#include "BlueBullet.h"

class GameState : public BaseState {
public:
	GameState(void);
	~GameState(void);

	void Initialize();
	void Update(float fTimeStep, StateMachine* pSM);
	void Draw();
	void Destroy();
private:
	Player* player;
	Controler* controls;
	BlueBullet* playerBullets[100];
	int playerBulletCounter;
};