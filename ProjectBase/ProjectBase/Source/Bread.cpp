#include "Bread.h"

Bread::Bread()
{
	Bread1 = LoadGraph("Image/Bread.png");
	Bread2 = LoadGraph("Image/Bread2.png");




	ObjectSize = 2;
	centerPosition = VGet(position.x - 64 * ObjectSize / 2, position.y - 64 * ObjectSize / 2, 0);
}

Bread::~Bread()
{
}

void Bread::Update()
{
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		if (!Push && Fire) {
			Push = true;
			int MousePX;
			int MousePY;
			GetMousePoint(&MousePX, &MousePY);
			position = VGet(MousePX, MousePY, 0);if (MousePX >= centerPosition.x && MousePX <= centerPosition.x + 64 * ObjectSize &&
				MousePY >= centerPosition.y && MousePY <= centerPosition.y + 64 * ObjectSize) {
				Hold = true;
			}
		}

	}
	else {
		Push = false;
		if (Hold) {
			DestroyMe();
		}
	}
	if (Hold) {
		int MousePX;
		int MousePY;
		GetMousePoint(&MousePX, &MousePY);
		position = VGet(MousePX, MousePY, 0);
		centerPosition = VGet(position.x - 64 * ObjectSize / 2, position.y - 64 * ObjectSize / 2, 0);
	}
}

void Bread::Draw()
{
	if (Fire)
		DrawExtendGraph(centerPosition.x + 0, centerPosition.y + 0, centerPosition.x + 64 * ObjectSize, centerPosition.y + 64 * ObjectSize,
			Bread2, TRUE);
	else
		DrawExtendGraph(centerPosition.x + 0, centerPosition.y + 0, centerPosition.x + 64 * ObjectSize, centerPosition.y + 64 * ObjectSize,
			Bread1, TRUE);
}
