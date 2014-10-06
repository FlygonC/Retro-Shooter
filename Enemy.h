#pragma once

#include "Sprite.h"

enum enemyType {target};

class Enemy : public Sprite {
public:
	Enemy();
	~Enemy();

	void Actions(float fTimeStep);
	void Spawn(enemyType type, float sX, float sY);

	bool live = true;
	float hp;
protected:
	enemyType type;
	float fireSpeed;
	float fireCoolDown;
	bool fire;
};