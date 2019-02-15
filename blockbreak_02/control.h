#pragma once
#include "pch.h"
//#include "bar.h"
//#include "ball.h"
#include "block.h"

class CONTROL {
private:

	//�o�[�N���X�̃|�C���^
	//BAR *bar;

	//�{�[���N���X�̃|�C���^
	//BALL *ball;

	//�u���b�N�̌��A�u���b�N�N���X�̃|�C���^
	int bkNum = 15; // XXX: �����l����Ƃ��Ȃ��ƁA�G���[�����킢
	BLOCK* block[100];

	//�{�[���ƃo�[�ƃu���b�N�̍��W
	int bdx, bdy, blx, bly, bkx, bky;


	//�{�[���ƃo�[�ƃu���b�N�̉摜�̕��ƍ���
	int bdwidth, bdheight, blwidth, blheight, bkwidth, bkheight;


	//�o�E���h���ƂԂ��艹�̃t���O
	bool boundflag, demolishflag;

	//�o�E���h���ƂԂ��艹�̃T�E���h�n���h��
	int bh, dh;

private:
	void HitCheckBallAndBar();
	void HitCheckBallAndBlock();
	void SoundPlay();

public:
	bool All();
	CONTROL(IDirect3DDevice9* pDevice3);
	~CONTROL();
};


