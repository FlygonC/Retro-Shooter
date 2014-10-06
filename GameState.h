#pragma once

#include "BaseState.h"
#include "Player.h"
#include "BlueBullet.h"
#include "Enemy.h"



class GameState : public BaseState {
	typedef void(GameState::*EW)(float fTimeStep);
public:
	GameState(void);
	~GameState(void);

	void Initialize();
	void Update(float fTimeStep, StateMachine* pSM);
	void Draw();
	void Destroy();

	void playerFireBullets(float fX, float fY, float fOffset);

	void Wave1(float fTimeStep);

	EW EnemyWave;

private:
	Player* player;
	Enemy* enemies[100];
	int enemyCounter;
	Controler* controls;
	BlueBullet* playerBullets[100];
	int playerBulletCounter;

	int currentWave;
	float waveTime = 0;
	float waveStep = 0;
};