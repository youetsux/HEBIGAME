#pragma once
#include "globals.h"


class sbody
{
private:
	pos sPos;
public:
	sbody();//�R���X�g���N�^
	~sbody();//�f�X�g���N�^
	void SetPosition(int x, int y);
	pos GetPosition();
};

