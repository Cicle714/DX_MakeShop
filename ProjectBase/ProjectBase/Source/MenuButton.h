
#pragma once
#include "../Library/GameObject.h"
#include "Screen.h"
#include <string>
#include <vector>
#include "GameManager.h"

class MenuButton : public GameObject
{
public:
	MenuButton();
	~MenuButton();
	void Update() override;
	void Draw() override;


	VECTOR position;
	VECTOR centerPosition;

	bool Fire;
	int OvenNum;


private:
	bool Push;

	int ButtonSize;

	VECTOR ButtonScale;
	

	GameManager* GameM;

};