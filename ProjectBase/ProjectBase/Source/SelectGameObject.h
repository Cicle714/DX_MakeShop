#pragma once
#include "../Library/GameObject.h"
#include "Screen.h"
#include <string>
#include <vector>

class SelectGameObject : public GameObject
{
public:
	SelectGameObject();
	~SelectGameObject();
	void Update() override;
	void Draw() override;

	int GetNum(int num) { return num; }
	
private:
	bool Push;

	int ObjectNum;

	int selectNum;

	VECTOR position;
	VECTOR centerPosition;
	int ObjectSize;

	bool Hold;

	int mugi;
	int Bread1;


};