#pragma once
#include "pch.h"
#define SPEED 4

class BAR {
private:
	//xÀWAyÀW
	int x, y;

	//I¹tOBI¹Èçtrue
	bool endflag;

	void Draw();
	void KeyGet();
	void Destroy();

public:
	static const int width, height; //cA¡
	IDirect3DTexture9* pTexture;
	IDirect3DDevice9* pDevice3D;
	BAR(IDirect3DDevice9* pDevice3D);
	~BAR();
	bool All();
	int GetX();
	int GetY();
};
