#include "pch.h"
#include "block.h"
#include "Texture.h"
#include "Sprite.h"

const TCHAR* FileName = _T("block.bmp");
int BLOCK::gh = -1;

BLOCK::BLOCK(IDirect3DDevice9* pDevice3D, float x, float y)
{
	//�ŏ������ǂݍ��܂Ȃ��B
	//if (gh == -1) Load();

	//GetGraphSize(gh, &width, &height);
	this->pDevice3D = pDevice3D;

	endflag = false;

	this->x = x;
	this->y = y;

	count = 0;

}

BLOCK::~BLOCK() {
	if (pTexture != NULL) pTexture->Release();
}

bool SetSize()
{
	// �e�N�X�`���T�C�Y�̎擾
	D3DSURFACE_DESC desc;
	if (FAILED(tex->GetLevelDesc(0, &desc)))
	{
		return false;
	}

	*pX = desc.Width;
	*pY = desc.Height;
}

bool BLOCK::Load() // XXX: �����ŉ摜�̓ǂݍ��݂���肭�����Ă��Ȃ�
{
	if (FAILED(D3DXCreateTextureFromFile(pDevice3D, FileName, &pTexture))) {
		return false; // �摜�ǂݍ��ݎ��s�i�t�@�C�����Ȃ��\������j
	}
	else {
		return true; // �摜�ǂݍ��ݐ���
	}
}

float BLOCK::GetX()
{
	return x;
}
float BLOCK::GetY()
{
	return y;
}
int BLOCK::GetWidth()
{
	return width;
}
int BLOCK::GetHeight()
{
	return height;
}

void BLOCK::SetFlag(bool flag)
{
	endflag = flag;
}
bool BLOCK::GetFlag()
{
	return endflag;
}

void BLOCK::Draw()
{
	//�u���b�N�����ĂȂ��Ƃ������`��
	/* if (!endflag) {
		DrawGraph(x - width / 2, y - height / 2, gh, FALSE);
	}
	else {
		if (count < 40) {
			//���ߓx���w��
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, (255 / 40)*(40 - count));
			//�`��
			DrawGraph(x - width / 2, y - height / 2, gh, FALSE);
			//�ݒ��߂�
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			++count;
		}
	}*/

	/*
	Sprite sprite;
	sprite.SetWidth(100, 28);
	sprite.SetPos(x, y);
	sprite.Draw(pDevice3D, pTexture);
	*/

	// XXX: Texture�N���X���Ăяo�������肭�������B�ߑR�Ƃ��Ȃ����A�Ƃ肠�����͓������̂����
	Texture tex;
	tex.Load(pDevice3D, FileName);
	Sprite sprite;
	sprite.SetWidth(100, 28);
	sprite.SetPos(x, y);
	sprite.Draw(pDevice3D, tex.pTexture);
}

void BLOCK::All()
{
	Draw();
}
