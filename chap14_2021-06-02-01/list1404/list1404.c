// �z��\���̂Ƃ��̏����֐�����������B

#include <stdio.h>
#include <stdlib.h>

// int�^�̔z����Ǘ����܂��B
typedef struct {
	size_t capacity;
	int* data;
} IntArray;

// IntArray�I�u�W�F�N�g�����������܂��B
void IntArray_Initialize(IntArray* intArray, size_t capacity) {
	intArray->capacity = capacity;
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

// �w�肵���C���f�b�N�X�Ԗڂ̒l���擾���܂��B
int IntArray_GetAt(IntArray* intArray, size_t index) {
	return intArray->data[index];
}

// �w�肵���C���f�b�N�X�Ԗڂɒl��ݒ肵�܂��B
void IntArray_SetValue(IntArray* intArray, size_t index, int value) {
	intArray->data[index] = value;
}

int main() {
	size_t count = 0;
	IntArray numbers;

	// ���͂���v�f��
	printf("�v�f�� : ");	scanf_s("%zu", &count);
	// ������
	IntArray_Initialize(&numbers, count);

	// �z��̗v�f�Ƀf�[�^�����
	for (size_t index = 0; index < IntArray_GetCapacity(&numbers); index++) {
		int value;
		printf("numbers[%zu] : ", index);	scanf_s("%d", &value);
		IntArray_SetValue(&numbers, index, value);
	}

	// �z��̗v�f�����ׂĕ\��
	for (size_t index = 0; index < IntArray_GetCapacity(&numbers); index++) {
		printf("numbers[%zu] : %d\n", index, IntArray_GetAt(&numbers, index));
	}

	// ���I�Ɋm�ۂ����������[�̉��
	IntArray_Release(&numbers);

	return 0;
}