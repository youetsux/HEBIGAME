#pragma once

//データとしてしか使わないし、直接代入で使いたい＝struct
struct pos
{
	int x;
	int y;
};

enum DIR
{
	UP, LEFT, DOWN, RIGHT, NONE, MAXDIR
};

namespace
{
	const int WIN_WIDTH = 1024;
	const int WIN_HEIGHT = 768;
	
	const int BOXSIZE = 40;
	
	const int STAGEW = WIN_WIDTH / BOXSIZE -2;
	const int STAGEH = WIN_HEIGHT / BOXSIZE - 3;
	
	int crrTime;
	int prevTime;
	
	const int MGN_WIDTH = 100;
	const int MGN_HEIGHT = 50;
}