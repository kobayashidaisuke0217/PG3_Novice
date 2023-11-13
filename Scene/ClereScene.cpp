#include "ClereScene.h"

ClereScene::~ClereScene() {}

void ClereScene::Initialize() { inputManager_ = inputManager::GetInstance(); }

void ClereScene::Update() {
	if (inputManager_->PushKey(DIK_SPACE)) {
		sceneNum = TITLE_SCENE;
	}
}

void ClereScene::Draw() { Novice::ScreenPrintf(300, 400, "GAME CLEAR");
	Novice::ScreenPrintf(300, 500, "PUSH SPACE");
}

void ClereScene::Finalize() {}
