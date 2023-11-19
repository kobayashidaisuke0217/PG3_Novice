#include "GameManager.h"

GameManager::GameManager() {}

GameManager::~GameManager() {}

void GameManager::Initialize() { 
	Novice::Initialize("PG3_StatePattern", 1280, 720);
	inputManager_ = inputManager::GetInstance();
	inputManager_->Initialize();
	sceneArry[0] = std::make_unique<TitleScene>();
	sceneArry[0]->Initialize();
	sceneArry[1] = std::make_unique<StageScene>();
	sceneArry[2] = std::make_unique<ClereScene>();
	currentSceneNum_ = TITLE_SCENE;
}

void GameManager::Run() {
	Initialize();
	    // ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		inputManager_->Update();

		///
		/// ↓更新処理ここから
		///
		prevSceneNum_ = currentSceneNum_;
		currentSceneNum_ = sceneArry[currentSceneNum_]->GetSceneNum();
		if (currentSceneNum_ != prevSceneNum_) {
		
		sceneArry[prevSceneNum_]->Finalize();
		sceneArry[currentSceneNum_]->Initialize();
		}
		sceneArry[currentSceneNum_]->Update();
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		sceneArry[currentSceneNum_]->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (inputManager_->PushKey(DIK_ESCAPE)) {
			break;
		}
	}
	Novice::Finalize();

}
