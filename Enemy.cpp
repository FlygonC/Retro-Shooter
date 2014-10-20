#pragma once

#include "Enemy.h"

Enemy::Enemy(void) {
	width = 40;
	height = 40;
	spriteID = CreateSprite("./images/crate_sideup.png", width, height, true);
	x = 200;
	y = 400;
	type = target;
	hp = 5;

}
Enemy::~Enemy(void) {
	DestroySprite(spriteID);
}

void Enemy::Actions(float fTimestep) {
	if (live) {
		if (hp <= 0) {
			live = false; 
		}
		if (x < -30 || x > 430 || y < -30 || y > 630) {
			live = false;
		}
		x += xSpeed*fTimestep;
		y += ySpeed*fTimestep;

		if (fireCoolDown > 0) {
			fire = false;
			fireCoolDown -= fTimestep;
		}
		if (fireCoolDown <= 0) {
			fire = true;
			fireCoolDown += fireSpeed;
			//y -= 1;
		}
	}
	if (!live) {
		fire = false;
	}
}

void Enemy::Spawn(enemyType stype, float sX, float sY) {
	live = true;
	type = stype;
	x = sX;
	y = sY;
	switch (stype) {
	case target:
	default:
		hp = 15;
		spriteID = CreateSprite("./images/crate_sideup.png", width, height, true);
		x = sX;
		y = sY;
		break;
	case sideFlier:
		hp = 8;
		fireSpeed = 1;
		fireCoolDown = (float)(rand() % 100)/ 100;
		spriteID = CreateSprite("./images/plane2idle.png", width, height, true);
		x = 0;
		y = 0;
		switch (rand() % 2) {
		case 0:
			SetPosition(-20, rand() % 579 + 20);
			xSpeed = 80;
			ySpeed = 0;
			break;
		case 1:
			SetPosition(420, rand() % 579 + 20);
			xSpeed = -80;
			ySpeed = 0;
			break;
		}
		break;
	case bottomChaser:
		hp = 4;
		fireSpeed = 1.2;
		fireCoolDown = (float)(rand() % 100) / 100;
		spriteID = CreateSprite("./images/plane2idle.png", width, height, true);
		SetPosition(rand() % 400, -20);
		xSpeed = 0;
		ySpeed = 90;
		break;
	case topEnemy:
		hp = 6;
		fireSpeed = 2;
		fireCoolDown = (float)(rand() % 100) / 100;
		spriteID = CreateSprite("./images/plane2idle.png", width, height, true);
		SetPosition(rand() % 400, 620);
		xSpeed = 0;
		ySpeed = -80;
		break;
	case sideShooter:
		hp = 6;
		fireSpeed = 1.2;
		fireCoolDown = (float)(rand() % 100) / 100;
		spriteID = CreateSprite("./images/plane2idle.png", width, height, true);
		switch (rand() % 2) {
		case 0:
			SetPosition(-20, rand() % 280);
			xSpeed = 80;
			ySpeed = 80;
			break;
		case 1:
			SetPosition(420, rand() % 280);
			xSpeed = -80;
			ySpeed = 80;
			break;
		}
		break;
	}
}

bool Enemy::GetFire() {
	return fire;
}