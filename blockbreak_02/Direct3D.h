#pragma once
class Direct3D
{
public:
	IDirect3D9*	pD3D9;			// Direct3Dデバイス生成用オブジェクト
	IDirect3DDevice9*pDevice3D;		// Direct3Dのデバイス

	// コンストラクタ
	Direct3D();
	// デストラクタ
	~Direct3D();

	// デバイス作成
	bool Create(HWND hWnd, int Width, int Height);
};
