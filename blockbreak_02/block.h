#pragma once
#include "pch.h"

class BLOCK {
private:
	//���W
	float x, y;

	//�c�A����
	int width, height;

	//�u���b�N�����Ă邩���ĂȂ����̃t���O�B
	bool endflag;

	//�O���t�B�b�N�n���h���B
	//�S�������摜�Ȃ̂ŐÓI�ϐ��ɂ��ċ��L�B
	static int gh;

	//�t�F�[�h�`��p�J�E���g
	int count;


private:
	bool SetSize(IDirect3DTexture9* pTexture);
	bool Load(const TCHAR* FileName);
	void Draw();

public:
	IDirect3DTexture9* pTexture;
	IDirect3DDevice9* pDevice3D;
	BLOCK(IDirect3DDevice9* pDevice3D, float x, float y);
	~BLOCK();
	float GetX();
	float GetY();
	int GetWidth();
	int GetHeight();
	void SetFlag(bool endflag);
	bool GetFlag();
	void All();

};

