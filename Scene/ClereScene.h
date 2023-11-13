#pragma once
#include "Iscene.h"
#include "Manager/inputManager.h"
class ClereScene:public IScene
{
public:
	~ClereScene() override;
	void Initialize() override;

	void Update() override;

	void Draw() override;
	void Finalize() override;

private:
	inputManager* inputManager_ = nullptr;
};
