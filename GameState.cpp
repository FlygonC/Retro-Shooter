#pragma once

#include "GameState.h"
#include "AIE.h"
#include "BaseState.h"
#include "StateMachine.h"
#include "Sprite.h"
#include "Player.h"
#include "Controler.h"

GameState::GameState(void) {}
GameState::~GameState(void) {}

void GameState::Initialize() {
	player = new Player();

	for (int i = 0; i <= 99; i++) {
		playerBullets[i] = new BlueBullet();
	}
	playerBulletCounter = 0;

	controls = new Controler();
	controls->setKeys(265, 264, 263, 262, 32);
}
void GameState::Update(float fTimeStep, StateMachine* pSM) {
	controls->updateControler();

	player->Actions(fTimeStep, controls);
	MoveSprite(player->GetSpriteID(), player->GetX(), player->GetY());

	if (player->GetFire() == true) {
		playerBullets[playerBulletCounter]->SetPosition(player->GetX() - 12, player->GetY() + 6);
		playerBullets[playerBulletCounter]->live = true;
		playerBulletCounter += 1;
		if (playerBulletCounter >= 100) {
			playerBulletCounter = 0;
		}
		playerBullets[playerBulletCounter]->SetPosition(player->GetX() + 12, player->GetY() + 6);
		playerBullets[playerBulletCounter]->live = true;
		playerBulletCounter += 1;
		if (playerBulletCounter >= 100) {
			playerBulletCounter = 0;
		}
	}

	for (int i = 0; i <= 99; i++) {
		playerBullets[i]->Actions(fTimeStep);
		MoveSprite(playerBullets[i]->GetSpriteID(), playerBullets[i]->GetX(), playerBullets[i]->GetY());
	}
}
void GameState::Draw() {
	for (int i = 0; i <= 99; i++) {
		if (playerBullets[i]->live == true) {
			DrawSprite(playerBullets[i]->GetSpriteID());
		}
	}
	DrawSprite(player->GetSpriteID());
}
void GameState::Destroy() {
	delete player;
	delete controls;
	for (int i = 0; i <= 99; i++) {
		delete playerBullets[i];
	}
}