// new、deleteを使った動的メモリー確保

#include <cstdio>
#include <cstdlib>

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
	intArray->data = new int[sizeof(int) * capacity];
	if (intArray->data == NULL) {
		perror("動的メモリーが確保できませんでした。");
		exit(-1);
	}
}

// IntArrayオブジェクトを解放します。
void IntArray_Release(IntArray* intArray) {
	delete[] intArray->data;
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
	if (intArray->count == intArray->capacity) {
		// 配列サイズを拡張する
		size_t newCapacity = intArray->capacity * 2;
		int* newData = new int[newCapacity];
		if (newData == NULL) {
			perror("動的メモリーが確保できませんでした。");
			exit(-1);
		}
		// 新領域にデータを複製
		for (size_t index = 0; index < intArray->count; index++) {
			newData[index] = IntArray_GetAt(intArray, index);
		}
		// 古いメモリーを解放して新領域を使用するように変更
		delete[] intArray->data;
		intArray->data = newData;
		intArray->capacity = newCapacity;
	}
	*(intArray->data + intArray->count) = value;
	intArray->count++;
}

// 指定したインデックス位置の要素を削除します。
void IntArray_Remove(IntArray* intArray, size_t index) {
	// 削除位置から最後の要素までを一つ前にずらす
	for (size_t i = index; i < intArray->count - 1; i++) {
		intArray->data[i] = intArray->data[i + 1];
	}
	// 要素数を一つ減らす
	intArray->count--;
}

int main() {
	IntArray numbers;

	// 初期化（最大要素数は適当に大きめに設定）
	IntArray_Initialize(&numbers, 3);

	IntArray_Add(&numbers, 10);	// 0
	IntArray_Add(&numbers, 20);	// 1
	IntArray_Add(&numbers, 30); // 2

	// 配列の要素をすべて表示
	for (size_t index = 0; index < IntArray_GetCount(&numbers); index++) {
		printf("numbers[%zu] : %d\n", index, IntArray_GetAt(&numbers, index));
	}
	printf("count : %zu\n", IntArray_GetCount(&numbers));

	IntArray_Remove(&numbers, 1);	// インデックス1の要素(20)が削除される

	puts("==============================");

	// 配列の要素をすべて表示
	for (size_t index = 0; index < IntArray_GetCount(&numbers); index++) {
		printf("numbers[%zu] : %d\n", index, IntArray_GetAt(&numbers, index));
	}
	printf("count : %zu\n", IntArray_GetCount(&numbers));

	// 動的に確保したメモリーの解放
	IntArray_Release(&numbers);

	return 0;
}