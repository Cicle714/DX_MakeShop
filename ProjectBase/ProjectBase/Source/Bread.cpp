#include "Bread.h"
#include "BuyArea.h"
#include "OvenObject.h"


Bread::Bread()
{
	GameM = ObjectManager::FindGameObject<GameManager>();

	Bread1 = LoadGraph("Image/Bread.png");
	Bread2 = LoadGraph("Image/Bread2.png");




	ObjectSize = 128;
	centerPosition = VGet(position.x - ObjectSize / 2, position.y -  ObjectSize / 2, 0);
}

Bread::~Bread()
{
}

void Bread::Update()
{
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		if (!Push && Fire) {
			FireObjectPos = position;
			Push = true;
			int MousePX;
			int MousePY;
			GetMousePoint(&MousePX, &MousePY);
			if (MousePX >= position.x - ObjectSize / 2 && MousePX <= position.x + ObjectSize / 2 &&
				MousePY >= position.y - ObjectSize / 2 && MousePY <= position.y + ObjectSize / 2) {
				Hold = true;
				position = VGet(MousePX, MousePY, 0);
			}
		}

	}
	else {
		Push = false;
		if (Hold) {
			int MousePX;
			int MousePY;
			GetMousePoint(&MousePX, &MousePY);
			BuyArea* buy = ObjectManager::FindGameObject<BuyArea>();
			if (buy->GetSize1().x <= MousePX && buy->GetSize1().y <= MousePY &&
				buy->GetSize2().x >= MousePX && buy->GetSize2().y >= MousePY) {
				OvenObject* oven = ObjectManager::FindGameObject<OvenObject>();
				oven->HaveItem = false;
				GameM->MyMoney += 100;
				DestroyMe();
			}

			else {
				position = FireObjectPos;
			}
			Hold = false;
		}
	}
	if (Hold) {
		int MousePX;
		int MousePY;
		GetMousePoint(&MousePX, &MousePY);
		position = VGet(MousePX, MousePY, 0);
	}
}

void Bread::Draw()
{
	if (Fire) {
		DrawFormatString(500, 0, GetColor(255, 255, 255), "x:%d  y:%d", position.x, position.y);
		DrawExtendGraph(position.x - ObjectSize / 2, position.y - ObjectSize / 2, position.x + ObjectSize / 2, position.y + ObjectSize / 2,
			Bread2, TRUE);
	}
	else
		DrawExtendGraph(position.x - ObjectSize / 2, position.y - ObjectSize / 2, position.x + ObjectSize / 2, position.y + ObjectSize / 2,
			Bread1, TRUE);
}
