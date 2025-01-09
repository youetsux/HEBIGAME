#include "Foods.h"
#include <DxLib.h>

Foods::Foods()
    :position_({0, 0}), isEat(false)
{
    foodColor.push_back(GetColor(217, 51, 63));//りんご
	foodColor.push_back(GetColor(255, 0, 0));//いちご
	foodColor.push_back(GetColor(255, 255, 0));//バナナ
	foodColor.push_back(GetColor(0, 255, 0));//メロン
	foodColor.push_back(GetColor(255, 0, 255));//ぶどう
	//foodType = APPLE;
	//color = foodColor[foodType];
}

Foods::~Foods()
{
}

void Foods::Init()
{
    position_ = { 0,0 };
    foodType = (FOOD_TYPE)GetRand(MAX_FLUITS - 1);
    color = foodColor[foodType];
    isEat = false;
}

void Foods::Update(float delta)
{
}

void Foods::Draw(float delta)
{
    if (isEat)
        return;//早期リターン

    DrawBox(MGN_WIDTH + position_.x * BOXSIZE, MGN_HEIGHT + position_.y * BOXSIZE,
        MGN_WIDTH + (position_.x + 1) * BOXSIZE, MGN_HEIGHT + (position_.y + 1) * BOXSIZE,
           color, TRUE);
}

void Foods::SetPosition(int x, int y)
{
    position_ = { x, y };
}

pos Foods::GetPosition()
{
    return position_;
}

pos Foods::GetRandPos()
{
    int rx = GetRand(STAGEW - 3) + 1;
    int ry = GetRand(STAGEH - 3) + 1;
    pos result = { rx, ry };
    return result;
}

void Foods::PutFood()
{
    foodType = (FOOD_TYPE)GetRand(MAX_FLUITS - 1);
    color = foodColor[foodType];
    isEat = false;
}

void Foods::EatFood()
{
    isEat = true;
}

bool Foods::IsEat()
{
    return isEat;
}
