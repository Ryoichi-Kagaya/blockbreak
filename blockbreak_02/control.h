#pragma once
#include "pch.h"
#include "bar.h"
#include "ball.h"
#include "block.h"
#define BK_NUM 15

class CONTROL {
private:

	//�o�[�N���X�̃|�C���^
	BAR *bar;

	//�{�[���N���X�̃|�C���^
	BALL *ball;

	//�u���b�N�̌��A�u���b�N�N���X�̃|�C���^
	BLOCK* block[BK_NUM];

	//�{�[���ƃo�[�ƃu���b�N�̍��W
	int bdx, bdy, blx, bly, bkx, bky;

	//�{�[���ƃo�[�ƃu���b�N�̉摜�̕��ƍ���
	int bdwidth, bdheight, blwidth, blheight, bkwidth, bkheight;

	//�o�E���h���ƂԂ��艹�̃t���O
	bool boundflag, demolishflag;

	//�o�E���h���ƂԂ��艹�̃T�E���h�n���h��
	int bh, dh;

	void HitCheckBallAndBar();
	void HitCheckBallAndBlock();
	void SoundPlay();

public:
	bool All();
	CONTROL(HWND hwnd, IDirect3DDevice9* pDevice3);
	~CONTROL();
};

