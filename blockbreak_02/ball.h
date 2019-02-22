#pragma once
#include "pch.h"
#include "Texture.h"
#define WIDTH 640
#define HEIGHT 480

class BALL {
	private:
		//x���W�Ay���W
		int x, y;

		//x��y�̈ړ���
		int dx, dy;

		//�摜�̉��A�c��
		int width, height;

		//�Q�[���[�I�[�o�[�t���O
		bool endflag;

		//����炷���ǂ����̃t���O
		bool soundflag;

		// 3D�f�o�C�X
		IDirect3DDevice9* pDevice3D;

		// �e�N�X�`���[
		Texture tex;

		void Draw();
		void Destroy();
		void Move();

	public:
		BALL(IDirect3DDevice9* pDevice3D);
		~BALL();
		bool All();
		int GetX();
		int GetY();
		int GetWidth();
		int GetHeight();
		void SetDX(int);
		void SetDY(int);
		int GetDX();
		int GetDY();
		bool GetSoundflag();
};

