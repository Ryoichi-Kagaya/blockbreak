#include "pch.h"
#include "bar.h"
#include "Texture.h"
#include "Sprite.h"

const int BAR::width = 100; // XXX: �摜�ύX����ꍇ�A�ǂ����悤�c
const int BAR::height = 14;

BAR::BAR(HWND hwnd, IDirect3DDevice9* pDevice3D)
{
	// 3D�f�o�C�X����荞��
	this->pDevice3D = pDevice3D;

	// �C���v�b�g���쐬
	input = new Input(hwnd);

	//y���W�͌Œ�Ȃ̂ł����Őݒ�
	y = 460;

	//�ŏ��͐^��
	x = wWidth / 2;

	//�I���t���O�͋U�ɂ��Ƃ�
	endflag = false;

}

void BAR::Draw() {
	// �e�N�X�`���쐬
	Texture tex;
	tex.Load(pDevice3D, _T("bar.bmp"));

	// �X�v���C�g�쐬�A�`��
	Sprite sprite;
	sprite.SetWidth(width, height);
	sprite.SetPos(x, y);
	sprite.Draw(pDevice3D, tex.pTexture);
}

void BAR::KeyGet()
{
	if (input->CheckKey(DIK_LEFT) == true) {
		//���Ɉړ��B
		x -= SPEED;
	}
	if (input->CheckKey(DIK_RIGHT) == true) {
		//�E�Ɉړ�
		x += SPEED;
	}
	if (input->CheckKey(DIK_ESCAPE) == true) {
		//�G�X�P�[�v�L�[��������Ă���ΏI���t���O��true�ɂ���
		endflag = true;
	}

	//��ʂ̂͂ݏo������
	if (x < width / 2) x = width / 2;
	if (x > wWidth - width / 2) x = wWidth - width / 2;

}

int BAR::GetX()
{
	return x;
}

int BAR::GetY()
{
	return y;
}

bool BAR::All()
{
	//�L�[����
	KeyGet();

	//�`�揈��
	Draw();

	//�I���t���O��Ԃ��B
	return endflag;
}

void BAR::Destroy() {


}

BAR::~BAR()
{
	if (pDevice3D != NULL) pDevice3D->Release();
	delete input;
	Destroy();

}

