#pragma once
#include "../Library/SceneBase.h"
#include "GameManager.h"

class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;
private: 
	GameManager* GameM;
	int hImage;
	int hImage2;
};
