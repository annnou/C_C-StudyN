// 配列構造体とその処理関数を実装する。

#include <stdio.h>
#include <stdlib.h>

// int型の配列を管理します。
typedef struct {
	size_t capacity;
	int* data;
} IntArray;

// IntArrayオブジェクトを初期化します。
void IntArray_Initialize(IntArray* intArray, size_t capacity) {
	intArray->capacity = capacity;
	// 入力する要素数がちょうど格納できるメモリーを動的に確保
	intArray->data = malloc(sizeof(int) * capacity);
	if (intArray->data == NULL) {
		perror("動的メモリーが確保できませんでした。");
		exit(-1);
	}
}

// IntArrayオブジェクトを解放します。
void IntArray_Release(IntArray* intArray) {
	free(intArray->data);
}

// 配列に格納できる要素数を取得します。
size_t IntArray_GetCapacity(IntArray* intArray) {
	return intArray->capacity;
}

// 指定したインデックス番目の値を取得します。
int IntArray_GetAt(IntArray* intArray, size_t index) {
	return intArray->data[index];
}

// 指定したインデックス番目に値を設定します。
void IntArray_SetValue(IntArray* intArray, size_t index, int value) {
	intArray->data[index] = value;
}

int main() {
	size_t count = 0;
	IntArray numbers;

	// 入力する要素数
	printf("要素数 : ");	scanf_s("%zu", &count);
	// 初期化
	IntArray_Initialize(&numbers, count);

	// 配列の要素にデータを入力
	for (size_t index = 0; index < IntArray_GetCapacity(&numbers); index++) {
		int value;
		printf("numbers[%zu] : ", index);	scanf_s("%d", &value);
		IntArray_SetValue(&numbers, index, value);
	}

	// 配列の要素をすべて表示
	for (size_t index = 0; index < IntArray_GetCapacity(&numbers); index++) {
		printf("numbers[%zu] : %d\n", index, IntArray_GetAt(&numbers, index));
	}

	// 動的に確保したメモリーの解放
	IntArray_Release(&numbers);

	return 0;
}