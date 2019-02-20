#pragma once
#include "pch.h"
#include "input.h"
#define SPEED 4

class BAR {
private:
	//x座標、y座標
	int x, y;

	//終了フラグ。終了ならtrue
	bool endflag;

	// 3Dデバイス
	IDirect3DDevice9* pDevice3D;

	void Draw();
	void KeyGet();
	void Destroy();

public:
	static const int width, height; //縦、横幅
	Input input;
	BAR(IDirect3DDevice9* pDevice3D);
	~BAR();
	bool All();
	int GetX();
	int GetY();
};
