#pragma once
#include "sbody.h"
#include <vector>

using std::vector;

class Snake
{
	//sbody��vector�z�� body;
	vector<sbody> body;
public:
	//�R���X�g���N�^
	Snake();
	~Snake();
	//�f�X�g���N�^
	void Init();
	void Update(float delta);
	void Draw(float delta);
};

