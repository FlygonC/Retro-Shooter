#pragma once

#include "Sprite.h"
#include "AIE.h"
#include "Sprite.h"
//#include "GameState.h"
#include <cstdlib>

enum enemyType {target,sideFlier,bottomChaser,topEnemy,sideShooter};

class Enemy : public Sprite {
public:
	Enemy(void);
	~Enemy(void);

	void Actions(float fTimeStep);
	void Spawn(enemyType stype, float sX, float sY);

	bool GetFire();
	bool live = false;
	float hp;
	enemyType type;
protected:
	float xSpeed;
	float ySpeed;
	float fireSpeed;
	float fireCoolDown;
	bool fire;
};