#pragma once
#include "sbody.h"
#include <vector>

using std::vector;



class Snake
{
public:
	//コンストラクタ
	Snake();
	//デストラクタ
	~Snake();

	void Init();
	void Update(float delta);
	void Draw(float delta);
	bool CheckOnBody(pos p);
	void EatFood();
	pos GetHeadPosition() { return(body[0].GetPosition()); }
private:
	//sbodyのvector配列 body;
	vector<sbody> body;
	bool isEat;//true, false
};

