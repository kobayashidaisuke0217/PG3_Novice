#include "TitleScene.h"
#include<Novice.h>
TitleScene::~TitleScene() {}

void TitleScene::Initialize() { inputManager_ = inputManager::GetInstance(); }

void TitleScene::Update() {
	if (inputManager_->PushKey(DIK_SPACE)) {
		sceneNum = GAME_SCENE;
	}
}

void TitleScene::Draw() {

Novice::ScreenPrintf(300, 400, "PUSH SPACE"); 

}

void TitleScene::Finalize() {}
