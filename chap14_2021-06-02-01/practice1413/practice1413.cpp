// �w�b�_�[�t�@�C���Ǝ����t�@�C���ɕ���

#include "IntArray.h"
#include <cstdio>

// �z��̗v�f�����ׂĕ\��
void PrintIntArray(const IntArray* numbers) {
	for (size_t index = 0; index < numbers->GetCount(); index++) {
		printf("numbers[%zu] : %d\n", index, (*numbers)[index]);
	}
}

int main() {
	IntArray* numbers = new IntArray(3);

	numbers->Add(10);	// 0
	numbers->Add(20);	// 1
	numbers->Add(30);	// 2
	(*numbers)[0] = 0;
	// �z��̗v�f�����ׂĕ\��
	for (size_t index = 0; index < numbers->GetCount(); index++) {
		printf("numbers[%zu] : %d\n", index, numbers->GetAt(index));
	}
	//// �z��̗v�f�����ׂĕ\��
	//for (size_t index = 0; index < numbers->GetCount(); index++) {
	//	printf("numbers[%zu] : %d\n", index, (*numbers)[index]);
	//}

	PrintIntArray(numbers);

	printf("count : %zu\n", numbers->GetCount());

	delete numbers;

	return 0;
}