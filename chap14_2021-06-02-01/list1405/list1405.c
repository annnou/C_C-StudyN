// 動的にサイズが拡張される配列

#include <stdio.h>
#include <stdlib.h>

// int型の配列を管理します。
typedef struct {
	size_t capacity;	// この配列に追加できる最大要素数
	size_t count;		// 現在追加されている要素数
	int* data;
} IntArray;

// IntArrayオブジェクトを初期化します。
void IntArray_Initialize(IntArray* intArray, size_t capacity) {
	intArray->capacity = capacity;
	intArray->count = 0;
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

// 配列に追加されている要素数を取得します。
size_t IntArray_GetCount(IntArray* intArray) {
	return intArray->count;
}

// 指定したインデックス番目の値を取得します。
int IntArray_GetAt(IntArray* intArray, size_t index) {
	return intArray->data[index];
}

// 配列の末尾に指定した値を追加します。
void IntArray_Add(IntArray* intArray, int value) {
	// 配列容量が足りない場合
	if (intArray->count >= intArray->capacity) {
		// 配列サイズを拡張する
		size_t newCapacity = intArray->capacity * 2;
		int* newData = malloc(sizeof(int) * newCapacity);
		if (newData == NULL) {
			perror("動的メモリーが確保できませんでした。");
			exit(-1);
		}
		// 新領域にデータを複製
		for (size_t index = 0; index < intArray->count; index++) {
			*(newData + index) = IntArray_GetAt(intArray, index);
		}
		// 古いメモリーを解放して新領域を使用するように変更
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

	// 初期化（最大要素数は適当に大きめに設定）
	IntArray_Initialize(&numbers, 3);

	// 入力する要素数
	printf("要素数 : ");	scanf_s("%zu", &count);
	// 配列にデータを追加
	for (size_t index = 0; index < count; index++) {
		int value;
		printf("追加する値を指定してください : ");	scanf_s("%d", &value);
		IntArray_Add(&numbers, value);
	}

	// 配列の要素をすべて表示
	for (size_t index = 0; index < IntArray_GetCount(&numbers); index++) {
		printf("numbers[%zu] : %d\n", index, IntArray_GetAt(&numbers, index));
	}

	// 動的に確保したメモリーの解放
	IntArray_Release(&numbers);

	return 0;
}