// ヘッダーファイルと実装ファイルに分離

#include "IntArray.h"
#include <cstdio>

// 配列の要素をすべて表示
void PrintIntArray(const IntArray* numbers) {
	for (size_t index = 0; index < numbers->GetCount(); index++) {
		printf("numbers[%zu] : %d\n", index, (*numbers)[index]);
	}
}

int main() {
	IntArray* numbers = new IntArray(3);

	numbers->Add(10);	// 0
	numbers->Add(20);	// 1
	numbers->Add(30);	// 2
	(*numbers)[0] = 0;
	// 配列の要素をすべて表示
	for (size_t index = 0; index < numbers->GetCount(); index++) {
		printf("numbers[%zu] : %d\n", index, numbers->GetAt(index));
	}
	//// 配列の要素をすべて表示
	//for (size_t index = 0; index < numbers->GetCount(); index++) {
	//	printf("numbers[%zu] : %d\n", index, (*numbers)[index]);
	//}

	PrintIntArray(numbers);

	printf("count : %zu\n", numbers->GetCount());

	delete numbers;

	return 0;
}