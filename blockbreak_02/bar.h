#pragma once
#include "pch.h"
#include "input.h"
#define SPEED 4

class BAR {
private:
	//x���W�Ay���W
	int x, y;

	//�I���t���O�B�I���Ȃ�true
	bool endflag;

	// 3D�f�o�C�X
	IDirect3DDevice9* pDevice3D;

	void Draw();
	void KeyGet();
	void Destroy();

public:
	static const int width, height; //�c�A����
	Input input;
	BAR(IDirect3DDevice9* pDevice3D);
	~BAR();
	bool All();
	int GetX();
	int GetY();
};
