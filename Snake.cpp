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
	//�����o�ϐ��@������
	isEat = false;
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
		b.SetDir(RIGHT);
		this->body.push_back(b);
	}
	isEat = false;
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

	if (Input::IsKeyDown(KEY_INPUT_SPACE))
	{
		//if (isEat == false)
			isEat = true;
	}
	DIR revDir[MAXDIR] = { DOWN, RIGHT, UP, LEFT, NONE };
	pos next[MAXDIR] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0}, {0, 0} };

	//���͂��A����body[0]�̕����Ƌt��������Ȃ�������A�ړ�
	//���͂��A����body[0]�̕����Ƌt������������A�X���[
	if (body[0].GetDir() != revDir[inputDir] && inputDir != NONE)
	{
		body[0].SetDir(inputDir);
	}


	if (sumDelta > refRate)
	{
		sumDelta = 0;
		//�P�c����Ƃ���
		sbody b = body.back();//�P�c��sbody���Ƃ��Ă���
		if (isEat == false) {
			body.pop_back();//�P�c��������o���ď���
		}
		else//isEat��true�̎�
		{
			isEat = false;
		}

		//�����̌����Ă������+1�̂Ƃ���ɃP�c����Ƃ��������������
		pos p = body[0].GetPosition();
		DIR dir = body[0].GetDir();
		//next[dir]�����ɐi�ޓ��̈ʒu
		b.SetPosition(p.x + next[dir].x, p.y + next[dir].y);
		b.SetDir(dir);
		//���ɂ���
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
