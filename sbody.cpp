#include "sbody.h"

sbody::sbody()
{
    sPos.x = 0;
    sPos.y = 0;
}

sbody::~sbody()
{
    //�������Ȃ���
}

void sbody::SetPosition(int x, int y)
{
    this->sPos.x = x;
    this->sPos.y = y;
}

pos sbody::GetPosition()
{
    return sPos;
}

void sbody::SetDir(DIR dir)
{
    forward = dir;
}

DIR sbody::GetDir()
{
    return forward;
}
