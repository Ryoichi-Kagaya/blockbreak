#pragma once
#include "pch.h"

class BLOCK {

private:
	float x, y; //座標
	bool endflag; //ブロックが壊れてるか壊れてないかのフラグ
	void Draw();

public:
	static const int width, height; //縦、横幅
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

