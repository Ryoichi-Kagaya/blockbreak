#pragma once
#include "pch.h"

class BLOCK {

private:

	//座標
	float x, y;

	//ブロックが壊れてるか壊れてないかのフラグ。
	bool endflag;

	//グラフィックハンドル。
	//全部同じ画像なので静的変数にして共有。
	static int gh;

	//フェード描画用カウント
	int count;

	void Draw();

public:

	//縦、横幅
	static const int width, height;

	IDirect3DTexture9* pTexture;
	IDirect3DDevice9* pDevice3D;
	BLOCK(IDirect3DDevice9* pDevice3D, float x, float y);
	~BLOCK();
	float GetX();
	float GetY();
	void SetFlag(bool endflag);
	bool GetFlag();
	void All();

};

