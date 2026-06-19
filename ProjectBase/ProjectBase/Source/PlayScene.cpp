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
	hImage = LoadGraph("Image/BackGround.png");
	hImage2 = LoadGraph("Image/Table.png");

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
	
	DrawExtendGraph(-235,-100, Screen::WIDTH + 265, Screen::HEIGHT,
		hImage, TRUE);
	DrawExtendGraph(-300,200, Screen::WIDTH, Screen::HEIGHT + 500,
		hImage2, TRUE);
	if (GameM != NULL) {
		DrawFormatString(0, 0, GetColor(0, 0, 0), "$:%d", GameM->MyMoney);
	}
}
