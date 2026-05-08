#include "OvenObject.h"
#include "GameManager.h"

OvenObject::OvenObject()
{
	hImageA = LoadGraph("Image/OvenAfter.png");
	hImageB = LoadGraph("Image/OvenBefore.png");

	Use = false;

	position.x = Screen::WIDTH/2;
	position.y = Screen::HEIGHT/2;

	

	ObjectSize = 5;

	centerPosition = VGet(position.x - 64 * ObjectSize / 2, position.y - 64 * ObjectSize / 2, 0);

}

OvenObject::~OvenObject()
{
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

			if (MousePX >= centerPosition.x && MousePX <= centerPosition.x + 64 * ObjectSize &&
				MousePY >= centerPosition.y && MousePY <= centerPosition.y + 64 * ObjectSize) {
				if (Use)
					Use = false;
				else
					Use = true;
			}
		}

	}
	else {
		Push = false;
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
}
