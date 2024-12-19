#include "Foods.h"
#include <DxLib.h>

Foods::Foods()
    :position_({0, 0}), isEat(false)
{
}

Foods::~Foods()
{
}

void Foods::Init()
{
    position_ = { 0,0 };
    isEat = false;
}

void Foods::Update(float delta)
{
}

void Foods::Draw(float delta)
{
    DrawBox(position_.x * BOXSIZE, position_.y * BOXSIZE,
        (position_.x + 1) * BOXSIZE, (position_.y + 1) * BOXSIZE,
        GetColor(217,51,63), TRUE);
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
    int rx = GetRand(STAGEW - 1);
    int ry = GetRand(STAGEH - 1);
    pos result = { rx, ry };
    return result;
}

void Foods::PutFood()
{
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
