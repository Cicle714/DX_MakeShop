#pragma once
#include "../Library/SceneBase.h"
#include <string>
#include <vector>

class StartFlag : public SceneBase
{
public:
	StartFlag();
	~StartFlag();
	void Update() override;
	void Draw() override;


private:
	int MessageNum;
	std::string* message;
	int messageImage;
};