#include "pch.h"
#include "bar.h"
#include "Texture.h"
#include "Sprite.h"

const int BAR::width = 100; // XXX: 画像変更する場合、どうしよう…
const int BAR::height = 14;

BAR::BAR(HWND hwnd, IDirect3DDevice9* pDevice3D)
{
	// 3Dデバイスを取り込む
	this->pDevice3D = pDevice3D;

	// インプットを作成
	input = new Input(hwnd);

	//y座標は固定なのでここで設定
	y = 460;

	//最初は真ん中
	x = wWidth / 2;

	//終了フラグは偽にしとく
	endflag = false;

}

void BAR::Draw() {
	// テクスチャ作成
	Texture tex;
	tex.Load(pDevice3D, _T("bar.bmp"));

	// スプライト作成、描画
	Sprite sprite;
	sprite.SetWidth(width, height);
	sprite.SetPos(x, y);
	sprite.Draw(pDevice3D, tex.pTexture);
}

void BAR::KeyGet()
{
	if (input->CheckKey(DIK_LEFT) == true) {
		//左に移動。
		x -= SPEED;
	}
	if (input->CheckKey(DIK_RIGHT) == true) {
		//右に移動
		x += SPEED;
	}
	if (input->CheckKey(DIK_ESCAPE) == true) {
		//エスケープキーが押されていれば終了フラグをtrueにする
		endflag = true;
	}

	//画面のはみ出し処理
	if (x < width / 2) x = width / 2;
	if (x > wWidth - width / 2) x = wWidth - width / 2;

}

int BAR::GetX()
{
	return x;
}

int BAR::GetY()
{
	return y;
}

bool BAR::All()
{
	//キー処理
	KeyGet();

	//描画処理
	Draw();

	//終了フラグを返す。
	return endflag;
}

void BAR::Destroy() {


}

BAR::~BAR()
{
	if (pDevice3D != NULL) pDevice3D->Release();
	delete input;
	Destroy();

}

