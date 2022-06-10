// 配列は固定長で宣言しないといけない

#include <stdio.h>
#define NUMBERS_COUNT 10

int main() {
	size_t count = 0;
	// 必ず配列の要素数はコンパイル時に決定していないといけない
	int numbers[NUMBERS_COUNT] = { 0 };

	// 入力する要素数
	printf("要素数 : ");	scanf_s("%zu", &count);

	// ここでnumbersのメモリーを必要なサイズで確保したい！

	// 配列の要素にデータを入力
	for (size_t index = 0; index < count; index++) {
		printf("numbers[%zu] : ", index);	scanf_s("%d", &numbers[index]);
	}

	// 配列の要素をすべて表示
	for (size_t index = 0; index < count; index++) {
		printf("numbers[%zu] : %d\n", index, numbers[index]);
	}

	return 0;
}