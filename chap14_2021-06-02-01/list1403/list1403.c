// �z��Ƃ��̗v�f�����\���̂ŊǗ�����B

#include <stdio.h>
#include <stdlib.h>

// int�^�̔z����Ǘ����܂��B
typedef struct {
	size_t count;
	int* data;
} IntArray;

int main() {
	IntArray numbers;
	// ������
	numbers.count = 0;
	numbers.data = NULL;

	// ���͂���v�f��
	printf("�v�f�� : ");	scanf_s("%zu", &numbers.count);

	// ���͂���v�f�������傤�Ǌi�[�ł��郁�����[�𓮓I�Ɋm��
	numbers.data = malloc(sizeof(int) * numbers.count);
	if (numbers.data == NULL) {
		perror("���I�������[���m�ۂł��܂���ł����B");
		return -1;
	}

	// �z��̗v�f�Ƀf�[�^�����
	for (size_t index = 0; index < numbers.count; index++) {
		printf("numbers[%zu] : ", index);	scanf_s("%d", &numbers.data[index]);
	}

	// �z��̗v�f�����ׂĕ\��
	for (size_t index = 0; index < numbers.count; index++) {
		printf("numbers[%zu] : %d\n", index, numbers.data[index]);
	}

	// ���I�Ɋm�ۂ����������[�̉��
	free(numbers.data);

	return 0;
}