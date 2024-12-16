#include "sbody.h"

sbody::sbody()
{
    sPos.x = 0;
    sPos.y = 0;
}

sbody::~sbody()
{
    //‰½‚à‚µ‚È‚¢‚æ
}

void sbody::SetPosition(int x, int y)
{
    sPos.x = x;
    sPos.y = y;
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
