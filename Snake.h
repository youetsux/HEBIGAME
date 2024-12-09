#pragma once
#include "sbody.h"
#include <vector>

using std::vector;

class Snake
{
	//sbodyのvector配列 body;
	vector<sbody> body;
public:
	//コンストラクタ
	Snake();
	~Snake();
	//デストラクタ
	void Init();
	void Update(float delta);
	void Draw(float delta);
};

