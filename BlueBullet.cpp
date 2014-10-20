#pragma once

#include "BlueBullet.h"

BlueBullet::BlueBullet(void) {
	width = 4;
	height = 8;
	spriteID = CreateSprite("./images/bluebullet.png", width, height, true);
	x = 0;
	y = 0;

	speed = 800;
	offset = 0;
	live = false;
}
BlueBullet::~BlueBullet(void) {
	DestroySprite(spriteID);
}

void BlueBullet::Actions(float DeltaT) {
	if (live == true) {
		y += speed*DeltaT;
		x += offset*DeltaT;
		if (x < 0 || x > 400 || y < 0 || y > 600) {
			live = false;
		}
	}
}

void BlueBullet::setOffset(float fOffset) {
	offset = fOffset;
}