#pragma once

#include "MainMenuState.h"
#include "AIE.h"
#include "BaseState.h"
#include "StateMachine.h"
#include "GameState.h"

extern const int screenWidth;
extern const int screenHeight;

MainMenuState::MainMenuState(void) {}
MainMenuState::~MainMenuState(void) {}

void MainMenuState::Initialize() {
	MenuScreenBG = CreateSprite("./images/crate_sideup.png", screenWidth, screenHeight, true);
	MoveSprite(MenuScreenBG, screenWidth / 2, screenHeight / 2);
}
void MainMenuState::Update(float fTimeStep, StateMachine* pSM) {
	if (IsKeyDown(257)) {
		delete pSM->SwitchState(new GameState);
	}
}
void MainMenuState::Draw() {
	//DrawSprite(MenuScreenBG);
	DrawString("Press Enter to start", 0, 60);
	DrawString("Press Esc to quit", 0, 30);
}
void MainMenuState::Destroy() {
	DestroySprite(MenuScreenBG);
}