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
	stat = GAMESTATE::TITLE;//����������
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

void Game::Update(float delta)//���t���[���̃f�[�^�X�V����
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
	if (snake.IsAlive() == false) {
		stat = GAMESTATE::GAMEOVER;
		return;
	}
	snake.Update(delta);
	//�a��H�ׂ鏈��
	pos fpos = food.GetPosition();
	pos hpos = snake.GetHeadPosition();
	if (fpos.x == hpos.x && fpos.y == hpos.y)
	{
		snake.EatFood();
		food.EatFood();
	}

	//�a���H�ׂ�ꂽ�ゾ������i�a�̃��X�|�[���j
	if (food.IsEat() == true)
	{
		//food.Init();
		pos p = food.GetRandPos();
		food.SetPosition(p.x, p.y);
		while (snake.CheckOnBody(p))
		{
			p = food.GetRandPos();
			food.SetPosition(p.x, p.y);
		}
		food.PutFood();//�a���X�^���o�C�iisEat��false�ɂ��Ă邾���j
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
		Init();
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
	DrawStage(delta);//�X�e�[�W�̕`��
	snake.Draw(delta);//�w�r�̕`��
	food.Draw(delta);//�a�̕`��
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
	//�`�F�b�J�[�{�[�h�͗l��`���Ă݂悤�I
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
	DrawWall(delta);
}

void Game::DrawWall(float delta)
{
//R:170�AG : 092�AB : 063�ŕǂ�`���I
	for (int j = 0; j < STAGEH; j++) {
		for (int i = 0; i < STAGEW; i++)
		{
			if (j == 0 || i == 0 || j == STAGEH-1 || i == STAGEW -1) {
				DrawBox(i * BOXSIZE, j * BOXSIZE,
					(i + 1) * BOXSIZE, (j + 1) * BOXSIZE,
					GetColor(170, 92, 63), TRUE);
				DrawBox(i * BOXSIZE, j * BOXSIZE,
					(i + 1) * BOXSIZE, (j + 1) * BOXSIZE,
					GetColor(0, 0, 0), FALSE);
			}
		}
	}
}
