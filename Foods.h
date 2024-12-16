#pragma once
#include "globals.h"

class Foods
{
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
private:
	pos position_;
	bool isEat;
};

