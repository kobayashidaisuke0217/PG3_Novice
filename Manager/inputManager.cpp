#include "inputManager.h"

inputManager* inputManager::GetInstance() {
	static inputManager instance;
	return &instance;
}

void inputManager::Initialize() { 
	for (int i = 0; i < 256; i++) {
		keys[i] = {0};
		preKeys[i] = {0};
	}
	
}

void inputManager::Update() { 
	for (int i = 0; i < 256; i++) {
		preKeys[i] = keys[i];
	}
	Novice::GetHitKeyStateAll(keys); }

bool inputManager::PushKey(uint8_t keynum) { 
	if (!keys[keynum] && preKeys[keynum]) {
		return true;
	} else {
		return false;
	}
}

bool inputManager::Presskey(uint8_t keynum) {
	if (keys[keynum]) {
		return true;
	} else {
		return false;
	}
}
