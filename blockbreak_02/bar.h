#pragma once
#include "pch.h"
#define SPEED 4

class BAR {
private:
	//x���W�Ay���W
	int x, y;

	//�I���t���O�B�I���Ȃ�true
	bool endflag;

	void Draw();
	void KeyGet();
	void Destroy();

public:
	static const int width, height; //�c�A����
	IDirect3DTexture9* pTexture;
	IDirect3DDevice9* pDevice3D;
	BAR(IDirect3DDevice9* pDevice3D);
	~BAR();
	bool All();
	int GetX();
	int GetY();
};
