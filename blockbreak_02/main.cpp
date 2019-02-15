#include "pch.h"
#include "Direct3D.h"
#include "Texture.h"
#include "Sprite.h"
#include "block.h"
#include "control.h"

// �E�B���h�E�v���V�[�W���A�E�B���h�E�ɑ΂��郁�b�Z�[�W�������s��
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {
		// �E�B���h�E���j�����ꂽ�Ƃ�
	case WM_DESTROY:
		PostQuitMessage(0);	// WM_QUIT���b�Z�[�W�����b�Z�[�W�L���[�ɑ���
		return 0;
	}
	// �f�t�H���g�̃��b�Z�[�W�������s��
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

// WinMain�֐��i�A�v���P�[�V�����̊J�n�֐��j
// �R���\�[���A�v���P�[�V�����ƈႢ�A�R���\�[�����J���Ȃ�
int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	const TCHAR* WC_BASIC = _T("BASIC_WINDOW");
	// �V���v���E�B���h�E�N���X�ݒ�
	WNDCLASSEX wcex = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,WndProc, 0,0,hInstance,
		(HICON)LoadImage(NULL,MAKEINTRESOURCE(IDI_APPLICATION),IMAGE_ICON,0,0,LR_DEFAULTSIZE | LR_SHARED),
		(HCURSOR)LoadImage(NULL,MAKEINTRESOURCE(IDC_ARROW),IMAGE_CURSOR,0,0,LR_DEFAULTSIZE | LR_SHARED),
		(HBRUSH)GetStockObject(WHITE_BRUSH), NULL, WC_BASIC , NULL };

	// �V���v���E�B���h�E�N���X�쐬
	if (!RegisterClassEx(&wcex))
		return false;

	// �E�B���h�E���A�����̓f�B�X�v���C�Ɉˑ�����B���ʂ�4:3
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;
	// �E�B���h�E�̍쐬
	HWND hWnd = CreateWindowEx(0, WC_BASIC,
		_T("Application"), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

	////////////////////////////////////////////////////////////////////////////
	// Direct3D�̏�����
	////////////////////////////////
	Direct3D direct3d;
	direct3d.Create(hWnd, WINDOW_WIDTH, WINDOW_HEIGHT);

	////////////////////////////////
	// �u���b�N�쐬
	////////////////////////////////
	BLOCK block(direct3d.pDevice3D, 100, 100);

	////////////////////////////////
	// �R���g���[���쐬
	////////////////////////////////
	CONTROL control(direct3d.pDevice3D);

	////////////////////////////////////////////////////////////////

	// ���b�Z�[�W���[�v
	MSG msg = {};
	while (msg.message != WM_QUIT) {
		// �A�v���P�[�V�����ɑ����Ă��郁�b�Z�[�W�����b�Z�[�W�L���[����擾����
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			DispatchMessage(&msg);	// �A�v���P�[�V�����̊e�E�B���h�E�v���V�[�W���Ƀ��b�Z�[�W��]������
		}
		// ���b�Z�[�W���������Ă��Ȃ��Ƃ��i������DirectX�̏����������j
		else {

			////////////////////////////////////////////////////////////////

			// �`��J�n
			if (SUCCEEDED(direct3d.pDevice3D->BeginScene()))
			{
				// �w�i�N���A
				DWORD ClearColor = 0xff000000;	// �w�i�N���A�F
				direct3d.pDevice3D->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER, ClearColor, 1.0f, 0);
				
				// �R���g���[���쓮�I
				control.All();

				// �`��I��
				direct3d.pDevice3D->EndScene();
			}
			// �`�攽�f
			direct3d.pDevice3D->Present(NULL, NULL, NULL, NULL);

			////////////////////////////////////////////////////////////////
		}
	}

	return 0;
}