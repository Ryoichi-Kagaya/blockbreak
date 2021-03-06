#include "pch.h"
#include "control.h"

CONTROL::CONTROL(HWND hwnd, IDirect3DDevice9* pDevice3)
{
	//バーとボールのインスタンスを生成
	bar = new BAR(hwnd, pDevice3);
	ball = new BALL(pDevice3);

	boundflag = false;
	demolishflag = false;

	//バーの幅と高さ
	bdwidth = bar->width;
	bdheight = bar->height;

	//ボールの幅と高さ
	blwidth = ball->GetWidth();
	blheight = ball->GetHeight();

	//音声ファイル読み込み。
	//bh = LoadSoundMem("bound.mp3");
	//dh = LoadSoundMem("demolish.mp3");
	
	// ブロック配置用の変数
	// XXX: もうちょい変数減らしたい
	int bkCol = 5;
	int bkRow = 3;
	int bkMargin = 10;

	// ブロックを配置
	for (int i = 0; i < BK_NUM; ++i) {
		block[i] = new BLOCK(pDevice3,
			(block[i]->width + bkMargin) * (i % bkCol) + (block[i]->width / 2 + bkMargin),
			(block[i]->height + bkMargin) * (i % bkRow) + (block[i]->height / 2 + bkMargin));
	}

	bkwidth = block[0]->width;
	bkheight = block[0]->height;
}

CONTROL::~CONTROL()
{
	delete bar;
	delete ball;

	for (int i = 0; i < BK_NUM; ++i) {
		delete block[i];
	}
}

void CONTROL::HitCheckBallAndBar()
{
	//最初はフラグをfalseにしとく。
	boundflag = false;

	//ボールクラス内での音フラグをセット
	boundflag = ball->GetSoundflag();

	//バーの座標取得
	bdx = bar->GetX();
	bdy = bar->GetY();

	//ボールの座標取得
	blx = ball->GetX();
	bly = ball->GetY();

	//ボールとバーの高さの半分を足したものよりも
	//バーの中心とボールの中心の距離の絶対値の方が小さかったら当たり
	//その距離より大きいやつは除外
	if (abs(bdx - blx) < (blwidth / 2 + bdwidth / 2) && 
		abs(bdy - bly) < (blheight / 2 + bdheight / 2)) 
	{
		//Yを跳ね返すだけ
		ball->SetDY(ball->GetDY()*-1);
		//バウンド音フラグを立てる。
		boundflag = true;
	}
}

void CONTROL::HitCheckBallAndBlock()
{
	//破壊音フラグ
	demolishflag = false;

	//ボールの座標取得
	blx = ball->GetX();
	bly = ball->GetY();

	//ブロック全てをループ
	for (int i = 0; i < BK_NUM; ++i) {
		//壊れてない奴だけ対象
		if (!block[i]->GetFlag()) 
		{
			bkx = block[i]->GetX();
			bky = block[i]->GetY();

			if (abs(blx-bkx) < (blwidth/2 + bkwidth/2) &&
				abs(bly - bky) < (blheight / 2 + bkheight / 2))
			{
				//フラグをオフに
				block[i]->SetFlag(true);

				//破壊音フラグを立てる
				demolishflag = true;

				//ボールはただ跳ね返すだけ
				// XXX: 反射の仕方も考えたい
				ball->SetDX(ball->GetDX()*-1);
				ball->SetDY(ball->GetDY()*-1);
			}
		}
	}
}

void CONTROL::SoundPlay()
{
	/*
	if (boundflag) {

		PlaySoundMem(bh, DX_PLAYTYPE_BACK);
	}

	if (demolishflag) {
		PlaySoundMem(dh, DX_PLAYTYPE_BACK);
	}
	*/
}

bool CONTROL::All()
{
	bool back = true;

	for (int i = 0; i < BK_NUM; ++i) {
		block[i]->All();
	}

	//バーの処理
	bar->All();

	//ボールの動き
	back = ball->All();

	//ボールとバーの当たり判定
	HitCheckBallAndBar();

	//ボールとブロックの当たり判定
	HitCheckBallAndBlock();

	//音再生
	SoundPlay();

	return back;
}

