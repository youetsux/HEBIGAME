#include <DxLib.h>
#include "Snake.h"
#include "Input.h"

namespace
{
	float sumDelta = 0;
	const float refRate = 0.25f;
}

Snake::Snake()
{
	//メンバ変数　初期化
	isEat = false;
}

Snake::~Snake()
{
}

void Snake::Init()
{
	body.clear();
	//bodyを５こつくる
	for (int i = 0; i < 5; i++)
	{	
		sbody b;
		b.SetPosition(10 - i, 5);
		b.SetDir(RIGHT);
		this->body.push_back(b);
	}
	isEat = false;
	isAlive = true;//ここで生きる
}

void Snake::Update(float delta)
{
	//自分のボディとの当たり判定
	pos p = body[0].GetPosition();//頭の位置をゲット
	for (int i = 1; i < body.size(); i++)
	{
		if (p.x == body[i].GetPosition().x && p.y == body[i].GetPosition().y)
		{
			isAlive = false;//ここで死ぬる
		}
	}

	//壁との当たり判定
	//すべての壁kabe.x, kabe.y に対して
	//(p.x,p.y) == (kabe.x, kabe.y)なら ⇒ isAlive = false
	for (int j = 0; j < STAGEH; j++) {
		for (int i = 0; i < STAGEW; i++)
		{
			if (j == 0 || i == 0 || j == STAGEH - 1 || i == STAGEW - 1) {
				if (p.x == i && p.y == j)
				{
					isAlive = false;//ここで死ぬる
				}
			}
		}
	}

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

	//入力が、頭＝body[0]の方向と逆方向じゃなかったら、移動
	//入力が、頭＝body[0]の方向と逆方向だったら、スルー
	if (body[0].GetDir() != revDir[inputDir] && inputDir != NONE)
	{
		body[0].SetDir(inputDir);
	}


	if (sumDelta > refRate)
	{
		sumDelta = 0;
		//ケツからとって
		sbody b = body.back();//ケツのsbodyをとってくる
		if (isEat == false) {
			body.pop_back();//ケツを一個押し出して消す
		}
		else//isEatがtrueの時
		{
			isEat = false;
		}

		//今頭の向いている方向+1のところにケツからとったやつをくっつける
		pos p = body[0].GetPosition();
		DIR dir = body[0].GetDir();
		//next[dir]が次に進む頭の位置
		b.SetPosition(p.x + next[dir].x, p.y + next[dir].y);
		b.SetDir(dir);
		//頭につける
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
	//if (isAlive == false)
	//	DrawFormatString(10, 50, GetColor(255, 0, 0), "Dead");

}

bool Snake::CheckOnBody(pos p)
{
	//for (int i = 0; i < body.size(); i++)
	for(auto itr: body)
	{
		if (itr.GetPosition().x == p.x && itr.GetPosition().y == p.y)
		{
			return true;
		}
	}
	return false;
}

void Snake::EatFood()
{
	isEat = true;
}
