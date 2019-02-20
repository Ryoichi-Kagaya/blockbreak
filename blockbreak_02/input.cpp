// XXX: 下記URLのコードを、ほぼ流用
// https://qiita.com/okmonn/items/e17e7998a669bf3fee08

// XXX: 下記URLも参考にした
// https://blog.goo.ne.jp/0421dvdm/e/dc65c7a143632f52f84b997b62a6dee4

// XXX: 両方、情報が古いのが気にはなる

#include "pch.h"
#include "input.h"

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

// 解放マクロ
#define Release(X) { if((X) != nullptr) (X)->Release(); (X) = nullptr; }

// コンストラクタ
Input::Input(HWND hwnd) : // XXX: Window型を前方宣言してて、ややこしかったので、ウィンドウハンドルに変更
	result(S_OK), input(nullptr), key(nullptr)
{
	memset(&keys, 0, sizeof(keys));
	memset(&olds, 0, sizeof(olds));

	CreateInput();
	CreateKey();
	SetKeyFormat();
	SetKeyCooperative(hwnd);
}
// デストラクタ
Input::~Input()
{
	Release(key);
	Release(input);
}
// インプットの生成
HRESULT Input::CreateInput(void)
{
	result = DirectInput8Create(GetModuleHandle(0), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)(&input), NULL);

	return result;
}
// キーデバイスの生成
HRESULT Input::CreateKey(void)
{
	result = input->CreateDevice(GUID_SysKeyboard, &key, NULL);

	return result;
}
// キーフォーマットのセット
HRESULT Input::SetKeyFormat(void)
{
	result = key->SetDataFormat(&c_dfDIKeyboard);

	return result;
}
// キーの協調レベルのセット
HRESULT Input::SetKeyCooperative(HWND hwnd)
{
	result = key->SetCooperativeLevel(hwnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);

	//入力デバイスへのアクセス権利を取得
	key->Acquire();

	return result;
}
// キー入力
bool Input::CheckKey(UINT index)
{
	//チェックフラグ
	bool flag = false;

	//キー情報を取得
	HRESULT hr = key->GetDeviceState(sizeof(keys), &keys);
	if (keys[index] & 0x80) flag = true;
	olds[index] = keys[index];

	// デバイスロスト対策
	if (hr == DIERR_INPUTLOST) key->Acquire(); // XXX: 変数いらないかと思ったが、Failedがわかりにくかったので、そのまま

	return flag;
}
// トリガーの入力
bool Input::TriggerKey(UINT index)
{
	//チェックフラグ
	bool flag = false;

	//キー情報を取得
	HRESULT hr = key->GetDeviceState(sizeof(keys), &keys);
	if ((keys[index] & 0x80) && !(olds[index] & 0x80)) flag = true;
	olds[index] = keys[index];

	// デバイスロスト対策
	if (hr == DIERR_INPUTLOST) key->Acquire();

	return flag;
}
