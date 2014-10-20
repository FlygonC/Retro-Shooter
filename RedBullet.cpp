#pragma once

#include "RedBullet.h"

RedBullet::RedBullet(void) {
	width = 6;
	height = 6;
	spriteID = CreateSprite("./images/redBullet.png", width, height, true);
	x = 0;
	y = 0;
};
RedBullet::~RedBullet(void) {
	DestroySprite(spriteID);
};

void RedBullet::Actions(float fTimestep) {
	if (live == true) {
		x += xSpeed*fTimestep;
		y += ySpeed*fTimestep;
		if (x < 0 || x > 400 || y < 0 || y > 600) {
			live = false;
		}
	}
};

void RedBullet::SetXSpeed(float sSpeed) {
	xSpeed = sSpeed;
}
void RedBullet::SetYSpeed(float sSpeed) {
	ySpeed = sSpeed;
}