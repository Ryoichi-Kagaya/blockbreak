#include "pch.h"
#include "block.h"
#include "Texture.h"
#include "Sprite.h"

int BLOCK::gh = -1;
const int BLOCK::width = 100; // XXX: 画像変更する場合、どうしよう…
const int BLOCK::height = 28;

BLOCK::BLOCK(IDirect3DDevice9* pDevice3D, float x, float y)
{
	//最初しか読み込まない。
	//if (gh == -1) Load();

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

	// XXX: Textureクラスを呼び出したら上手くいった。釈然としないが、とりあえずは動くものを作る
	// XXX: 外からファイル名持ってきたら失敗
	//const TCHAR* FileName = _T("block.bmp");
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
