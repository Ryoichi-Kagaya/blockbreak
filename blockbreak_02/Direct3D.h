#pragma once
class Direct3D
{
public:
	IDirect3D9*	pD3D9;			// Direct3D�f�o�C�X�����p�I�u�W�F�N�g
	IDirect3DDevice9*pDevice3D;		// Direct3D�̃f�o�C�X

	// �R���X�g���N�^
	Direct3D();
	// �f�X�g���N�^
	~Direct3D();

	// �f�o�C�X�쐬
	bool Create(HWND hWnd, int Width, int Height);
};
