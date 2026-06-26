#include "BuyArea.h"
#include "Screen.h"

BuyArea::BuyArea()
{
	ObjectSizeX = 300;
	ObjectSizeY = 200;
	position.x = Screen::WIDTH - ObjectSizeX;
	position.y = Screen::HEIGHT - ObjectSizeY + 120;
	hImage = LoadGraph("Image/Box.png");
}

BuyArea::~BuyArea()
{
}

void BuyArea::Update()
{
}

void BuyArea::Draw()
{
	DrawExtendGraph(position.x, position.y - ObjectSizeY / 2, position.x + ObjectSizeX, position.y + ObjectSizeY / 2,hImage, TRUE);
	DrawBox(position.x, position.y - ObjectSizeY  / 2, position.x + ObjectSizeX, position.y + ObjectSizeY/2, GetColor(255, 0, 0), FALSE);
}

