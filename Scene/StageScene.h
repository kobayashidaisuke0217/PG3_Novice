#pragma once
#include "IScene.h"
#include "Manager/inputManager.h"
#include"GameObjects/Player.h"
#include"GameObjects/Enemy.h"
#include <memory>
class StageScene:public IScene  {
public:
	~StageScene() override;
	void Initialize() override;

	void Update() override;

	void Draw() override;
	void Finalize() override;

private:
	inputManager* inputManager_ = nullptr;
	std::unique_ptr<Player> player_;
	std::unique_ptr<Enemy> enemy_;
};
