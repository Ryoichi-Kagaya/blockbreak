#include "pch.h"
#include "block.h"
#include "Texture.h"
#include "Sprite.h"

const TCHAR* FileName = _T("block.bmp");
int BLOCK::gh = -1;

BLOCK::BLOCK(IDirect3DDevice9* pDevice3D, float x, float y)
{
	//最初しか読み込まない。
	//if (gh == -1) Load();

	//GetGraphSize(gh, &width, &height);
	this->pDevice3D = pDevice3D;

	endflag = false;

	this->x = x;
	this->y = y;
	width = 100;
	height = 28;

	count = 0;

}

BLOCK::~BLOCK() {
	if (pTexture != NULL) pTexture->Release();
}

bool BLOCK::SetSize(IDirect3DTexture9* pTexture) // XXX: 画像サイズの自動取得が上手くいかない。これも保留。クラス内でテクスチャ作れないのか？
{
	// テクスチャサイズの取得
	D3DSURFACE_DESC desc;
	if (FAILED(pTexture->GetLevelDesc(0, &desc))) return false;

	width = desc.Width;
	height = desc.Height;

	return true;
}

bool BLOCK::Load() // XXX: ここで画像の読み込みが上手くいっていない
{
	if (FAILED(D3DXCreateTextureFromFile(pDevice3D, FileName, &pTexture))) {
		return false; // 画像読み込み失敗（ファイルがない可能性あり）
	}
	else {
		return true; // 画像読み込み成功
	}
}

float BLOCK::GetX()
{
	return x;
}
float BLOCK::GetY()
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

	/*
	Sprite sprite;
	sprite.SetWidth(100, 28);
	sprite.SetPos(x, y);
	sprite.Draw(pDevice3D, pTexture);
	*/

	// XXX: Textureクラスを呼び出したら上手くいった。釈然としないが、とりあえずは動くものを作る
	// XXX: 外からファイル名持ってきたら失敗
	Texture tex;
	tex.Load(pDevice3D, _T("block.bmp"));
	Sprite sprite;
	sprite.SetWidth(width, height);
	sprite.SetPos(x, y);
	sprite.Draw(pDevice3D, tex.pTexture);
}

void BLOCK::All()
{
	Draw();
}
