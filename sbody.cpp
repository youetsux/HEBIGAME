#include "sbody.h"

sbody::sbody()
{
    sPos.x = 0;
    sPos.y = 0;
}

sbody::~sbody()
{
    //何もしないよ
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
