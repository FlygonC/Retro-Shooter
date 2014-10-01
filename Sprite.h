#pragma once

class Sprite {
public:
	Sprite(void);
	~Sprite(void);
protected:
	unsigned int spriteID;
	float width;
	float height;
	float x;
	float y;
public:
	virtual unsigned int GetSpriteID();
	virtual float GetWidth();
	virtual float GetHeight();
	virtual float GetX();
	virtual float GetY();
	virtual void SetX(float sX);
	virtual void SetY(float sY);
	virtual void SetPosition(float sX, float sY);
};