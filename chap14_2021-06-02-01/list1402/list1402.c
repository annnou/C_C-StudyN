// �������[�̓��I�m��

#include <stdio.h>
#include <stdlib.h>

int main() {
	size_t count = 0;
	int* numbers = NULL;

	// ���͂���v�f��
	printf("�v�f�� : ");	scanf_s("%zu", &count);

	// ���͂���v�f�������傤�Ǌi�[�ł��郁�����[�𓮓I�Ɋm��
	numbers = malloc(sizeof(int) * count);
	if (numbers != NULL) {
		perror("���I�������[���m�ۂł��܂���ł����B");
		return -1;
	}

	// �z��̗v�f�Ƀf�[�^�����
	for (size_t index = 0; index < count; index++) {
		printf("numbers[%zu] : ", index);	scanf_s("%d", &numbers[index]);
	}

	// �z��̗v�f�����ׂĕ\��
	for (size_t index = 0; index < count; index++) {
		printf("numbers[%zu] : %d\n", index, numbers[index]);
	}

	// ���I�Ɋm�ۂ����������[�̉��
	free(numbers);

	return 0;
}
