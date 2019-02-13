#pragma once
#include "pch.h"


class BLOCK {
private:
	//座標
	int x, y;

	//縦、横幅
	int width, height;

	//ブロックが壊れてるか壊れてないかのフラグ。
	bool endflag;

	//グラフィックハンドル。
	//全部同じ画像なので静的変数にして共有。
	static int gh;

	//フェード描画用カウント
	int count;


private:
	bool Load();
	void Draw();

public:
	IDirect3DTexture9* pTexture;
	IDirect3DDevice9* pDevice3D;

	BLOCK(IDirect3DDevice9* pDevice3D, int x, int y);
	~BLOCK();
	
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
	void SetFlag(bool endflag);
	bool GetFlag();
	void All();

};

