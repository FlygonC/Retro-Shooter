#pragma once

#include "Controler.h"
#include "AIE.h"
//Was meant to be more profound in its usage
Controler::Controler(void) {}
Controler::~Controler(void) {}

void Controler::setKeys(int iup, int idown, int ileft, int iright, int ifire) {
	upKey = iup;
	downKey = idown;
	leftKey = ileft;
	rightKey = iright;
	fireKey = ifire;
}

void Controler::updateControler() {
	if (IsKeyDown(upKey)) {
		UP = true;
	}
	else {
		UP = false;
	}
	if (IsKeyDown(downKey)) {
		DOWN = true;
	}
	else {
		DOWN = false;
	}
	if (IsKeyDown(leftKey)) {
		LEFT = true;
	}
	else {
		LEFT = false;
	}
	if (IsKeyDown(rightKey)) {
		RIGHT = true;
	}
	else {
		RIGHT = false;
	}
	if (IsKeyDown(fireKey)) {
		FIRE = true;
	}
	else {
		FIRE = false;
	}
}