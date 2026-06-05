#pragma once
#include "../Library/GameObject.h"
#include "Screen.h"
#include <string>
#include <vector>

class BuyArea : public GameObject
{
public:
	BuyArea();
	~BuyArea();
	void Update() override;
	void Draw() override;


	VECTOR position;
	VECTOR centerPosition;

	int ObjectSizeX;
	int ObjectSizeY;

	VECTOR GetSize1() { return VGet(position.x, position.y - ObjectSizeY/2, 0); }
	VECTOR GetSize2() { return VGet(position.x + ObjectSizeX, position.y + ObjectSizeY / 2, 0); }


private:
};