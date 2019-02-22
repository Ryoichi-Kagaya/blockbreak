#include "pch.h"
#include "ball.h"
#include "Sprite.h"

BALL::BALL(IDirect3DDevice9* pDevice3D)
{
	this->pDevice3D = pDevice3D;
	tex.Load(pDevice3D, _T("ball.bmp"));
	width = 18;
	height = 18;

	//y���W�͌Œ�Ȃ̂ł����Őݒ�
	y = 400;

	//�ŏ��͐^��
	x = WIDTH / 2;

	//�ŏ��̌W��
	dx = 3;
	dy = -3;

	endflag = false;
	soundflag = false;
}

void BALL::Draw() 
{
	// �X�v���C�g�쐬�A�`��
	Sprite sprite;
	sprite.SetWidth(width, height);
	sprite.SetPos(x, y);
	sprite.Draw(pDevice3D, tex.pTexture);
}

void BALL::Move() 
{
	//�܂�����OFF�ɂ��Ƃ�
	soundflag = false;

	//�ړ��ʂ����Z
	x += dx;
	y += dy;

	//��ʂ͂ݏo������
	if (x < width / 2)
	{
		x = width / 2;
		dx *= -1;
		//���������̂ŃT�E���h�t���O�𗧂Ă�
		soundflag = true;
	}

	if (x > WIDTH - width / 2) 
	{
		x = WIDTH - width / 2;
		dx *= -1;
		//���������̂ŃT�E���h�t���O�𗧂Ă�
		soundflag = true;
	}

	if (y < height / 2)
	{
		y = height / 2;
		dy *= -1;
		//���������̂ŃT�E���h�t���O�𗧂Ă�
		soundflag = true;
	}

	//���ɂ͂ݏo����Q�[���I�[�o�[
	if (y > HEIGHT)
	{
		endflag = true;
	}
}

int BALL::GetX()
{
	return x;
}

int BALL::GetY()
{
	return y;
}

void BALL::SetDX(int x)
{
	dx = x;
}

void BALL::SetDY(int y)
{
	dy = y;
}

int BALL::GetDX()
{
	return dx;
}

int BALL::GetDY()
{
	return dy;
}

int BALL::GetWidth()
{
	return width;
}

int BALL::GetHeight()
{
	return height;
}

bool BALL::GetSoundflag()
{
	return soundflag;
}

bool BALL::All()
{
	Move();
	Draw();
	return endflag;
}

void BALL::Destroy() {

}

BALL::~BALL()
{
	if (pDevice3D != NULL) pDevice3D->Release();
	Destroy();
}

