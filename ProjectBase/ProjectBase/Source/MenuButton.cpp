#include "MenuButton.h"

MenuButton::MenuButton()
{
	position.x = 150;
	position.y = 200;
	ButtonScale.x = 250;
	ButtonScale.y = 100;
}

MenuButton::~MenuButton()
{
}

void MenuButton::Update()
{
}

void MenuButton::Draw()
{
	float FontSize = 32;
	SetFontSize(32);
	DrawBox(position.x - ButtonScale.x / 2,position.y - ButtonScale.y / 2, position.x + ButtonScale.x / 2, position.y + ButtonScale.y / 2, GetColor(255, 200, 200), TRUE);
	DrawFormatString(FontSize /2+ position.x - ButtonScale.x / 2, position.y-FontSize/2, GetColor(0, 0, 0), "édì¸ÇÍÉÇÅ[Éh");
}
