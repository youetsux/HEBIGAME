#pragma once
#include "Snake.h"
#include "Foods.h"

class Game
{
	enum GAMESTATE//�Q�[���V�[�P���X�i�^�C�g���A�v���C��ʁA�Q�[���I�[�o�[�j
	{
		TITLE, PLAY, GAMEOVER, MAXSTATE
	};//�e��ԂŁA�X�y�[�X�L�[���������玟�̏�ԂɈړ�����
	Snake snake;
	Foods food;
public:
	Game();//�R���X�g���N�^�@�������p�֐�
	~Game();//�f�X�g���N�^   �폜�p�֐�
	GAMESTATE stat;
	void Init();
	void Update(float delta);
	//�e��Ԃ̃A�b�v�f�[�g�֐�
	void UpdateTitle(float delta);
	void UpdatePlay(float delta);
	void UpdateGameOver(float delta);
	void Draw(float delta);
	//�e��Ԃ̕`��֐�
	void DrawTitle(float delta);
	void DrawPlay(float delta);
	void DrawGameOver(float delta);

	//�X�e�[�W��`�悷��֐�
	void DrawStage(float delta);
};

