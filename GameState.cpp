#pragma once

#include "GameState.h"

extern const int screenWidth;
extern const int screenHeight;

extern float score = 0;

GameState::GameState(void) {}
GameState::~GameState(void) {}

void GameState::Initialize() {
	unsigned int splashScreen = CreateSprite("./images/splashscreen.png", screenWidth, screenHeight, false);
	MoveSprite(splashScreen, 0, 0);
	DrawSprite(splashScreen);

	player = new Player();
	score = 0;
	lives = 20;
	
	for (int i = 0; i <= maxEnemies-1; i++) {
		enemies[i] = new Enemy();
	}
	enemyCounter = 0;
	//waves are not in order by number
	GameState::EnemyWave = &GameState::Wave3;
	currentWave = 1;
	waveTime = 0;
	waveStep = 0;

	for (int i = 0; i <= maxPlayerBullets-1; i++) {
		playerBullets[i] = new BlueBullet();
	}
	playerBulletCounter = 0;

	for (int i = 0; i <= maxEnemyBullets-1; i++) {
		enemyBullets[i] = new RedBullet();
	}
	enemyBulletCounter = 0;

	controls = new Controler();
	controls->setKeys(265, 264, 263, 262, 32);
}
//bullet creation functions
void GameState::playerFireBullets(float fX, float fY, float fOffset) {
	playerBullets[playerBulletCounter]->SetPosition(player->GetX() + fX, player->GetY() + fY);
	playerBullets[playerBulletCounter]->setOffset(fOffset);
	playerBullets[playerBulletCounter]->live = true;
	playerBulletCounter += 1;
	if (playerBulletCounter >= maxPlayerBullets) {
		playerBulletCounter = 0;
	}
}

void GameState::enemyFireBullets(float fX, float fY, float sXSpeed, float sYSpeed) {
	enemyBullets[enemyBulletCounter]->SetPosition(fX, fY);
	enemyBullets[enemyBulletCounter]->SetXSpeed(sXSpeed);
	enemyBullets[enemyBulletCounter]->SetYSpeed(sYSpeed);
	enemyBullets[enemyBulletCounter]->live = true;
	enemyBulletCounter += 1;
	if (enemyBulletCounter >= maxEnemyBullets) {
		enemyBulletCounter = 0;
	}
}
//test wave
void GameState::Wave0(float fTimeStep) {
	waveTime += fTimeStep;
	waveStep += fTimeStep;
	if (waveStep >= 1) {
		waveStep -= 1;
		enemies[enemyCounter]->Spawn(target, rand() % 399, rand()%589+20);
		enemyCounter++;
		if (enemyCounter >= maxEnemies) {
			enemyCounter = 0;
			//GameState::EnemyWave = &GameState::Wave1;
		}
	}
}
//Enemy waves
void GameState::Wave1(float fTimeStep) {
	waveTime += fTimeStep;
	waveStep += fTimeStep;
	if (waveStep >= 0.8) {
		waveStep -= 0.8;
		enemies[enemyCounter]->Spawn(sideFlier, 0, 0);
		enemyCounter++;
		if (enemyCounter >= maxEnemies) {
			enemyCounter = 0;
			GameState::EnemyWave = &GameState::Wave4;
		}
	}
}
void GameState::Wave2(float fTimeStep) {
	waveTime += fTimeStep;
	waveStep += fTimeStep;
	if (waveStep >= 0.6) {
		waveStep -= 0.6;
		enemies[enemyCounter]->Spawn(bottomChaser, 0, 0);
		enemyCounter++;
		if (enemyCounter >= maxEnemies) {
			enemyCounter = 0;
			GameState::EnemyWave = &GameState::Wave3;
		}
	}
}
void GameState::Wave3(float fTimeStep) {
	waveTime += fTimeStep;
	waveStep += fTimeStep;
	if (waveStep >= 0.6) {
		waveStep -= 0.6;
		enemies[enemyCounter]->Spawn(topEnemy, 0, 0);
		enemyCounter++;
		if (enemyCounter >= maxEnemies) {
			enemyCounter = 0;
			GameState::EnemyWave = &GameState::Wave1;
		}
	}
}
void GameState::Wave4(float fTimeStep) {
	waveTime += fTimeStep;
	waveStep += fTimeStep;
	if (waveStep >= 0.6) {
		waveStep -= 0.6;
		enemies[enemyCounter]->Spawn(sideShooter, 0, 0);
		enemyCounter++;
		if (enemyCounter >= maxEnemies) {
			enemyCounter = 0;
			GameState::EnemyWave = &GameState::Wave2;
		}
	}
}

void GameState::Update(float fTimeStep, StateMachine* pSM) {
	controls->updateControler();

	player->Actions(fTimeStep, controls);
	MoveSprite(player->GetSpriteID(), player->GetX(), player->GetY());
	//Enemy wave function call
	(this->*EnemyWave)(fTimeStep);
	//enemys for loop
	for (int i = 0; i <= maxEnemies-1; i++) {
		//actions
		enemies[i]->Actions(fTimeStep);
		MoveSprite(enemies[i]->GetSpriteID(), enemies[i]->GetX(), enemies[i]->GetY());
		//enemies shooting
		if (enemies[i]->GetFire()) {
			switch (enemies[i]->type) {
			case sideFlier:
				enemyFireBullets(enemies[i]->GetX(), enemies[i]->GetY(), 0, 80);
				enemyFireBullets(enemies[i]->GetX(), enemies[i]->GetY(), 0, -80);
				break;
			case bottomChaser:
				enemyFireBullets(enemies[i]->GetX(), enemies[i]->GetY(), 80, 00);
				enemyFireBullets(enemies[i]->GetX(), enemies[i]->GetY(), -80, 00);
				break;
			case topEnemy:
				//enemyFireBullets(enemies[i]->GetX(), enemies[i]->GetY(), 0, -80);
				enemyFireBullets(enemies[i]->GetX()+14, enemies[i]->GetY(), 0, -160);
				enemyFireBullets(enemies[i]->GetX()-14, enemies[i]->GetY(), 0, -160);
				enemyFireBullets(enemies[i]->GetX(), enemies[i]->GetY(), 0, -230);
				break;
			case sideShooter:
				enemyFireBullets(enemies[i]->GetX(), enemies[i]->GetY(), 30, -80);
				enemyFireBullets(enemies[i]->GetX(), enemies[i]->GetY(), -30, -80);
				enemyFireBullets(enemies[i]->GetX(), enemies[i]->GetY(), 0, 50);
				break;
			}
		}
		//collision with player bullets
		for (int j = 0; j <= maxPlayerBullets-1; j++) {
			//circle collision
			if (sqrt((enemies[i]->GetX() - playerBullets[j]->GetX())*(enemies[i]->GetX() - playerBullets[j]->GetX()) + (enemies[i]->GetY() - playerBullets[j]->GetY())*(enemies[i]->GetY() - playerBullets[j]->GetY())) <= 20 /*sqrt(enemies[i]->GetWidth())*/
				&& enemies[i]->live == true && playerBullets[j]->live == true) {
				playerBullets[j]->live = false;
				if (enemies[i]->hp == 1) {
					score += 1;
				}
				enemies[i]->hp -= 1;
			}
			//square collision
			/*if (abs(playerBullets[j]->GetX() - enemies[i]->GetX()) <= enemies[i]->GetWidth() / 2 && abs(playerBullets[j]->GetY() - enemies[i]->GetY()) <= enemies[i]->GetHeight() / 2
				&& enemies[i]-> live == true && playerBullets[j]->live == true) {
				playerBullets[j]->live = false;
				enemies[i]->hp -= 1;
			}*/
		}
	}
	//if player is shooting
	if (player->GetFire() == true) {
		//playerFireBullets(0, 18, 0);
		playerFireBullets(12, 0, 0);
		playerFireBullets(-12, 0, 0);
		//playerFireBullets(14, 6, 100);
		//playerFireBullets(-14, 6, -100);
	}
	//player bullets actions for loop
	for (int i = 0; i <= maxPlayerBullets-1; i++) {
		playerBullets[i]->Actions(fTimeStep);
		MoveSprite(playerBullets[i]->GetSpriteID(), playerBullets[i]->GetX(), playerBullets[i]->GetY());

	}
	//enemy bullets actions & collision with player
	for (int i = 0; i <= maxEnemyBullets - 1; i++) {
		enemyBullets[i]->Actions(fTimeStep);
		MoveSprite(enemyBullets[i]->GetSpriteID(), enemyBullets[i]->GetX(), enemyBullets[i]->GetY());
		if (sqrt((player->GetX() - enemyBullets[i]->GetX())*(player->GetX() - enemyBullets[i]->GetX()) + (player->GetY() - enemyBullets[i]->GetY())*(player->GetY() - enemyBullets[i]->GetY())) <= 15 /*sqrt(enemies[i]->GetWidth())*/
			&& enemyBullets[i]->live == true) {
			enemyBullets[i]->live = false;
			lives -= 1;
			//enemies[i]->hp -= 1;
		}
	}
	//if out of lives
	if (lives <= 0) {
		delete pSM->SwitchState(new GameEndState);
	}
}
void GameState::Draw() {
	//draw enemies
	for (int i = 0; i <= maxEnemies-1; i++) {
		if (enemies[i]->live == true) {
			DrawSprite(enemies[i]->GetSpriteID());
		}
	}
	//draw player bullets
	for (int i = 0; i <= maxPlayerBullets-1; i++) {
		if (playerBullets[i]->live == true) {
			DrawSprite(playerBullets[i]->GetSpriteID());
		}
	}
	//draw enemy bullets
	for (int i = 0; i <= maxEnemyBullets - 1; i++) {
		if (enemyBullets[i]->live == true) {
			DrawSprite(enemyBullets[i]->GetSpriteID());
		}
	}
	//draw player
	DrawSprite(player->GetSpriteID());
	//draw score
	char buffer1[20];
	itoa(score, buffer1, 10);
	DrawString(buffer1, 0, 30);
	//draw lives
	char buffer2[4];
	itoa(lives, buffer2, 10);
	DrawString(buffer2, 360, 30);
}
void GameState::Destroy() {
	delete player;
	for (int i = 0; i <= maxEnemies-1; i++) {
		delete enemies[i];
	}
	delete controls;
	for (int i = 0; i <= maxPlayerBullets-1; i++) {
		delete playerBullets[i];
	}
	for (int i = 0; i <= maxEnemyBullets-1; i++) {
		delete enemyBullets[i];
	}
}