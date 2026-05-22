#include "PlayScene.h"
#include "ItemData.h"
#include "StartFlag.h"
#include "OvenObject.h"
#include "SelectGameObject.h"
#include "Bread.h"
#include "BuyArea.h"
#include <DxLib.h>

PlayScene::PlayScene()
{
	SelectGameObject* select;
	new ItemData();
	new StartFlag();
	Instantiate<BuyArea>();
	OvenObject* Oven1 = Instantiate<OvenObject>();
	Oven1->myNum = 0;
	select = Instantiate<SelectGameObject>();
	select->GetNum(0);
	
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TitleScene");
	}
}

void PlayScene::Draw()
{
	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
