#include "pch.h"
#include "control.h"

CONTROL::CONTROL(HWND hwnd, IDirect3DDevice9* pDevice3)
{

	//�o�[�ƃ{�[���̃C���X�^���X�𐶐�
	bar = new BAR(hwnd, pDevice3);
	ball = new BALL(pDevice3);

	boundflag = false;
	demolishflag = false;

	//�o�[�̕��ƍ���
	bdwidth = bar->width;
	bdheight = bar->height;

	//�{�[���̕��ƍ���
	blwidth = ball->GetWidth();
	blheight = ball->GetHeight();

	//�����t�@�C���ǂݍ��݁B
	//bh = LoadSoundMem("bound.mp3");
	//dh = LoadSoundMem("demolish.mp3");
	
	// �u���b�N�z�u�p�̕ϐ�
	// XXX: �������傢�ϐ����炵����
	bkNum = 15;
	int bkCol = 5;
	int bkRow = 3;
	int bkMargin = 10;

	// �u���b�N��z�u
	for (int i = 0; i < bkNum; ++i) {
		block[i] = new BLOCK(pDevice3,
			(block[i]->width + bkMargin) * (i % bkCol) + (block[i]->width / 2 + bkMargin),
			(block[i]->height + bkMargin) * (i % bkRow) + (block[i]->height / 2 + bkMargin));
	}

	bkwidth = block[0]->width;
	bkheight = block[0]->height;
}

CONTROL::~CONTROL()
{
	delete bar;
	delete ball;

	for (int i = 0; i < bkNum; ++i) {
		delete block[i];
	}
}

void CONTROL::HitCheckBallAndBar()
{
	//�ŏ��̓t���O��false�ɂ��Ƃ��B
	boundflag = false;

	//�{�[���N���X���ł̉��t���O���Z�b�g
	boundflag = ball->GetSoundflag();

	//�o�[�̍��W�擾
	bdx = bar->GetX();
	bdy = bar->GetY();

	//�{�[���̍��W�擾
	blx = ball->GetX();
	bly = ball->GetY();

	//�{�[���ƃo�[�̍����̔����𑫂������̂���
	//�o�[�̒��S�ƃ{�[���̒��S�̋����̐�Βl�̕��������������瓖����
	//���̋������傫����͏��O
	if (abs(bdy - bly) < blheight / 2 + bdheight / 2) {
		//���A�{�[�����o�[���ɂ���Γ�����
		if (bdx + bdwidth / 2 > blx &&
			bdx - bdwidth / 2 < blx) {
			//�o�[�̍��[�ɓ������Ă���΁A�t�����ɔ�΂��B
			if (blx < bdx - bdwidth / 2 * 2 / 3) {
				//�{�[���𔽓]
				ball->SetDX(-1 * ball->GetDX());
				//Y�͒��˕Ԃ�����
				ball->SetDY(ball->GetDY()*-1);
				//�o�E���h���t���O�𗧂Ă�B
				boundflag = true;

				//�E�[
			}
			else if (blx > bdx + bdwidth / 2 * 2 / 3) {
				//�{�[���𔽓]
				ball->SetDX(-1 * ball->GetDX());
				//Y�͒��˕Ԃ�����
				ball->SetDY(ball->GetDY()*-1);
				//�o�E���h���t���O�𗧂Ă�B
				boundflag = true;

				//����ȊO�͂�������
			}
			else {
				//x�͉����Ȃ�
				//Y�͒��˕Ԃ�����
				ball->SetDY(ball->GetDY()*-1);
				//�o�E���h���t���O�𗧂Ă�B
				boundflag = true;
			}
		}
	}
}

void CONTROL::HitCheckBallAndBlock()
{
	//�j�󉹃t���O
	demolishflag = false;

	//�{�[���̍��W�擾
	blx = ball->GetX();
	bly = ball->GetY();

	//�u���b�N�S�Ă����[�v
	for (int i = 0; i < 12; ++i) {
		//���ĂȂ��z�����Ώ�
		if (!block[i]->GetFlag()) {
			bkx = block[i]->GetX();
			bky = block[i]->GetY();

			//�u���b�N�̏�Ƃ̓����蔻��
			if (blx<bkx + bkwidth / 2 && blx>bkx - bkwidth / 2 &&
				bly + blheight / 2 > bky - bkheight / 2 && bly + blheight / 2 < bky + bkheight / 2) {
				//�t���O���I�t��
				block[i]->SetFlag(true);
				//�j�󉹃t���O�𗧂Ă�
				demolishflag = true;
				//�{�[���͂������˕Ԃ�����
				ball->SetDY(ball->GetDY()*-1);

				//�u���b�N�̉��Ƃ̓����蔻��
			}
			else if (blx<bkx + bkwidth / 2 && blx>bkx - bkwidth / 2 &&
				bly - blheight / 2 > bky - bkheight / 2 && bly - blheight / 2 < bky + bkheight / 2) {

				//�t���O���I�t��
				block[i]->SetFlag(true);
				//�j�󉹃t���O�𗧂Ă�
				demolishflag = true;
				//�{�[���͂������˕Ԃ�����
				ball->SetDY(ball->GetDY()*-1);

				//�u���b�N�̍��Ƃ̓����蔻��
			}
			else if (blx + blwidth / 2 < bkx - bkwidth / 2 + blwidth && blx + blwidth / 2 > bkx - bkwidth / 2 &&
				bly > bky - bkheight / 2 && bly < bky + bkheight / 2) {

				//�t���O���I�t��
				block[i]->SetFlag(true);
				//�j�󉹃t���O�𗧂Ă�
				demolishflag = true;
				//�{�[���͂������˕Ԃ�����
				ball->SetDX(ball->GetDX()*-1);

				//�u���b�N�̉E�Ƃ̓����蔻��
			}
			else if (blx - blwidth / 2 < bkx + bkwidth / 2 && blx - blwidth / 2 > bkx + bkwidth / 2 - blwidth &&
				bly > bky - bkheight / 2 && bly < bky + bkheight / 2) {

				//�t���O���I�t��
				block[i]->SetFlag(true);
				//�j�󉹃t���O�𗧂Ă�
				demolishflag = true;
				//�{�[���͂������˕Ԃ�����
				ball->SetDX(ball->GetDX()*-1);
			}
		}
	}
}

void CONTROL::SoundPlay()
{
	/*
	if (boundflag) {

		PlaySoundMem(bh, DX_PLAYTYPE_BACK);
	}

	if (demolishflag) {
		PlaySoundMem(dh, DX_PLAYTYPE_BACK);
	}
	*/
}

bool CONTROL::All()
{
	bool back = true;

	for (int i = 0; i < bkNum; ++i) {
		block[i]->All();
	}

	//�o�[�̏���
	bar->All();

	//�{�[���̓���
	back = ball->All();

	//�{�[���ƃo�[�̓����蔻��
	HitCheckBallAndBar();

	//�{�[���ƃu���b�N�̓����蔻��
	HitCheckBallAndBlock();

	//���Đ�
	SoundPlay();

	return back;
}

