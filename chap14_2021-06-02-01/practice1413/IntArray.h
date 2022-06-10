#pragma once

// int型の配列を管理します。
class IntArray {
public:
	// このオブジェクトを初期化します。
	IntArray(size_t capacity);
	// IntArrayオブジェクトを解放します。
	~IntArray();

	// 配列に格納できる要素数を取得します。
	size_t GetCapacity() const;
	// 配列に追加されている要素数を取得します。
	size_t GetCount() const;
	// 指定したインデックス番目の値を取得します。
	int GetAt(size_t index);

	int operator[](size_t index) const { return data[index]; }
	int& operator[](size_t index) { return data[index]; }

	// 配列の末尾に指定した値を追加します。
	void Add(int value);
	// 指定したインデックス位置の要素を削除します。
	void Remove(size_t index);

private:
	size_t capacity;	// この配列に追加できる最大要素数
	size_t count;		// 現在追加されている要素数
	int* data;
};
