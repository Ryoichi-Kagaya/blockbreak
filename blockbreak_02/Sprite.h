#pragma once
class Sprite
{
public:
	// 板ポリゴン頂点情報
	struct Vertex {
		float x, y, z;// 3次元座標
		float rhw;	// 2D変換済みフラグ
		float u, v;	// UV座標
	};
	// FVF（柔軟な頂点構造体宣言）フラグ
	static const DWORD SPRITE_FVF = D3DFVF_XYZRHW | D3DFVF_TEX1;

	// スプライト位置
	D3DXVECTOR2 pos;
	// スプライトサイズ
	int width;
	int height;

	// コンストラクタ
	Sprite();
	// デストラクタ
	~Sprite();

	void SetPos(float x, float y);
	void SetWidth(int Width, int Height);
	void Draw(IDirect3DDevice9* pDevice3D, IDirect3DTexture9* pTexture);

};

