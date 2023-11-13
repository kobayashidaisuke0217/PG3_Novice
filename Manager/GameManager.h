#pragma once
#pragma region エンジン
#include <Novice.h>
#include "inputManager.h"
#pragma endregion
#include<memory>
#pragma region SCENE
#include"Scene/IScene.h"
#include"Scene/StageScene.h"
#include "Scene/TitleScene.h"
#include "Scene/ClereScene.h"
#pragma endregion
class GameManager {
public:
	GameManager();
	~GameManager();

	void Initialize();
	/*void Update();
	void Draw();
	void Finalize();*/
	void Run();
	private:
	inputManager* inputManager_;
	std::unique_ptr<IScene> sceneArry[3];
	int currentSceneNum_;
	int prevSceneNum_;
};
