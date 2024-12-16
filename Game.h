#pragma once
#include "Snake.h"
#include "Foods.h"

class Game
{
	enum GAMESTATE//ゲームシーケンス（タイトル、プレイ画面、ゲームオーバー）
	{
		TITLE, PLAY, GAMEOVER, MAXSTATE
	};//各状態で、スペースキーを押したら次の状態に移動する
	Snake snake;
	Foods food;
public:
	Game();//コンストラクタ　初期化用関数
	~Game();//デストラクタ   削除用関数
	GAMESTATE stat;
	void Init();
	void Update(float delta);
	//各状態のアップデート関数
	void UpdateTitle(float delta);
	void UpdatePlay(float delta);
	void UpdateGameOver(float delta);
	void Draw(float delta);
	//各状態の描画関数
	void DrawTitle(float delta);
	void DrawPlay(float delta);
	void DrawGameOver(float delta);

	//ステージを描画する関数
	void DrawStage(float delta);
};

