#pragma once

#include "Sprite.h"

class BlueBullet : public Sprite {
public:
	BlueBullet(void);
	~BlueBullet(void);

	void Actions(float DeltaT);

	bool live;
private:
	float speed;
	float offset;
};