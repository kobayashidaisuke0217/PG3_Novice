#pragma once
#include"Vector2.h"
#include "Manager/inputManager.h"
class Player {
public:
	Player();
	~Player();
	void Initialize();
	void Update();
	void Draw();
	Vector2 GetPos() { return pos; }
	Vector2 GetBulletPos() { return bulletPos_; }

private:
	Vector2 pos;
	float moveSpeed_;
	bool isAtack_;
	Vector2 bulletPos_;
	inputManager* inputManager_;

	void Move();
	void Atack();
};
