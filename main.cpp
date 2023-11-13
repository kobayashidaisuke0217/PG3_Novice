#include <Novice.h>
#include "Manager/GameManager.h"
const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>();
	gameManager->Run();
	return 0;
}
