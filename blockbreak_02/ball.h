#pragma once
#include "pch.h"
#include "Texture.h"
#define WIDTH 640
#define HEIGHT 480

class BALL {
	private:
		//x座標、y座標
		int x, y;

		//xとyの移動量
		int dx, dy;

		//画像の横、縦幅
		int width, height;

		//ゲームーオーバーフラグ
		bool endflag;

		//音を鳴らすかどうかのフラグ
		bool soundflag;

		// 3Dデバイス
		IDirect3DDevice9* pDevice3D;

		// テクスチャー
		Texture tex;

		void Draw();
		void Destroy();
		void Move();

	public:
		BALL(IDirect3DDevice9* pDevice3D);
		~BALL();
		bool All();
		int GetX();
		int GetY();
		int GetWidth();
		int GetHeight();
		void SetDX(int);
		void SetDY(int);
		int GetDX();
		int GetDY();
		bool GetSoundflag();
};

