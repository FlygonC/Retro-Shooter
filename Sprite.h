#pragma once

class Sprite {
public:
	Sprite(void);
	~Sprite(void);

	unsigned int GetSpriteID();
	float GetWidth();
	float GetHeight();
	float GetX();
	float GetY();
	void SetX(float sX);
	void SetY(float sY);
	void SetPosition(float sX, float sY);
protected:
	unsigned int spriteID;
	float width;
	float height;
	float x;
	float y;	
};