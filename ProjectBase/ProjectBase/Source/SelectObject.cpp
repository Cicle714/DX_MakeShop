#include "SelectGameObject.h"
#include "Bread.h"


Bread* bread;

SelectGameObject::SelectGameObject()
{

	

	Bread1 = LoadGraph("Image/Bread.png");

	position.x = 300;
	position.y = 600;



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
		if (!Push) {
			Push = true;

			int MousePX;
			int MousePY;

			GetMousePoint(&MousePX, &MousePY);

			if (MousePX >= centerPosition.x && MousePX <= centerPosition.x + 64 * ObjectSize &&
				MousePY >= centerPosition.y && MousePY <= centerPosition.y + 64 * ObjectSize) {
				Hold = true;
				bread = Instantiate<Bread>();
			}
		}

	}
	else {
		Push = false;
		Hold = false;
		if(bread != nullptr)
		bread->DestroyMe();
	}

	if (Hold) {
		
		int MousePX;
		int MousePY;
		GetMousePoint(&MousePX, &MousePY);
		bread->position = VGet(MousePX, MousePY, 0);
		bread->centerPosition = VGet(bread->position.x - 64 * ObjectSize / 2, bread->position.y - 64 * ObjectSize / 2, 0);
	}

}

void SelectGameObject::Draw()
{
	switch(selectNum)
	{
	case 0:
		DrawExtendGraph(centerPosition.x + 0, centerPosition.y + 0, centerPosition.x + 64 * ObjectSize, centerPosition.y + 64 * ObjectSize,
			Bread1, TRUE);
		break;
	default:
		break;
	}
}
