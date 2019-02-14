#include "pch.h"
#include "block.h"
#include "Sprite.h"


int BLOCK::gh = -1;

BLOCK::BLOCK(IDirect3DDevice9* pDevice3D, float x, float y)
{
	//最初しか読み込まない。
	//if (gh == -1) Load();
	Load();

	//GetGraphSize(gh, &width, &height);
	this->pDevice3D = pDevice3D;

	endflag = false;

	this->x = x;
	this->y = y;

	count = 0;

}

BLOCK::~BLOCK() {
	if (pTexture != NULL) pTexture->Release();
}

bool BLOCK::Load() // XXX: ここで画像の読み込みが上手くいっていない
{
	const TCHAR* FileName;
	FileName = TEXT("block.bmp");

	if (FAILED(D3DXCreateTextureFromFile(pDevice3D, FileName, &pTexture))) {
		return false; // 画像読み込み失敗（ファイルがない可能性あり）
	}
	else {
		return true; // 画像読み込み成功
	}
}

int BLOCK::GetX()
{
	return x;
}
int BLOCK::GetY()
{
	return y;
}
int BLOCK::GetWidth()
{
	return width;
}
int BLOCK::GetHeight()
{
	return height;
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
	//ブロックが壊れてないときだけ描画
	/* if (!endflag) {
		DrawGraph(x - width / 2, y - height / 2, gh, FALSE);
	}
	else {
		if (count < 40) {
			//透過度を指定
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, (255 / 40)*(40 - count));
			//描画
			DrawGraph(x - width / 2, y - height / 2, gh, FALSE);
			//設定を戻す
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			++count;
		}
	}*/

	Sprite sprite;
	sprite.SetWidth(100, 28);
	sprite.SetPos(x, y);
	sprite.Draw(pDevice3D, pTexture);
}

void BLOCK::All()
{
	Draw();
}
