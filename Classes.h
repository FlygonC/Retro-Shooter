class Sprite {
public:
	Sprite() {}
	unsigned int spriteID;
	float height;
	float width;
	float x;
	float y;
	
};


class Plane : public Sprite {
public:
	float health;
	float thrust;
	float lift;
	float turn;

	bool thrusting = false;
	bool turnLeft = false;
	bool turnRight = false;
	bool brake = false;
	float speedThrust = 100;
	float speedTurn;

	void Move(float timestep) {
		y += timestep*speedThrust;
	}
};
class Player : public Plane {
public:
	Player() {
		width = 40;
		height = 40;
		x = 400;
		y = 200;
		spriteID = CreateSprite("./images/plane1idle.png", width, height, true);
		health = 100;
		thrust = 10;
		lift = 50;
		turn = 10;
	}
};
class EnemyEasy : public Plane {
public:
	EnemyEasy() {
		width = 40;
		height = 40;
		x = 500;
		y = 200;
		spriteID = CreateSprite("./images/plane2idle.png", width, height, true);
		health = 100;
		thrust = 10;
		lift = 50;
		turn = 10;
	}
};


class Projectile : Sprite {
public:
	bool live = true;
	float speed;
	float speedChange;
	float damage;
};