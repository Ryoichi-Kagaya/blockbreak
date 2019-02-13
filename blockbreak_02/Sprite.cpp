#include "pch.h"
#include "Sprite.h"


// �R���X�g���N�^
Sprite::Sprite()
{
	pos.x = pos.y = 0.0f;
	width = 0;
	height = 0;
}
// �f�X�g���N�^
Sprite::~Sprite() {
}

void Sprite::SetPos(float x, float y)
{
	pos.x = x;
	pos.y = y;
}
void Sprite::SetWidth(int Width, int Height)
{
	width = Width;
	height = Height;
}

void Sprite::Draw(IDirect3DDevice9* pDevice3D, IDirect3DTexture9* pTexture)
{
	// ���_���Z�b�g
	Vertex vtx[4] = {
		{ pos.x + width / 2, pos.y - height / 2, 0.0f, 1.0f, 1.0f, 0.0f},
		{ pos.x + width / 2, pos.y + height / 2, 0.0f, 1.0f, 1.0f, 1.0f},
		{ pos.x - width / 2, pos.y - height / 2, 0.0f, 1.0f, 0.0f, 0.0f},
		{ pos.x - width / 2, pos.y + height / 2, 0.0f, 1.0f, 0.0f, 1.0f}
	};

	// �e�N�X�`���Z�b�g
	pDevice3D->SetTexture(0, pTexture);
	// ���_�\���̐錾�Z�b�g
	pDevice3D->SetFVF(SPRITE_FVF);
	// �X�v���C�g�`��
	pDevice3D->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vtx, sizeof(Vertex));
}
