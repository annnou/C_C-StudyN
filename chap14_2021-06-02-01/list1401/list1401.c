// �z��͌Œ蒷�Ő錾���Ȃ��Ƃ����Ȃ�

#include <stdio.h>
#define NUMBERS_COUNT 10

int main() {
	size_t count = 0;
	// �K���z��̗v�f���̓R���p�C�����Ɍ��肵�Ă��Ȃ��Ƃ����Ȃ�
	int numbers[NUMBERS_COUNT] = { 0 };

	// ���͂���v�f��
	printf("�v�f�� : ");	scanf_s("%zu", &count);

	// ������numbers�̃������[��K�v�ȃT�C�Y�Ŋm�ۂ������I

	// �z��̗v�f�Ƀf�[�^�����
	for (size_t index = 0; index < count; index++) {
		printf("numbers[%zu] : ", index);	scanf_s("%d", &numbers[index]);
	}

	// �z��̗v�f�����ׂĕ\��
	for (size_t index = 0; index < count; index++) {
		printf("numbers[%zu] : %d\n", index, numbers[index]);
	}

	return 0;
}