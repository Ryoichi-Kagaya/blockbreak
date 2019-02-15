#include "pch.h"
#include "Direct3D.h"
#include "Texture.h"
#include "Sprite.h"
#include "block.h"
#include "control.h"

// ウィンドウプロシージャ、ウィンドウに対するメッセージ処理を行う
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {
		// ウィンドウが破棄されたとき
	case WM_DESTROY:
		PostQuitMessage(0);	// WM_QUITメッセージをメッセージキューに送る
		return 0;
	}
	// デフォルトのメッセージ処理を行う
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

// WinMain関数（アプリケーションの開始関数）
// コンソールアプリケーションと違い、コンソールを開かない
int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	const TCHAR* WC_BASIC = _T("BASIC_WINDOW");
	// シンプルウィンドウクラス設定
	WNDCLASSEX wcex = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,WndProc, 0,0,hInstance,
		(HICON)LoadImage(NULL,MAKEINTRESOURCE(IDI_APPLICATION),IMAGE_ICON,0,0,LR_DEFAULTSIZE | LR_SHARED),
		(HCURSOR)LoadImage(NULL,MAKEINTRESOURCE(IDC_ARROW),IMAGE_CURSOR,0,0,LR_DEFAULTSIZE | LR_SHARED),
		(HBRUSH)GetStockObject(WHITE_BRUSH), NULL, WC_BASIC , NULL };

	// シンプルウィンドウクラス作成
	if (!RegisterClassEx(&wcex))
		return false;

	// ウィンドウ幅、高さはディスプレイに依存する。普通は4:3
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;
	// ウィンドウの作成
	HWND hWnd = CreateWindowEx(0, WC_BASIC,
		_T("Application"), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

	////////////////////////////////////////////////////////////////////////////
	// Direct3Dの初期化
	////////////////////////////////
	Direct3D direct3d;
	direct3d.Create(hWnd, WINDOW_WIDTH, WINDOW_HEIGHT);

	////////////////////////////////
	// ブロック作成
	////////////////////////////////
	BLOCK block(direct3d.pDevice3D, 100, 100);

	////////////////////////////////
	// コントロール作成
	////////////////////////////////
	CONTROL control(direct3d.pDevice3D);

	////////////////////////////////////////////////////////////////

	// メッセージループ
	MSG msg = {};
	while (msg.message != WM_QUIT) {
		// アプリケーションに送られてくるメッセージをメッセージキューから取得する
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			DispatchMessage(&msg);	// アプリケーションの各ウィンドウプロシージャにメッセージを転送する
		}
		// メッセージ処理をしていないとき（ここにDirectXの処理を書く）
		else {

			////////////////////////////////////////////////////////////////

			// 描画開始
			if (SUCCEEDED(direct3d.pDevice3D->BeginScene()))
			{
				// 背景クリア
				DWORD ClearColor = 0xff000000;	// 背景クリア色
				direct3d.pDevice3D->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER, ClearColor, 1.0f, 0);
				
				// コントロール作動！
				control.All();

				// 描画終了
				direct3d.pDevice3D->EndScene();
			}
			// 描画反映
			direct3d.pDevice3D->Present(NULL, NULL, NULL, NULL);

			////////////////////////////////////////////////////////////////
		}
	}

	return 0;
}