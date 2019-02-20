#pragma once
#include "pch.h"

class BLOCK {

private:
	IDirect3DDevice9* pDevice3D;
	float x, y; //座標
	bool endflag; //ブロックが壊れてるか壊れてないかのフラグ
	void Draw();

public:
	static const int width, height; //縦、横幅
	BLOCK(IDirect3DDevice9* pDevice3D, float x, float y);
	~BLOCK();
	float GetX();
	float GetY();
	void SetFlag(bool endflag);
	bool GetFlag();
	void All();

};

