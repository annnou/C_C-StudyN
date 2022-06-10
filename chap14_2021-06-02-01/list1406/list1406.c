// �z��̗v�f���폜����

#include <stdio.h>
#include <stdlib.h>

// int�^�̔z����Ǘ����܂��B
typedef struct {
	size_t capacity;	// ���̔z��ɒǉ��ł���ő�v�f��
	size_t count;		// ���ݒǉ�����Ă���v�f��
	int* data;
} IntArray;

// IntArray�I�u�W�F�N�g�����������܂��B
void IntArray_Initialize(IntArray* intArray, size_t capacity) {
	intArray->capacity = capacity;
	intArray->count = 0;
	// ���͂���v�f�������傤�Ǌi�[�ł��郁�����[�𓮓I�Ɋm��
	intArray->data = malloc(sizeof(int) * capacity);
	if (intArray->data == NULL) {
		perror("���I�������[���m�ۂł��܂���ł����B");
		exit(-1);
	}
}

// IntArray�I�u�W�F�N�g��������܂��B
void IntArray_Release(IntArray* intArray) {
	free(intArray->data);
}

// �z��Ɋi�[�ł���v�f�����擾���܂��B
size_t IntArray_GetCapacity(IntArray* intArray) {
	return intArray->capacity;
}

// �z��ɒǉ�����Ă���v�f�����擾���܂��B
size_t IntArray_GetCount(IntArray* intArray) {
	return intArray->count;
}

// �w�肵���C���f�b�N�X�Ԗڂ̒l���擾���܂��B
int IntArray_GetAt(IntArray* intArray, size_t index) {
	return intArray->data[index];
}

// �z��̖����Ɏw�肵���l��ǉ����܂��B
void IntArray_Add(IntArray* intArray, int value) {
	// �z��e�ʂ�����Ȃ��ꍇ
	if (intArray->count == intArray->capacity) {
		// �z��T�C�Y���g������
		size_t newCapacity = intArray->capacity * 2;
		int* newData = malloc(sizeof(int) * newCapacity);
		if (newData == NULL) {
			perror("���I�������[���m�ۂł��܂���ł����B");
			exit(-1);
		}
		// �V�̈�Ƀf�[�^�𕡐�
		for (size_t index = 0; index < intArray->count; index++) {
			*(newData + index) = intArray->data[index];
		}
		// �Â��������[��������ĐV�̈���g�p����悤�ɕύX
		free(intArray->data);
		intArray->data = newData;
		intArray->capacity = newCapacity;
	}
	*(intArray->data + intArray->count) = value;
	intArray->count++;
}


// ���K14-6
// �ȉ��ɐ錾����IntArray_Remove()�֐����������Ȃ����B

// �w�肵���C���f�b�N�X�ʒu�̗v�f���폜���܂��B
void IntArray_Remove(IntArray* intArray, size_t index) {

}

int main() {
	IntArray numbers;

	// �������i�ő�v�f���͓K���ɑ傫�߂ɐݒ�j
	IntArray_Initialize(&numbers, 3);

	IntArray_Add(&numbers, 10);	// 0
	IntArray_Add(&numbers, 20);	// 1
	IntArray_Add(&numbers, 30); // 2

	// �z��̗v�f�����ׂĕ\��
	for (size_t index = 0; index < IntArray_GetCount(&numbers); index++) {
		printf("numbers[%zu] : %d\n", index, IntArray_GetAt(&numbers, index));
	}
	printf("count : %zu\n", IntArray_GetCount(&numbers));
	// �\������
	//	numbers[0] : 10
	//	numbers[1] : 20
	//	numbers[2] : 30
	//	count : 3

	IntArray_Remove(&numbers, 1);	// �C���f�b�N�X1�̗v�f(20)���폜�����

	puts("==============================");

	// �z��̗v�f�����ׂĕ\��
	for (size_t index = 0; index < IntArray_GetCount(&numbers); index++) {
		printf("numbers[%zu] : %d\n", index, IntArray_GetAt(&numbers, index));
	}
	printf("count : %zu\n", IntArray_GetCount(&numbers));
	// �\������
	//	numbers[0] : 10
	//	numbers[1] : 30
	//	count : 2

	// ���I�Ɋm�ۂ����������[�̉��
	IntArray_Release(&numbers);

	return 0;
}