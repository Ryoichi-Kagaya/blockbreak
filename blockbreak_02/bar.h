#pragma once
#include "pch.h"
#define SPEED 4

class BAR {
private:
	//x座標、y座標
	int x, y;

	//終了フラグ。終了ならtrue
	bool endflag;

	void Draw();
	void KeyGet();
	void Destroy();

public:
	static const int width, height; //縦、横幅
	IDirect3DTexture9* pTexture;
	IDirect3DDevice9* pDevice3D;
	BAR(IDirect3DDevice9* pDevice3D);
	~BAR();
	bool All();
	int GetX();
	int GetY();
};
