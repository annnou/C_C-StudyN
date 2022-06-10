// 構造体の定義と実装の分離

#include <cstdio>
#include <cstdlib>

// int型の配列を管理します。
struct IntArray {
private:
	size_t capacity;	// この配列に追加できる最大要素数
	size_t count;		// 現在追加されている要素数
	int* data;

public:
	// このオブジェクトを初期化します。
	IntArray(size_t capacity);
	// IntArrayオブジェクトを解放します。
	~IntArray();

	// 配列に格納できる要素数を取得します。
	size_t GetCapacity();
	// 配列に追加されている要素数を取得します。
	size_t GetCount();
	// 指定したインデックス番目の値を取得します。
	int GetAt(size_t index);

	// 配列の末尾に指定した値を追加します。
	void Add(int value);
	// 指定したインデックス位置の要素を削除します。
	void Remove(size_t index);
};

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
size_t IntArray::GetCapacity() {
	return capacity;
}

// 配列に追加されている要素数を取得します。
size_t IntArray::GetCount() {
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

int main() {
	IntArray* numbers = new IntArray(3);

	numbers->Add(10);	// 0
	numbers->Add(20);	// 1
	numbers->Add(30);	// 2
	// 配列の要素をすべて表示
	for (size_t index = 0; index < numbers->GetCount(); index++) {
		printf("numbers[%zu] : %d\n", index, numbers->GetAt(index));
	}
	printf("count : %zu\n", numbers->GetCount());

	delete numbers;

	return 0;
}