#include "SelectGameObject.h"
#include "Bread.h"
#include "OvenObject.h"


Bread* bread;

SelectGameObject::SelectGameObject()
{

	

	Bread1 = LoadGraph("Image/Bread.png");

	position.x = 300;
	position.y = 600;

	ItemNum = 10;

	ObjectSize = 2;

	centerPosition = VGet(position.x - 64 * ObjectSize / 2, position.y - 64 * ObjectSize / 2, 0);
}

SelectGameObject::~SelectGameObject()
{
}

void SelectGameObject::Update()
{
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		if (!Push && ItemNum > 0) {
			Push = true;

			int MousePX;
			int MousePY;

			GetMousePoint(&MousePX, &MousePY);

			if (MousePX >= centerPosition.x && MousePX <= centerPosition.x + 64 * ObjectSize &&
				MousePY >= centerPosition.y && MousePY <= centerPosition.y + 64 * ObjectSize) {
				Hold = true;
				ItemNum--;
				bread = Instantiate<Bread>();
			}
		}

	}
	else {
		bool Use = false;
		if (bread != nullptr && Push) {
			bread->DestroyMe();

			OvenObject* oven = ObjectManager::FindGameObject<OvenObject>();
			if (!oven->Use) {

				VECTOR ovenP1 = oven->GetP1();
				VECTOR ovenP2 = oven->GetP2();
				if (ovenP1.x < GetMouseP().x && ovenP2.x > GetMouseP().x &&
					ovenP1.y < GetMouseP().y && ovenP2.y > GetMouseP().y) {
					oven->Use = true;
					Use = true;
				}
			}
		}
		if (!Use && Hold) {
			ItemNum++;
		}
		Push = false;
		Hold = false;
	}

	if (Hold) {
		
		int MousePX;
		int MousePY;
		GetMousePoint(&MousePX, &MousePY);
		bread->position = VGet(MousePX, MousePY, 0);
		bread->centerPosition = VGet(bread->position.x - 64 * ObjectSize / 2, bread->position.y - 64 * ObjectSize / 2, 0);
	}

}

VECTOR SelectGameObject::GetMouseP()
{
	int MousePX;
	int MousePY;
	GetMousePoint(&MousePX, &MousePY);
	return VGet(MousePX, MousePY, 0);
}

void SelectGameObject::Draw()
{
	switch(selectNum)
	{
	case 0:
		DrawExtendGraph(centerPosition.x + 0, centerPosition.y + 0, centerPosition.x + 64 * ObjectSize, centerPosition.y + 64 * ObjectSize,
			Bread1, TRUE);
		SetFontSize(20);
		DrawFormatString(position.x + 32, position.y, GetColor(255, 255, 255),"Å~%d", ItemNum);
		break;
	default:
		break;
	}
}
