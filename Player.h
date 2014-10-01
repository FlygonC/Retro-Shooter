#pragma once

#include "Sprite.h"
#include "Controler.h"

class Player : public Sprite {
public:
	Player(void);
	~Player(void);

	void Actions(float DeltaT, Controler* control);
	bool GetFire();

	int gunLevel;
	int speedLevel;
private:
	float speed;
	float fireCoolDown;
	bool fire;
};