#pragma once

#include "Sprite.h"

Sprite::Sprite(void) {}
Sprite::~Sprite(void) {}

unsigned int Sprite::GetSpriteID() {
	return spriteID;
}
float Sprite::GetWidth() {
	return width;
}
float Sprite::GetHeight() {
	return height;
}
float Sprite::GetX() {
	return x;
}
float Sprite::GetY() {
	return y;
}
void Sprite::SetX(float sX) {
	x = sX;
}
void Sprite::SetY(float sY) {
	y = sY;
}
void Sprite::SetPosition(float sX, float sY) {
	x = sX;
	y = sY;
}