#include "BootScene.h"
#include "../Library/SceneManager.h"
#include "DebugScreen.h"

BootScene::BootScene()
{
	DebugScreen* ds = Instantiate<DebugScreen>();
}

BootScene::~BootScene()
{
}

void BootScene::Update()
{
	SceneManager::ChangeScene("TitleScene"); // ‹N“®‚ªI‚í‚Á‚½‚çTitle‚ğ•\¦
}

void BootScene::Draw()
{
}
