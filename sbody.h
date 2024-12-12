#pragma once
#include "globals.h"


class sbody
{
public:
	sbody();//コンストラクタ
	~sbody();//デストラクタ
	void SetPosition(int x, int y);
	pos GetPosition();
	void SetDir(DIR dir);
	DIR GetDir();
private:
	pos sPos;
	DIR forward;
};

