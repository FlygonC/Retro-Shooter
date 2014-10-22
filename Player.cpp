#pragma once

#include "Player.h"
#include "AIE.h"
#include "Sprite.h"
#include "Controler.h"

Player::Player(void) {
	width = 40;
	height = 40;
	spriteID = CreateSprite("./images/plane1idle.png", width, height, true);
	x = 200;
	y = 300;

	speed = 200;
	fireCoolDown = 0;
	fire = false;
}
Player::~Player(void) {
	DestroySprite(spriteID);
}

void Player::Actions(float DeltaT, Controler* control) {
	if (control->UP == true) {
		y += speed*DeltaT;
	}
	if (control->DOWN == true) {
		y -= speed*DeltaT;
	}
	if (control->RIGHT == true) {
		x += speed*DeltaT;
	}
	if (control->LEFT == true) {
		x -= speed*DeltaT;
	}

	if (y >= 600 - 20) {
		y = 600 - 20;
	}
	if (y <= 0 + 20) {
		y = 0 + 20;
	}
	if (x >= 400 - 20) {
		x = 400 - 20;
	}
	if (x <= 0 + 20) {
		x = 0 + 20;
	}

	if (fireCoolDown > 0) {
		fire = false;
		fireCoolDown -= DeltaT;
	}
	if (control->FIRE == true && fireCoolDown <= 0) {
		fire = true;
		fireCoolDown += 0.07f;
		//y -= 1;
	}
}

bool Player::GetFire() {
	return fire;
}