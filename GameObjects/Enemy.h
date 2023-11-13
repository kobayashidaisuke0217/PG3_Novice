#pragma once
#include"Vector2.h"
class Enemy {
public:
	void Initialze();
	void Update();
	void Draw();
	void OnCollision();
	bool GetIsAlive() { return isAlive_; }
	Vector2 GetPos() { return pos_; }
	float GetSize() { return radius_; }

private:
	Vector2 pos_;
	Vector2 velocity_;
	float radius_;
	bool isAlive_;
};
