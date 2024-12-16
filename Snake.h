#pragma once
#include "sbody.h"
#include <vector>

using std::vector;



class Snake
{
	//sbodyのvector配列 body;
	vector<sbody> body;
	bool isEat;//true, false
public:
	//コンストラクタ
	Snake();
	//デストラクタ
	~Snake();

	void Init();
	void Update(float delta);
	void Draw(float delta);
};

