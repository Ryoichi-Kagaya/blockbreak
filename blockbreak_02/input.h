#pragma once
#pragma comment(lib, "dinput8.lib")
#define DIRECTINPUT_VERSION 0x0800
#define KEY_MAX 256

class Input
{
public:
	// �R���X�g���N�^
	Input(HWND hwnd);
	// �f�X�g���N�^
	~Input();
	// �L�[����
	bool CheckKey(UINT index);
	// �g���K�[�̓���
	bool TriggerKey(UINT index);

private:
	// �C���v�b�g�̐���
	HRESULT CreateInput(void);
	// �L�[�f�o�C�X�̐���
	HRESULT CreateKey(void);
	// �L�[�t�H�[�}�b�g�̃Z�b�g
	HRESULT SetKeyFormat(void);
	// �L�[�̋������x���̃Z�b�g
	HRESULT SetKeyCooperative(HWND hwnd);

	// �Q�ƌ���
	HRESULT result;
	// �C���v�b�g
	LPDIRECTINPUT input;
	// �C���v�b�g�f�o�C�X
	LPDIRECTINPUTDEVICE key;
	// �L�[���
	BYTE keys[KEY_MAX];
	// �O�̃L�[���
	BYTE olds[KEY_MAX];
};

