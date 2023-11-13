#include "StageScene.h"

StageScene::~StageScene() {}

void StageScene::Initialize() { inputManager_ = inputManager::GetInstance();
	player_ = std::make_unique<Player>();
	player_->Initialize();
	enemy_ = std::make_unique<Enemy>();
	enemy_->Initialze();
}

void StageScene::Update() { 
	enemy_->Update();
	player_->Update();
}

void StageScene::Draw() { 
	enemy_->Draw();
	player_->Draw(); 
   Vector2 Distance = {
	    (enemy_->GetPos().x - player_->GetBulletPos().x) *
	        (enemy_->GetPos().x - player_->GetBulletPos().x),
	    (enemy_->GetPos().y - player_->GetBulletPos().y) *
	        (enemy_->GetPos().y - player_->GetBulletPos().y)
	};
	if (Distance.x + Distance.y <= (enemy_->GetSize() + 32.0f) * (enemy_->GetSize() + 32.0f)) {
	   enemy_->OnCollision();
	}
	if (!enemy_->GetIsAlive()) {
	 
		sceneNum = CLEAR_SCENE;
	}
}

void StageScene::Finalize() {}
