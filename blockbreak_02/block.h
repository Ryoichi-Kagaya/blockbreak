#pragma once
#include "pch.h"

class BLOCK {

private:

	//���W
	float x, y;

	//�u���b�N�����Ă邩���ĂȂ����̃t���O�B
	bool endflag;

	//�O���t�B�b�N�n���h���B
	//�S�������摜�Ȃ̂ŐÓI�ϐ��ɂ��ċ��L�B
	static int gh;

	//�t�F�[�h�`��p�J�E���g
	int count;

	void Draw();

public:

	//�c�A����
	static const int width, height;

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

