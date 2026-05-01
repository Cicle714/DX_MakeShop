#include "OvenObject.h"

OvenObject::OvenObject()
{
	hImageA = LoadGraph("Image/OvenAfter.png");
	hImageB = LoadGraph("Image/OvenBefore.png");

	position.x = 500;
	position.y = 300;
	DrawGraph(position.x, position.y, hImageA, TRUE);
}

OvenObject::~OvenObject()
{
}

void OvenObject::Update()
{
}

void OvenObject::Draw()
{
	
}
