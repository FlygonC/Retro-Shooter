#pragma once

#include "Enemy.h"
#include "AIE.h"
#include "Sprite.h"

Enemy::Enemy() {
	width = 40;
	height = 40;
	spriteID = CreateSprite("./images/crate_sideup.png", width, height, true);
	x = 200;
	y = 400;
	type = target;
	hp = 5;

}
Enemy::~Enemy() {}

void Enemy::Actions(float fTimestep) {
	if (hp <= 0) {
		live = false;
	}
	if (live) {

	}
	if (!live) {

	}
}

//void Enemy::Spawn() {

//}