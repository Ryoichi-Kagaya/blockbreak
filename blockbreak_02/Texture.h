#pragma once
class Texture
{
public:
	IDirect3DTexture9* pTexture;
	// �R���X�g���N�^
	Texture();
	// �f�X�g���N�^
	~Texture();
	// �摜�f�[�^�ǂݍ���
	bool Load(IDirect3DDevice9* pDevice3D, const TCHAR* FileName);
};

