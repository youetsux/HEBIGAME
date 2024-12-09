#pragma once
#include "globals.h"


class sbody
{
private:
	pos sPos;
public:
	sbody();//コンストラクタ
	~sbody();//デストラクタ
	void SetPosition(int x, int y);
	pos GetPosition();
};

