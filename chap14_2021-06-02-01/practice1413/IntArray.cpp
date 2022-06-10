#include "IntArray.h"
#include <cstdio>
#include <cstdlib>

// このオブジェクトを初期化します。
IntArray::IntArray(size_t capacity) {
	this->capacity = capacity;
	count = 0;
	// 入力する要素数がちょうど格納できるメモリーを動的に確保
	data = new int[sizeof(int) * capacity];
	if (data == nullptr) {
		perror("動的メモリーが確保できませんでした。");
		exit(-1);
	}
}

// IntArrayオブジェクトを解放します。
IntArray::~IntArray() {
	delete[] data;
}

// 配列に格納できる要素数を取得します。
size_t IntArray::GetCapacity() const
{
	return capacity;
}

// 配列に追加されている要素数を取得します。
size_t IntArray::GetCount() const
{
	return count;
}

// 指定したインデックス番目の値を取得します。
int IntArray::GetAt(size_t index) {
	return data[index];
}

// 配列の末尾に指定した値を追加します。
void IntArray::Add(int value) {
	// 配列容量が足りない場合
	if (count == capacity) {
		// 配列サイズを拡張する
		size_t newCapacity = capacity * 2;
		int* newData = new int[newCapacity];
		if (newData == nullptr) {
			perror("動的メモリーが確保できませんでした。");
			exit(-1);
		}
		// 新領域にデータを複製
		for (size_t index = 0; index < count; index++) {
			newData[index] = GetAt(index);
		}
		// 古いメモリーを解放して新領域を使用するように変更
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}
	*(data + count) = value;
	count++;
}

// 指定したインデックス位置の要素を削除します。
void IntArray::Remove(size_t index) {
	// 削除位置から最後の要素までを一つ前にずらす
	for (size_t i = index; i < count - 1; i++) {
		data[i] = data[i + 1];
	}
	// 要素数を一つ減らす
	count--;
}
