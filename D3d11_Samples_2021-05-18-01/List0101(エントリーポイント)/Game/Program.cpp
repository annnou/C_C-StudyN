//=============================================================================
// Program.cpp
// 
//=============================================================================
#include <Windows.h>

//// �R�}���h���C�������Ƃ�
//int main(int argc, char **argv) {
//	printf("%d", argc);	// 3
//	printf(argv[0]);	// "Game.exe"
//	printf(argv[1]);	// "/f=filename"
//	printf(argv[2]);	// "/i"
//	return 0;
//}

// �G���g���[�|�C���g
int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,			// �C���X�^���X�ւ̃n���h��
	_In_opt_ HINSTANCE hPrevInstance,	// ���݂ł͖��g�p
	_In_ LPWSTR lpCmdLine,				// �R�}���h���C������
	_In_ int nCmdShow)					// �\�����
{
	CHAR str[] = "ABC������\n";
	//printf("%s", str);
	OutputDebugStringA(str);

	WCHAR strW[] = L"ABC������\n";
	OutputDebugStringW(strW);
	OutputDebugString(strW);

	return 0;
}