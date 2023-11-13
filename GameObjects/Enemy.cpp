#include "Enemy.h"
#include <Novice.h>
void Enemy::Initialze() {
	pos_ = {640.0f, 360.0f};
	velocity_ = {2.0f, 0.0f};
	radius_ = 64.0f;
	isAlive_ = true;
}

void Enemy::Update() {
	pos_.x += velocity_.x;

	if (pos_.x >= 1200.0f || pos_.x <= 64.0f) {
		velocity_.x *= -1.0f;
	}
}

void Enemy::Draw() {
	if (isAlive_) {

		Novice::DrawEllipse(
		    (int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.0f, BLACK, kFillModeSolid);
	}
}

void Enemy::OnCollision() { isAlive_ = false; }
