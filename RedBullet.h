#pragma once

#include "Sprite.h"
#include "AIE.h"

class RedBullet : public Sprite {
public:
	RedBullet(void);
	~RedBullet(void);

	void Actions(float fTimestep);

	void SetXSpeed(float sSpeed);
	void SetYSpeed(float sSpeed);

	bool live = false;
protected:
	float xSpeed;
	float ySpeed;
};