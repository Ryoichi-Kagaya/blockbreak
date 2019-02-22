#include "pch.h"
#include "block.h"
#include "Sprite.h"

const int BLOCK::width = 100; // XXX: 画像変更する場合、どうしよう…
const int BLOCK::height = 28;

BLOCK::BLOCK(IDirect3DDevice9* pDevice3D, float x, float y)
{
	this->pDevice3D = pDevice3D;
	tex.Load(pDevice3D, _T("block.bmp"));
	this->x = x;
	this->y = y;
	endflag = false;
}

BLOCK::~BLOCK()
{
	if (pDevice3D != NULL) pDevice3D->Release();
}

float BLOCK::GetX()
{
	return x;
}
float BLOCK::GetY()
{
	return y;
}

void BLOCK::SetFlag(bool flag)
{
	endflag = flag;
}
bool BLOCK::GetFlag()
{
	return endflag;
}

void BLOCK::Draw()
{
	// スプライト作成
	Sprite sprite;
	sprite.SetWidth(width, height);
	sprite.SetPos(x, y);

	//ブロックが壊れてないときだけ描画
	if (!endflag) {
		sprite.Draw(pDevice3D, tex.pTexture);
	}
	else {
		 // XXX: 透過処理しようと思ったが保留…
	}
}

void BLOCK::All()
{
	Draw();
}
