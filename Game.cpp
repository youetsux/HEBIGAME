#include <DxLib.h>
#include "globals.h"
#include "Game.h"
#include "Input.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
	stat = GAMESTATE::TITLE;//かっこいい
	snake.Init();
	food.Init();
	pos p = food.GetRandPos();
	food.SetPosition(p.x, p.y);
	while(snake.CheckOnBody(p))
	{
		p = food.GetRandPos();
		food.SetPosition(p.x, p.y);
	}
	
}

void Game::Update(float delta)//毎フレームのデータ更新処理
{
	if (stat == GAMESTATE::TITLE)
	{
		UpdateTitle(delta);
	}
	else if (stat == GAMESTATE::PLAY)
	{
		UpdatePlay(delta);
	}
	else if (stat == GAMESTATE::GAMEOVER)
	{
		UpdateGameOver(delta);
	}
}

void Game::UpdateTitle(float delta)
{
	if (Input::IsKeyDown(KEY_INPUT_SPACE))
	{
		stat = GAMESTATE::PLAY;
	}
}

void Game::UpdatePlay(float delta)
{

	snake.Update(delta);
	pos fpos = food.GetPosition();
	pos hpos = snake.GetHeadPosition();
	if (fpos.x == hpos.x && fpos.y == hpos.y)
	{
		snake.EatFood();
		food.EatFood();
	}
	//if (Input::IsKeyDown(KEY_INPUT_SPACE))
	//{
	//	stat = GAMESTATE::GAMEOVER;
	//}
}

void Game::UpdateGameOver(float delta)
{
	if (Input::IsKeyDown(KEY_INPUT_SPACE))
	{
		stat = GAMESTATE::TITLE;
	}
}

void Game::Draw(float delta)
{
	if (stat == GAMESTATE::TITLE)
	{
		DrawTitle(delta);
	}
	else if (stat == GAMESTATE::PLAY)
	{
		DrawPlay(delta);
	}
	else if (stat == GAMESTATE::GAMEOVER)
	{
		DrawGameOver(delta);
	}
}

void Game::DrawTitle(float delta)
{
	DrawString(100, 100, "TITLE", GetColor(0, 0, 0));
}

void Game::DrawPlay(float delta)
{
	DrawStage(delta);//ステージの描画
	snake.Draw(delta);//ヘビの描画
	food.Draw(delta);//餌の描画
	//DrawString(100, 100, "PLAY", GetColor(0, 0, 0));
}

void Game::DrawGameOver(float delta)
{
	DrawString(100, 100, "GAMEOVER", GetColor(0, 0, 0));
}

//const int WIN_WIDTH = 1024;
//const int WIN_HEIGHT = 768;
//const int BOXSIZE = 20;
void Game::DrawStage(float delta)
{
	bool kigu = true;
	//チェッカーボード模様を描いてみよう！
	for (int j = 0; j < STAGEH; j++) {
		int boxnum = 0;
		if (kigu == true)
			boxnum++;
		for (int i = 0; i < STAGEW; i++)
		{
			if (boxnum % 2)
				DrawBox(i * BOXSIZE, j * BOXSIZE,
					   (i + 1) * BOXSIZE, (j + 1) * BOXSIZE,
					   GetColor(230, 200, 240), TRUE);
			else
				DrawBox(i * BOXSIZE, j * BOXSIZE,
					   (i + 1) * BOXSIZE, (j + 1) * BOXSIZE,
					   GetColor(200, 200, 200), TRUE);
			boxnum++;
		}
		kigu = !kigu;
	}
}
