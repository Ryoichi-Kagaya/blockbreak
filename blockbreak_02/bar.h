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

	// �C���v�b�g
	Input* input;
	
	void Draw();
	void KeyGet();
	void Destroy();

public:
	static const int width, height; //�c�A����
	BAR(IDirect3DDevice9* pDevice3D, HWND hwnd);
	~BAR();
	bool All();
	int GetX();
	int GetY();
};
