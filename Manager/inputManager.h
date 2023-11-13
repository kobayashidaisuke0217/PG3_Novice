#pragma once
#include <Novice.h>
#include <stdint.h>
class inputManager {
public:
	static inputManager* GetInstance();
	void Initialize();
	void Update();
	//void Draw();
    bool PushKey(uint8_t keynum );
	bool Presskey(uint8_t keynum);
	private:
	char keys[256];
	char preKeys[256];
};
