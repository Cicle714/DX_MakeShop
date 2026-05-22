#include "BuyArea.h"
#include "Screen.h"

BuyArea::BuyArea()
{
	ObjectSizeX = 128;
	ObjectSizeY = 320;
	position.x = Screen::WIDTH - ObjectSizeX;
	position.y = Screen::HEIGHT - ObjectSizeY;
}

BuyArea::~BuyArea()
{
}

void BuyArea::Update()
{
}

void BuyArea::Draw()
{
	DrawBox(position.x, position.y - ObjectSizeY  / 2, position.x + ObjectSizeX, position.y + ObjectSizeY/2, GetColor(255, 0, 0), FALSE);
}

