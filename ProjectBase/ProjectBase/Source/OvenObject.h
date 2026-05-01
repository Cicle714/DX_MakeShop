#pragma once

#include "../Library/SceneBase.h"
#include <string>
#include <vector>

class OvenObject : public SceneBase
{
public:
	OvenObject();
	~OvenObject();
	void Update() override;
	void Draw() override;


private:
	int hImageA;
	int hImageB;
	VECTOR position;
};