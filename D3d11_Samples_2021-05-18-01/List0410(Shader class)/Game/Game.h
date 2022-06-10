//=============================================================================
// Game.h
// 
//=============================================================================
#pragma once

#include <Windows.h>
#include <d3d11.h>

#define SAFE_RELEASE(p) if ((p) != nullptr) { (p)->Release(); (p) = nullptr; }

// アプリケーション全体を表します。
class Game {
public:
	// アプリケーションを初期化します。
	void Initialize(LPCWSTR windowTitle, int screenWidth, int screenHeight);
	// メッセージループを実行します。
	int Run();

private:
	// ウィンドウのタイトル
	LPCWSTR WindowTitle = L"タイトル";
	// ウィンドウの幅
	int ScreenWidth = 640;
	// ウィンドウの高さ
	int ScreenHeight = 480;
	// ウィンドウのハンドル
	HWND hWnd = NULL;

	// ウィンドウを作成します。
	bool InitWindow();

	// Direct3D 11のデバイス
	ID3D11Device* graphicsDevice = nullptr;
	// Direct3D 11のデバイス コンテキスト
	ID3D11DeviceContext* immediateContext = nullptr;
	// Direct3D 11の機能レベル
	D3D_FEATURE_LEVEL featureLevel = {};
	// スワップチェーン
	IDXGISwapChain* swapChain = nullptr;
	// レンダーターゲット
	ID3D11RenderTargetView* renderTargetViews[1];
	// バックバッファーをシェーダーで利用するためのリソース ビュー
	ID3D11ShaderResourceView* renderTargetResourceView = nullptr;
	// 深度ステンシルのフォーマット
	const DXGI_FORMAT depthStencilFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;
	// 深度ステンシル
	ID3D11DepthStencilView* depthStencilView = nullptr;
	// 深度ステンシルをシェーダーで利用するためのリソース ビュー
	ID3D11ShaderResourceView* depthStencilResourceView = nullptr;
	// 画面クリアーに使用するカラー
	FLOAT clearColor[4] = { 53 / 255.0f, 70 / 255.0f, 166 / 255.0f, 1.0f };
	// ビューポート
	D3D11_VIEWPORT viewports[1] = {};

	// グラフィックデバイスを作成します。
	bool InitGraphicsDevice();
	// グラフィックリソースを解放します。
	void ReleaseGraphicsDevice();
};

// 頂点シェーダーを表します。
class BasicVertexShader
{
private:
	// D3D11のインターフェース
	ID3D11VertexShader* shader = nullptr;

public:
	// このクラスの新しいインスタンスを作成します。
	static BasicVertexShader* Create(ID3D11Device* graphicsDevice);
	// リソースを解放します。
	void Release();
	// D3D11のネイティブポインターを取得します。
	ID3D11VertexShader* GetNativePointer();
};

// ジオメトリーシェーダーを表します。
class BasicGeometryShader
{
private:
	// D3D11のインターフェース
	ID3D11GeometryShader* shader = nullptr;

public:
	// このクラスの新しいインスタンスを作成します。
	static BasicGeometryShader* Create(ID3D11Device* graphicsDevice);
	// リソースを解放します。
	void Release();
	// D3D11のネイティブポインターを取得します。
	ID3D11GeometryShader* GetNativePointer();
};

// ピクセルシェーダーを表します。
class BasicPixelShader
{
private:
	// D3D11のインターフェース
	ID3D11PixelShader* shader = nullptr;

public:
	// このクラスの新しいインスタンスを作成します。
	static BasicPixelShader* Create(ID3D11Device* graphicsDevice);
	// リソースを解放します。
	void Release();
	// D3D11のネイティブポインターを取得します。
	ID3D11PixelShader* GetNativePointer();
};