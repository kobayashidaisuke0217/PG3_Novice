#include "Player.h"
#include <Novice.h>
Player::Player() {}
Player::~Player() {}
void Player::Initialize() { 
	pos = {640.0f, 600.0f};
	bulletPos_ = pos;
	isAtack_ = false;
	moveSpeed_ = 4.0f;
	inputManager_ = inputManager::GetInstance();
}

void Player::Update() {
Move();
Atack();
if (isAtack_) {
	bulletPos_.y -= 6.0f;
}
if (bulletPos_.y <= -10.0f) {
	isAtack_ = false;
}
}

void Player::Draw() { 
	Novice::DrawBox((int)pos.x, (int)pos.y, 64, 64, 0.0f, BLUE, kFillModeSolid);
	if (isAtack_) {
		Novice::DrawEllipse((int)bulletPos_.x, (int)bulletPos_.y, 32, 32, 0.0f, WHITE, kFillModeSolid);
	}
}

void Player::Move() {
	if (inputManager_->Presskey(DIK_A)) {
		pos.x -= moveSpeed_;
     }
	if (inputManager_->Presskey(DIK_D)) {
		pos.x += moveSpeed_;
	}
	if (inputManager_->Presskey(DIK_W)) {
		pos.y -= moveSpeed_;
	}
	if (inputManager_->Presskey(DIK_S)) {
		pos.y += moveSpeed_;
	}
}

void Player::Atack() {
	if (inputManager_->Presskey(DIK_SPACE)){
		if (!isAtack_) {
			bulletPos_ = pos;
			isAtack_ = true;
		}
}
}
