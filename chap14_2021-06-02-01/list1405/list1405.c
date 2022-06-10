// ���I�ɃT�C�Y���g�������z��

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
	if (intArray->count >= intArray->capacity) {
		// �z��T�C�Y���g������
		size_t newCapacity = intArray->capacity * 2;
		int* newData = malloc(sizeof(int) * newCapacity);
		if (newData == NULL) {
			perror("���I�������[���m�ۂł��܂���ł����B");
			exit(-1);
		}
		// �V�̈�Ƀf�[�^�𕡐�
		for (size_t index = 0; index < intArray->count; index++) {
			*(newData + index) = IntArray_GetAt(intArray, index);
		}
		// �Â��������[��������ĐV�̈���g�p����悤�ɕύX
		free(intArray->data);
		intArray->data = newData;
		intArray->capacity = newCapacity;
	}
	*(intArray->data + intArray->count) = value;
	intArray->count++;
}

int main() {
	size_t count = 0;
	IntArray numbers;

	// �������i�ő�v�f���͓K���ɑ傫�߂ɐݒ�j
	IntArray_Initialize(&numbers, 3);

	// ���͂���v�f��
	printf("�v�f�� : ");	scanf_s("%zu", &count);
	// �z��Ƀf�[�^��ǉ�
	for (size_t index = 0; index < count; index++) {
		int value;
		printf("�ǉ�����l���w�肵�Ă������� : ");	scanf_s("%d", &value);
		IntArray_Add(&numbers, value);
	}

	// �z��̗v�f�����ׂĕ\��
	for (size_t index = 0; index < IntArray_GetCount(&numbers); index++) {
		printf("numbers[%zu] : %d\n", index, IntArray_GetAt(&numbers, index));
	}

	// ���I�Ɋm�ۂ����������[�̉��
	IntArray_Release(&numbers);

	return 0;
}