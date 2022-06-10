// メモリーの動的確保

#include <stdio.h>
#include <stdlib.h>

int main() {
	size_t count = 0;
	int* numbers = NULL;

	// 入力する要素数
	printf("要素数 : ");	scanf_s("%zu", &count);

	// 入力する要素数がちょうど格納できるメモリーを動的に確保
	numbers = malloc(sizeof(int) * count);
	if (numbers != NULL) {
		perror("動的メモリーが確保できませんでした。");
		return -1;
	}

	// 配列の要素にデータを入力
	for (size_t index = 0; index < count; index++) {
		printf("numbers[%zu] : ", index);	scanf_s("%d", &numbers[index]);
	}

	// 配列の要素をすべて表示
	for (size_t index = 0; index < count; index++) {
		printf("numbers[%zu] : %d\n", index, numbers[index]);
	}

	// 動的に確保したメモリーの解放
	free(numbers);

	return 0;
}
