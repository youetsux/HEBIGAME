#pragma once
#include "sbody.h"
#include <vector>

using std::vector;



class Snake
{
	//sbody��vector�z�� body;
	vector<sbody> body;
	bool isEat;//true, false
public:
	//�R���X�g���N�^
	Snake();
	//�f�X�g���N�^
	~Snake();

	void Init();
	void Update(float delta);
	void Draw(float delta);
};

