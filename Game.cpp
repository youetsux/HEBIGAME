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

	if (Input::IsKeyDown(KEY_INPUT_SPACE))
	{
		stat = GAMESTATE::GAMEOVER;
	}
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
	DrawString(100, 100, "TITLE", GetColor(0,0,0));
}

void Game::DrawPlay(float delta)
{
	DrawStage(delta);
	snake.Draw(delta);
	DrawString(100, 100, "PLAY", GetColor(0, 0, 0));
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
	for (int j = 0; j < WIN_HEIGHT; j += BOXSIZE) {
		int boxnum = 0;
		if (kigu == true)
			boxnum++;
		for (int i = 0; i < WIN_WIDTH; i+= BOXSIZE)
		{
			if (boxnum % 2) 
				DrawBox(i, j, i + BOXSIZE, j + BOXSIZE, GetColor(230, 200, 240), TRUE);
			else
				DrawBox(i, j, i + BOXSIZE, j + BOXSIZE, GetColor(200, 200, 200), TRUE);
			boxnum++;
		}
		kigu = !kigu;
	}
}
