// メンバー関数

#include <cstdio>
#include <cstdlib>

// int型の配列を管理します。
struct IntArray {
	size_t capacity;	// この配列に追加できる最大要素数
	size_t count;		// 現在追加されている要素数
	int* data;

	// IntArrayオブジェクトを初期化します。
	void Initialize(size_t capacity) {
		this->capacity = capacity;
		this->count = 0;
		// 入力する要素数がちょうど格納できるメモリーを動的に確保
		this->data = new int[sizeof(int) * capacity];
		if (this->data == NULL) {
			perror("動的メモリーが確保できませんでした。");
			exit(-1);
		}
	}

	// IntArrayオブジェクトを解放します。
	void Release() {
		delete[] this->data;
	}

	// 配列に格納できる要素数を取得します。
	size_t GetCapacity() {
		return this->capacity;
	}

	// 配列に追加されている要素数を取得します。
	size_t GetCount() {
		return this->count;
	}

	// 指定したインデックス番目の値を取得します。
	int GetAt(size_t index) {
		return this->data[index];
	}

	// 配列の末尾に指定した値を追加します。
	void Add(int value) {
		// 配列容量が足りない場合
		if (this->count == this->capacity) {
			// 配列サイズを拡張する
			size_t newCapacity = this->capacity * 2;
			int* newData = new int[newCapacity];
			if (newData == NULL) {
				perror("動的メモリーが確保できませんでした。");
				exit(-1);
			}
			// 新領域にデータを複製
			for (size_t index = 0; index < this->count; index++) {
				newData[index] = this->GetAt(index);
			}
			// 古いメモリーを解放して新領域を使用するように変更
			delete[] this->data;
			this->data = newData;
			this->capacity = newCapacity;
		}
		*(this->data + this->count) = value;
		this->count++;
	}

	// 指定したインデックス位置の要素を削除します。
	void Remove(size_t index) {
		// 削除位置から最後の要素までを一つ前にずらす
		for (size_t i = index; i < this->count - 1; i++) {
			this->data[i] = this->data[i + 1];
		}
		// 要素数を一つ減らす
		this->count--;
	}
};

int main() {
	IntArray numbers;

	// 初期化（最大要素数は適当に大きめに設定）
	numbers.Initialize(3);

	numbers.Add(10);	// 0
	numbers.Add(20);	// 1
	numbers.Add(30); // 2

	// 配列の要素をすべて表示
	for (size_t index = 0; index < numbers.GetCount(); index++) {
		printf("numbers[%zu] : %d\n", index, numbers.GetAt(index));
	}
	printf("count : %zu\n", numbers.GetCount());

	numbers.Remove(1);	// インデックス1の要素(20)が削除される

	puts("==============================");

	// 配列の要素をすべて表示
	for (size_t index = 0; index < numbers.GetCount(); index++) {
		printf("numbers[%zu] : %d\n", index, numbers.GetAt(index));
	}
	printf("count : %zu\n", numbers.GetCount());

	// 動的に確保したメモリーの解放
	numbers.Release();

	return 0;
}