#include "OvenObject.h"
#include "GameManager.h"
#include "Bread.h"

OvenObject::OvenObject()
{
	hImageA = LoadGraph("Image/OvenAfter.png");
	hImageB = LoadGraph("Image/OvenBefore.png");

	Use = false;

	position.x = Screen::WIDTH/2;
	position.y = Screen::HEIGHT/2;

	
	OvenGageMax = 320;
	ObjectSize = 5;

	centerPosition = VGet(position.x - 64 * ObjectSize / 2, position.y - 64 * ObjectSize / 2, 0);

}

OvenObject::~OvenObject()
{
}

VECTOR OvenObject::GetP1()
{
	return VGet(position.x - 64, position.y - 64 , 0);
}

VECTOR OvenObject::GetP2()
{
	return VGet(position.x + 128 , position.y + 64, 0);
}

void OvenObject::Update()
{
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		if (!Push) {
			Push = true;

			int MousePX;
			int MousePY;
			GetMousePoint(&MousePX, &MousePY);

			/*if (MousePX >= centerPosition.x && MousePX <= centerPosition.x + 64 * ObjectSize &&
				MousePY >= centerPosition.y && MousePY <= centerPosition.y + 64 * ObjectSize) {
				if (Use)
					Use = false;
			}*/
		}

	}
	else {
		Push = false;
	}

	if (Use)
	{
		OvenGage += 10;
		if (OvenGage >= OvenGageMax) {
			OvenGage = 0;
			HaveItem = true;
			Use = false;
			Bread* bread = Instantiate<Bread>();
			bread->position =  VGet(position.x + 10, position.y ,0);
			bread->Fire = true;
			bread->OvenNum = myNum;
		}
	}

}

void OvenObject::Draw()
{
	if(Use)
	DrawExtendGraph(centerPosition.x + 0, centerPosition.y +0, centerPosition.x + 64 * ObjectSize,centerPosition.y + 64*ObjectSize,
		hImageA, TRUE);
	else
		DrawExtendGraph(centerPosition.x + 0, centerPosition.y + 0, centerPosition.x + 64 * ObjectSize, centerPosition.y + 64 * ObjectSize,
			hImageB, TRUE);
	DrawBox(centerPosition.x, centerPosition.y + 64 * ObjectSize + 10, centerPosition.x + OvenGageMax, centerPosition.y + 64 * ObjectSize, GetColor(255, 255, 255), TRUE);
	DrawBox(centerPosition.x, centerPosition.y + 64 * ObjectSize + 10, centerPosition.x + OvenGage, centerPosition.y + 64 * ObjectSize, GetColor(0, 255, 0), TRUE);
}
