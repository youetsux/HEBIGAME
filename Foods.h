#pragma once
#include "globals.h"
#include <vector>

class Foods
{
	enum FOOD_TYPE
	{
		APPLE,
		STRAWBERRY,
		BANANA,
		MELON,
		GRAPE,
		MAX_FLUITS
	};
public:
	Foods();
	~Foods();
	void Init();
	void Update(float delta);
	void Draw(float delta);
	void SetPosition(int x, int y);
	pos  GetPosition();
	pos	 GetRandPos();
	void PutFood();
	void EatFood();
	bool IsEat();
	FOOD_TYPE foodType;
	int color;
private:
	std::vector<int> foodColor;//êHÇ◊ï®ÇªÇÍÇºÇÍÇÃêF
	pos position_;
	bool isEat;
};

