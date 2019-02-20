#pragma once
#include "pch.h"
#include "input.h"
#define SPEED 4
#define wWidth 640

class BAR {
private:
	//x座標、y座標
	int x, y;

	//終了フラグ。終了ならtrue
	bool endflag;

	// 3Dデバイス
	IDirect3DDevice9* pDevice3D;

	// インプット
	Input* input;
	
	void Draw();
	void KeyGet();
	void Destroy();

public:
	static const int width, height; //縦、横幅
	BAR(HWND hwnd, IDirect3DDevice9* pDevice3D);
	~BAR();
	bool All();
	int GetX();
	int GetY();
};
