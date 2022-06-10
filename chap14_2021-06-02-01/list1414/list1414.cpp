// 演習14-14
// ここまで解説してきた動的配列と同等の機能として、C++言語STLライブラリーのvector
// コンテナークラスの使い方を調べなさい。

#include <vector>
#include <cstdio>
using namespace std;

int main() {
	vector<int> numbers;
	numbers.reserve(3);

	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	// 配列の要素をすべて表示
	for (size_t index = 0; index < numbers.size(); index++) {
		printf("numbers[%zu] : %d\n", index, numbers.at(index));
	}
	puts("========================================");
	numbers[0] = 100;
	numbers[1] = 200;
	numbers[2] = 300;
	// 配列の要素をすべて表示
	for (size_t index = 0; index < numbers.size(); index++) {
		printf("numbers[%zu] : %d\n", index, numbers[index]);
	}
	puts("========================================");
	// 配列の要素をすべて表示
	for (auto number : numbers) {
		printf("numbers : %d\n", number);
	}
	puts("========================================");

	// 配列の要素をすべて表示
	for (auto itr = numbers.begin(); itr != numbers.end(); itr++) {
		printf("numbers : %d\n", *itr);
	}
	puts("========================================");

	printf("count : %zu\n", numbers.size());

	return 0;
}