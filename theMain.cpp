#include "DxLib.h"
#include "globals.h"
#include "Input.h"
#include "Game.h"





void DxInit()
{
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText("TITLE");
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(255, 250, 205);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}

	SetDrawScreen(DX_SCREEN_BACK);
}


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	DxInit();
	prevTime = GetNowCount();
	Game game;
	

	game.Init();

	while (true)
	{
		ClearDrawScreen();
		Input::KeyStateUpdate();
		//ここにやりたい処理を書く
		crrTime = GetNowCount();
		float deltaTime = (crrTime - prevTime) / 1000.0;//フレーム間時間（ｓ）
		
		game.Update(deltaTime);
		game.Draw(deltaTime);


		//sbody s[10];
		//s[0].xxx();
		//s[0].pos.x = 10;

		DrawFormatString(20, 50, GetColor(0, 0, 0), "%lf", deltaTime);
		ScreenFlip();
		WaitTimer(16);

		prevTime = crrTime;
		if (ProcessMessage() == -1)
			break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
	}

	DxLib_End();
	return 0;
}

