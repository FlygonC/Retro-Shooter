#pragma once

#include "Sprite.h"
#include "AIE.h"

class BlueBullet : public Sprite {
public:
	BlueBullet(void);
	~BlueBullet(void);

	void Actions(float DeltaT);

	void setOffset(float fOffset);

	bool live;
private:
	float speed;
	float offset;
};