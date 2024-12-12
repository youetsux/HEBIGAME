#include <DxLib.h>
#include "Snake.h"
#include "Input.h"

namespace
{
	float sumDelta = 0;
	const float refRate = 0.5f;
}

Snake::Snake()
{
}

Snake::~Snake()
{
}

void Snake::Init()
{
	//body���T������
	for (int i = 0; i < 5; i++)
	{
		sbody b;
		b.SetPosition(10 - i, 5);
		this->body.push_back(b);
	}

}

void Snake::Update(float delta)
{
	DIR inputDir = NONE;
	if (Input::IsKeyDown(KEY_INPUT_UP)) {
		inputDir = UP;
	}
	if (Input::IsKeyDown(KEY_INPUT_LEFT)) {
		inputDir = LEFT;
	}
	if (Input::IsKeyDown(KEY_INPUT_DOWN)) {
		inputDir = DOWN;
	}
	if (Input::IsKeyDown(KEY_INPUT_RIGHT)) {
		inputDir = RIGHT;
	}

	DIR revDir[MAXDIR] = { DOWN, RIGHT, UP, LEFT, NONE };
	pos next[MAXDIR] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0},{0,0} };
	if (sumDelta > refRate)
	{
		sumDelta = 0;
		//���͕����Ɉړ�
		sbody b = body.back();//�P�c��sbody���Ƃ��Ă���

		//���͂��A����body[0]�̕����Ƌt��������Ȃ�������A�ړ�
		//���͂��A����body[0]�̕����Ƌt������������A�X���[
		body.pop_back();//�P�c��������o���ď���
		pos p = body[0].GetPosition();
		b.SetPosition(p.x + next[RIGHT].x, p.y + next[RIGHT].y);
		body.insert(body.begin(), b);

	}
	sumDelta = sumDelta + delta;
}

void Snake::Draw(float delta)
{
	for (int i = 0; i < body.size(); i++)
	{
		pos p = body[i].GetPosition();
		DrawBox(p.x * BOXSIZE, p.y * BOXSIZE,
			(p.x + 1) * BOXSIZE, (p.y + 1) * BOXSIZE,
			GetColor(0, 255, 0), TRUE);
		DrawBox(p.x * BOXSIZE, p.y * BOXSIZE,
			(p.x + 1) * BOXSIZE, (p.y + 1) * BOXSIZE,
			GetColor(0, 0, 0), FALSE);
	}
}
