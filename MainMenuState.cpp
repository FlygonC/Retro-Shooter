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
	unsigned int splashScreen = CreateSprite("./images/splashscreen.png", screenWidth, screenHeight, false);
	MoveSprite(splashScreen, 0, 0);
	DrawSprite(splashScreen);

	MenuScreenBG = CreateSprite("./images/crate_sideup.png", screenWidth, screenHeight, true);
	MoveSprite(MenuScreenBG, screenWidth / 2, screenHeight / 2);
	screen = 0;
}
void MainMenuState::Update(float fTimeStep, StateMachine* pSM) {
	if (IsKeyDown(257)) {
		delete pSM->SwitchState(new GameState);
	}
	if (IsKeyDown(32)) {
		screen = 1;
	}
}
void MainMenuState::Draw() {
	//DrawSprite(MenuScreenBG);
	if (screen == 0) {
		DrawString("Press Enter to start", 0, 90);
		DrawString("Press Space for controls", 0, 60);
		DrawString("Press Esc to quit", 0, 30);
	}
	else if (screen == 1) {
		DrawString("Arrow Keys = Movement", 0, 600);
		DrawString("Space = Shoot", 0, 570);
		DrawString("Press Enter to start", 0, 30);
	}
}
void MainMenuState::Destroy() {
	DestroySprite(MenuScreenBG);
}