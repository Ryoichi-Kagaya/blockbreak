#pragma once
#include "pch.h"

class BLOCK {

private:
	IDirect3DDevice9* pDevice3D;
	float x, y; //���W
	bool endflag; //�u���b�N�����Ă邩���ĂȂ����̃t���O
	void Draw();

public:
	static const int width, height; //�c�A����
	BLOCK(IDirect3DDevice9* pDevice3D, float x, float y);
	~BLOCK();
	float GetX();
	float GetY();
	void SetFlag(bool endflag);
	bool GetFlag();
	void All();

};

