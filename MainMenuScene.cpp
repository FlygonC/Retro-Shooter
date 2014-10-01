#pragma once

#include "MainMenuState.h"
#include "AIE.h"
#include "BaseState.h"
#include "StateMachine.h"

extern const int screenWidth;
extern const int screenHeight;

MainMenuState::MainMenuState(void) {}
MainMenuState::~MainMenuState(void) {}

void MainMenuState::Initialize() {
	MenuScreenBG = CreateSprite("./images/crate_sideup.png", screenWidth, screenHeight, true);
	MoveSprite(MenuScreenBG, screenWidth / 2, screenHeight / 2);
}
void MainMenuState::Update(float fTimeStep, StateMachine* pSM) {
}
void MainMenuState::Draw() {
	DrawSprite(MenuScreenBG);
}
void MainMenuState::Destroy() {
	DestroySprite(MenuScreenBG);
}