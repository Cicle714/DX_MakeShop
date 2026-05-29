#include "PlayScene.h"
#include "ItemData.h"
#include "StartFlag.h"
#include "OvenObject.h"
#include "SelectGameObject.h"
#include "Bread.h"
#include "BuyArea.h"
#include <DxLib.h>
#include "GameManager.h"

PlayScene::PlayScene()
{
	SelectGameObject* select;
	new ItemData();
	new StartFlag();
	Instantiate<GameManager>();
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
	GameM = ObjectManager::FindGameObject<GameManager>();
	SetFontSize(64);
	if (GameM != NULL) {
		DrawFormatString(0, 0, GetColor(255, 255, 255), "$:%d", GameM->MyMoney);
	}
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
