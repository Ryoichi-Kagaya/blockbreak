#include "pch.h"
#include "ball.h"
#include "Sprite.h"

BALL::BALL(IDirect3DDevice9* pDevice3D)
{
	this->pDevice3D = pDevice3D;
	tex.Load(pDevice3D, _T("ball.bmp"));
	width = 18;
	height = 18;

	//y座標は固定なのでここで設定
	y = 400;

	//最初は真ん中
	x = WIDTH / 2;

	//最初の係数
	dx = 3;
	dy = -3;

	endflag = false;
	soundflag = false;
}

void BALL::Draw() 
{
	// スプライト作成、描画
	Sprite sprite;
	sprite.SetWidth(width, height);
	sprite.SetPos(x, y);
	sprite.Draw(pDevice3D, tex.pTexture);
}

void BALL::Move() 
{
	//まず音はOFFにしとく
	soundflag = false;

	//移動量を加算
	x += dx;
	y += dy;

	//画面はみ出し処理
	if (x < width / 2)
	{
		x = width / 2;
		dx *= -1;
		//当たったのでサウンドフラグを立てる
		soundflag = true;
	}

	if (x > WIDTH - width / 2) 
	{
		x = WIDTH - width / 2;
		dx *= -1;
		//当たったのでサウンドフラグを立てる
		soundflag = true;
	}

	if (y < height / 2)
	{
		y = height / 2;
		dy *= -1;
		//当たったのでサウンドフラグを立てる
		soundflag = true;
	}

	//下にはみ出たらゲームオーバー
	if (y > HEIGHT)
	{
		endflag = true;
	}
}

int BALL::GetX()
{
	return x;
}

int BALL::GetY()
{
	return y;
}

void BALL::SetDX(int x)
{
	dx = x;
}

void BALL::SetDY(int y)
{
	dy = y;
}

int BALL::GetDX()
{
	return dx;
}

int BALL::GetDY()
{
	return dy;
}

int BALL::GetWidth()
{
	return width;
}

int BALL::GetHeight()
{
	return height;
}

bool BALL::GetSoundflag()
{
	return soundflag;
}

bool BALL::All()
{
	Move();
	Draw();
	return endflag;
}

void BALL::Destroy() {

}

BALL::~BALL()
{
	if (pDevice3D != NULL) pDevice3D->Release();
	Destroy();
}

