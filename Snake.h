#pragma once
#include "sbody.h"
#include <vector>

using std::vector;



class Snake
{
public:
	//�R���X�g���N�^
	Snake();
	//�f�X�g���N�^
	~Snake();

	void Init();
	void Update(float delta);
	void Draw(float delta);
	bool CheckOnBody(pos p);
	void EatFood();
	bool IsAlive() { return isAlive; }//�����Ă�H
	pos GetHeadPosition() { return(body[0].GetPosition()); }
private:
	//sbody��vector�z�� body;
	vector<sbody> body;
	bool isEat;//true, false
	bool isAlive;
};

