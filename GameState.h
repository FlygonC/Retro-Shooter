#pragma once

#include "BaseState.h"
#include "Player.h"
#include "BlueBullet.h"
#include "RedBullet.h"
#include "Enemy.h"
#include "AIE.h"
#include "StateMachine.h"
#include "Sprite.h"
#include "Player.h"
#include "Controler.h"
#include <cstdlib>
#include "GameEndState.h"

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
	void enemyFireBullets(float fX, float fY, float fXSpeed, float fYSpeed);

	void Wave0(float fTimeStep);
	void Wave1(float fTimeStep);
	void Wave2(float fTimeStep);
	void Wave3(float fTimeStep);
	void Wave4(float fTimeStep);

	EW EnemyWave;

private:
	Player* player;
	int maxEnemies = 100;
	Enemy* enemies[100];
	int enemyCounter;
	Controler* controls;
	int maxPlayerBullets = 100;
	BlueBullet* playerBullets[100];
	int playerBulletCounter;
	int maxEnemyBullets = 200;
	RedBullet* enemyBullets[200];
	int enemyBulletCounter;

	int lives;

	int currentWave;
	float waveTime = 0;
	float waveStep = 0;
};