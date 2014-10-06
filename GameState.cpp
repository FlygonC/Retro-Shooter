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
		enemies[i] = new Enemy();
	}
	enemyCounter = 0;

	this->EnemyWave = &Wave1;
	currentWave = 1;
	waveTime = 0;
	waveStep = 0;

	for (int i = 0; i <= 99; i++) {
		playerBullets[i] = new BlueBullet();
	}
	playerBulletCounter = 0;

	controls = new Controler();
	controls->setKeys(265, 264, 263, 262, 32);
}

void GameState::playerFireBullets(float fX, float fY, float fOffset) {
	playerBullets[playerBulletCounter]->SetPosition(player->GetX() + fX, player->GetY() + fY);
	playerBullets[playerBulletCounter]->setOffset(fOffset);
	playerBullets[playerBulletCounter]->live = true;
	playerBulletCounter += 1;
	if (playerBulletCounter >= 100) {
		playerBulletCounter = 0;
	}
}

void GameState::Wave1(float fTimeStep) {
	waveTime += fTimeStep;
	waveStep += fTimeStep;
	if (waveStep >= 5) {
		waveStep -= 5;
		enemies[enemyCounter]->SetPosition(rand() % 399, rand() % 599);
		enemies[enemyCounter]->live = true;
		enemyCounter++;
		if (enemyCounter >= 100) {
			enemyCounter = 0;
		}
	}
}

void GameState::Update(float fTimeStep, StateMachine* pSM) {
	controls->updateControler();

	player->Actions(fTimeStep, controls);
	MoveSprite(player->GetSpriteID(), player->GetX(), player->GetY());

	EnemyWave(fTimeStep);

	/*switch (currentWave) {
	case 1:
		Wave1(fTimeStep);
		break;
	}
	waveStep += fTimeStep;
	if (waveStep >= 5) {
		waveStep -= 5;
		enemies[enemyCounter]->SetPosition(rand() % 399, rand() % 599);
		enemies[enemyCounter]->live = true;
		enemyCounter++;
		if (enemyCounter >= 100) {
			enemyCounter = 0;
		}
	}*/


	for (int i = 0; i <= 99; i++) {
		enemies[i]->Actions(fTimeStep);
		MoveSprite(enemies[i]->GetSpriteID(), enemies[i]->GetX(), enemies[i]->GetY());
		for (int j = 0; j <= 99; j++) {
			/*if ( sqrt(enemies[i]->GetX() - playerBullets[j]->GetX()) + sqrt(enemies[i]->GetY() - playerBullets[j]->GetY()) <= sqrt(enemies[i]->GetWidth())
				&& enemies[i]->live == true && playerBullets[j]->live == true) {
				playerBullets[j]->live = false;
				enemies[i]->hp -= 1;
			}*/
			if (abs(playerBullets[j]->GetX() - enemies[i]->GetX()) <= enemies[i]->GetWidth() / 2 && abs(playerBullets[j]->GetY() - enemies[i]->GetY()) <= enemies[i]->GetHeight() / 2
				&& enemies[i]-> live == true && playerBullets[j]->live == true) {
				playerBullets[j]->live = false;
				enemies[i]->hp -= 1;
			}
		}
	}

	if (player->GetFire() == true) {
		playerFireBullets(0, 18, 0);
		playerFireBullets(6, 10, 30);
		playerFireBullets(-6, 10, -30);
		playerFireBullets(14, 6, 60);
		playerFireBullets(-14, 6, -60);
	}

	for (int i = 0; i <= 99; i++) {
		playerBullets[i]->Actions(fTimeStep);
		MoveSprite(playerBullets[i]->GetSpriteID(), playerBullets[i]->GetX(), playerBullets[i]->GetY());
	}
}
void GameState::Draw() {
	for (int i = 0; i <= 99; i++) {
		if (enemies[i]->live == true) {
			DrawSprite(enemies[i]->GetSpriteID());
		}
	}
	for (int i = 0; i <= 99; i++) {
		if (playerBullets[i]->live == true) {
			DrawSprite(playerBullets[i]->GetSpriteID());
		}
	}
	DrawSprite(player->GetSpriteID());
}
void GameState::Destroy() {
	delete player;
	for (int i = 0; i <= 99; i++) {
		delete enemies[i];
	}
	delete controls;
	for (int i = 0; i <= 99; i++) {
		delete playerBullets[i];
	}
}