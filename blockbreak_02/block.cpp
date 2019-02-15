#include "pch.h"
#include "block.h"
#include "Texture.h"
#include "Sprite.h"

int BLOCK::gh = -1;
const int BLOCK::width = 100; // XXX: �摜�ύX����ꍇ�A�ǂ����悤�c
const int BLOCK::height = 28;

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

float BLOCK::GetX()
{
	return x;
}
float BLOCK::GetY()
{
	return y;
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

	// XXX: Texture�N���X���Ăяo�������肭�������B�ߑR�Ƃ��Ȃ����A�Ƃ肠�����͓������̂����
	// XXX: �O����t�@�C���������Ă����玸�s
	//const TCHAR* FileName = _T("block.bmp");
	Texture tex;
	tex.Load(pDevice3D, _T("block.bmp"));
	Sprite sprite;
	sprite.SetWidth(width, height);
	sprite.SetPos(x, y);
	sprite.Draw(pDevice3D, tex.pTexture);
}

void BLOCK::All()
{
	Draw();
}
