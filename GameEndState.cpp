#pragma once

#include "GameEndState.h"

extern const int screenWidth;
extern const int screenHeight;

extern float score;

GameEndState::GameEndState(void) {}
GameEndState::~GameEndState(void) {}

void GameEndState::Initialize() {

}

void GameEndState::Update(float fTimeStep, StateMachine* pSM) {
	if (IsKeyDown(257)) {
		delete pSM->SwitchState(new GameState);
	}
}

void GameEndState::Draw() {
	DrawString("Press Enter to restart", 0, 30);
	DrawString("Score:", 150, 360);

	char buffer1[20];
	itoa(score, buffer1, 10);
	DrawString(buffer1, 150, 330);
}

void GameEndState::Destroy() {

}