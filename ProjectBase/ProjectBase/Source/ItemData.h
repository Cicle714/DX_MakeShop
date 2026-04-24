#pragma once
#include "../Library/SceneBase.h"
#include <string>

class ItemData : public SceneBase
{
public:
	ItemData();
	~ItemData();
	void Update() override;
	void Draw() override;
private:

	std::string* ItemDatas;
	int DataNum = 5;
};