// 配列とその要素数を構造体で管理する。

#include <stdio.h>
#include <stdlib.h>

// int型の配列を管理します。
typedef struct {
	size_t count;
	int* data;
} IntArray;

int main() {
	IntArray numbers;
	// 初期化
	numbers.count = 0;
	numbers.data = NULL;

	// 入力する要素数
	printf("要素数 : ");	scanf_s("%zu", &numbers.count);

	// 入力する要素数がちょうど格納できるメモリーを動的に確保
	numbers.data = malloc(sizeof(int) * numbers.count);
	if (numbers.data == NULL) {
		perror("動的メモリーが確保できませんでした。");
		return -1;
	}

	// 配列の要素にデータを入力
	for (size_t index = 0; index < numbers.count; index++) {
		printf("numbers[%zu] : ", index);	scanf_s("%d", &numbers.data[index]);
	}

	// 配列の要素をすべて表示
	for (size_t index = 0; index < numbers.count; index++) {
		printf("numbers[%zu] : %d\n", index, numbers.data[index]);
	}

	// 動的に確保したメモリーの解放
	free(numbers.data);

	return 0;
}