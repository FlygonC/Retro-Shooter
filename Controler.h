#pragma once

class Controler {
public:
	Controler(void);
	~Controler(void);

	bool UP;
	bool DOWN;
	bool LEFT;
	bool RIGHT;
	bool FIRE;

	int upKey;
	int downKey;
	int leftKey;
	int rightKey;
	int fireKey;

	void setKeys(int up, int down, int left, int right, int fire);

	void updateControler();
};