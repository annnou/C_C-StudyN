//=============================================================================
// Program.cpp
// 
//=============================================================================
#include <Windows.h>

//// コマンドライン引数とは
//int main(int argc, char **argv) {
//	printf("%d", argc);	// 3
//	printf(argv[0]);	// "Game.exe"
//	printf(argv[1]);	// "/f=filename"
//	printf(argv[2]);	// "/i"
//	return 0;
//}

// エントリーポイント
int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,			// インスタンスへのハンドル
	_In_opt_ HINSTANCE hPrevInstance,	// 現在では未使用
	_In_ LPWSTR lpCmdLine,				// コマンドライン引数
	_In_ int nCmdShow)					// 表示状態
{
	CHAR str[] = "ABCあいう\n";
	//printf("%s", str);
	OutputDebugStringA(str);

	WCHAR strW[] = L"ABCあいう\n";
	OutputDebugStringW(strW);
	OutputDebugString(strW);

	return 0;
}