#pragma once

//�f�[�^�Ƃ��Ă����g��Ȃ����A���ڑ���Ŏg��������struct
struct pos
{
	int x;
	int y;
};


namespace
{
	const int WIN_WIDTH = 1024;
	const int WIN_HEIGHT = 768;
	
	const int BOXSIZE = 40;
	
	const int STAGEW = WIN_WIDTH / BOXSIZE;
	const int STAGEH = WIN_HEIGHT / BOXSIZE;
	
	int crrTime;
	int prevTime;
	
	
}