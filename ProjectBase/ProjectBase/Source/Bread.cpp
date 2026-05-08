#include "Bread.h"

Bread::Bread()
{
	Bread1 = LoadGraph("Image/Bread.png");
	Bread2 = LoadGraph("Image/Bread2.png");




	ObjectSize = 2;

}

Bread::~Bread()
{
}

void Bread::Update()
{
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
