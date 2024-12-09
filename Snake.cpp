#include <DxLib.h>
#include "Snake.h"

Snake::Snake()
{
}

Snake::~Snake()
{
}

void Snake::Init()
{
	//body‚ð‚T‚±‚Â‚­‚é
	for (int i = 0; i < 5; i++)
	{
		sbody b;
		b.SetPosition(10 - i, 5);
		this->body.push_back(b);
	}

}

void Snake::Update(float delta)
{
}

void Snake::Draw(float delta)
{
	for (int i = 0; i < body.size(); i++)
	{
		pos p = body[i].GetPosition();
		DrawBox(p.x*BOXSIZE, p.y * BOXSIZE, p.x * BOXSIZE + BOXSIZE, p.y * BOXSIZE + BOXSIZE, GetColor(0, 255, 0), TRUE);
		DrawBox(p.x * BOXSIZE, p.y * BOXSIZE, p.x * BOXSIZE + BOXSIZE, p.y * BOXSIZE + BOXSIZE, GetColor(0, 0, 0), FALSE);
	}
}
