// new�Adelete���g�������I�������[�m��

#include <cstdio>
#include <cstdlib>

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
	intArray->data = new int[sizeof(int) * capacity];
	if (intArray->data == NULL) {
		perror("���I�������[���m�ۂł��܂���ł����B");
		exit(-1);
	}
}

// IntArray�I�u�W�F�N�g��������܂��B
void IntArray_Release(IntArray* intArray) {
	delete[] intArray->data;
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
		int* newData = new int[newCapacity];
		if (newData == NULL) {
			perror("���I�������[���m�ۂł��܂���ł����B");
			exit(-1);
		}
		// �V�̈�Ƀf�[�^�𕡐�
		for (size_t index = 0; index < intArray->count; index++) {
			newData[index] = IntArray_GetAt(intArray, index);
		}
		// �Â��������[��������ĐV�̈���g�p����悤�ɕύX
		delete[] intArray->data;
		intArray->data = newData;
		intArray->capacity = newCapacity;
	}
	*(intArray->data + intArray->count) = value;
	intArray->count++;
}

// �w�肵���C���f�b�N�X�ʒu�̗v�f���폜���܂��B
void IntArray_Remove(IntArray* intArray, size_t index) {
	// �폜�ʒu����Ō�̗v�f�܂ł���O�ɂ��炷
	for (size_t i = index; i < intArray->count - 1; i++) {
		intArray->data[i] = intArray->data[i + 1];
	}
	// �v�f��������炷
	intArray->count--;
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

	IntArray_Remove(&numbers, 1);	// �C���f�b�N�X1�̗v�f(20)���폜�����

	puts("==============================");

	// �z��̗v�f�����ׂĕ\��
	for (size_t index = 0; index < IntArray_GetCount(&numbers); index++) {
		printf("numbers[%zu] : %d\n", index, IntArray_GetAt(&numbers, index));
	}
	printf("count : %zu\n", IntArray_GetCount(&numbers));

	// ���I�Ɋm�ۂ����������[�̉��
	IntArray_Release(&numbers);

	return 0;
}