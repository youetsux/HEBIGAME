#pragma once
#include "globals.h"


class sbody
{
public:
	sbody();//�R���X�g���N�^
	~sbody();//�f�X�g���N�^
	void SetPosition(int x, int y);
	pos GetPosition();
	void SetDir(DIR dir);
	DIR GetDir();
private:
	pos sPos;
	DIR forward;
};

