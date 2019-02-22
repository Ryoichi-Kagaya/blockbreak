#pragma once
#include "pch.h"
#include "Texture.h"
#include "input.h"
#define SPEED 4
#define wWidth 640

class BAR {
	private:
		//x���W�Ay���W
		int x, y;

		//�I���t���O�B�I���Ȃ�true
		bool endflag;

		// 3D�f�o�C�X
		IDirect3DDevice9* pDevice3D;

		// �e�N�X�`���[
		Texture tex;

		// �C���v�b�g
		Input* input;
	
		void Draw();
		void KeyGet();
		void Destroy();

	public:
		static const int width, height; //�c�A����
		BAR(HWND hwnd, IDirect3DDevice9* pDevice3D);
		~BAR();
		bool All();
		int GetX();
		int GetY();
};
