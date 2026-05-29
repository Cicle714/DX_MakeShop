
#pragma once
#include "../Library/GameObject.h"
#include "Screen.h"
#include <string>
#include <vector>
#include "GameManager.h"

class Bread : public GameObject
{
public:
	Bread();
	~Bread();
	void Update() override;
	void Draw() override;


	VECTOR position;
	VECTOR centerPosition;

	bool Fire;
	int OvenNum;


private:
	bool Push;

	int ObjectSize;

	int mugi;
	int Bread1;
	int Bread2;

	VECTOR FireObjectPos;

	bool Hold;

	GameManager* GameM;

};