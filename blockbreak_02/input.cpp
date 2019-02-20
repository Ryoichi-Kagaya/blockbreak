// XXX: ���LURL�̃R�[�h���A�قڗ��p
// https://qiita.com/okmonn/items/e17e7998a669bf3fee08

// XXX: ���LURL���Q�l�ɂ���
// https://blog.goo.ne.jp/0421dvdm/e/dc65c7a143632f52f84b997b62a6dee4

// XXX: �����A��񂪌Â��̂��C�ɂ͂Ȃ�

#include "pch.h"
#include "input.h"

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

// ����}�N��
#define Release(X) { if((X) != nullptr) (X)->Release(); (X) = nullptr; }

// �R���X�g���N�^
Input::Input(HWND hwnd) : // XXX: Window�^��O���錾���ĂāA��₱���������̂ŁA�E�B���h�E�n���h���ɕύX
	result(S_OK), input(nullptr), key(nullptr)
{
	memset(&keys, 0, sizeof(keys));
	memset(&olds, 0, sizeof(olds));

	CreateInput();
	CreateKey();
	SetKeyFormat();
	SetKeyCooperative(hwnd);
}
// �f�X�g���N�^
Input::~Input()
{
	Release(key);
	Release(input);
}
// �C���v�b�g�̐���
HRESULT Input::CreateInput(void)
{
	result = DirectInput8Create(GetModuleHandle(0), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)(&input), NULL);

	return result;
}
// �L�[�f�o�C�X�̐���
HRESULT Input::CreateKey(void)
{
	result = input->CreateDevice(GUID_SysKeyboard, &key, NULL);

	return result;
}
// �L�[�t�H�[�}�b�g�̃Z�b�g
HRESULT Input::SetKeyFormat(void)
{
	result = key->SetDataFormat(&c_dfDIKeyboard);

	return result;
}
// �L�[�̋������x���̃Z�b�g
HRESULT Input::SetKeyCooperative(HWND hwnd)
{
	result = key->SetCooperativeLevel(hwnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);

	//���̓f�o�C�X�ւ̃A�N�Z�X�������擾
	key->Acquire();

	return result;
}
// �L�[����
bool Input::CheckKey(UINT index)
{
	//�`�F�b�N�t���O
	bool flag = false;

	//�L�[�����擾
	HRESULT hr = key->GetDeviceState(sizeof(keys), &keys);
	if (keys[index] & 0x80) flag = true;
	olds[index] = keys[index];

	// �f�o�C�X���X�g�΍�
	if (hr == DIERR_INPUTLOST) key->Acquire(); // XXX: �ϐ�����Ȃ����Ǝv�������AFailed���킩��ɂ��������̂ŁA���̂܂�

	return flag;
}
// �g���K�[�̓���
bool Input::TriggerKey(UINT index)
{
	//�`�F�b�N�t���O
	bool flag = false;

	//�L�[�����擾
	HRESULT hr = key->GetDeviceState(sizeof(keys), &keys);
	if ((keys[index] & 0x80) && !(olds[index] & 0x80)) flag = true;
	olds[index] = keys[index];

	// �f�o�C�X���X�g�΍�
	if (hr == DIERR_INPUTLOST) key->Acquire();

	return flag;
}
