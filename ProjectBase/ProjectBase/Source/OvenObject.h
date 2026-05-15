#pragma once

#include "../Library/GameObject.h"
#include "Screen.h"
#include <string>
#include <vector>

class OvenObject : public GameObject
{
public:
	OvenObject();
	~OvenObject();
	void Update() override;
	void Draw() override;

	VECTOR GetP1();
	VECTOR GetP2();


	bool Use;


private:

	bool Push;

	int hImageA;
	int hImageB;
	VECTOR position;
	VECTOR centerPosition;
	int ObjectSize;

	float OvenGage;
	float OvenGageMax;
};