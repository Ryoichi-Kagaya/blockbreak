#pragma once
#include "pch.h"
#include "Texture.h"

class BLOCK {
private:
	//座標
	float x, y;

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
	const TCHAR* FileName;
	bool SetSize(IDirect3DTexture9* pTexture);
	bool Load();
	void Draw();

public:
	IDirect3DTexture9* pTexture;
	IDirect3DDevice9* pDevice3D;
	BLOCK(IDirect3DDevice9* pDevice3D, float x, float y);
	~BLOCK();
	float GetX();
	float GetY();
	int GetWidth();
	int GetHeight();
	void SetFlag(bool endflag);
	bool GetFlag();
	void All();

};

