// ���K14-14
// �����܂ŉ�����Ă������I�z��Ɠ����̋@�\�Ƃ��āAC++����STL���C�u�����[��vector
// �R���e�i�[�N���X�̎g�����𒲂ׂȂ����B

#include <vector>
#include <cstdio>
using namespace std;

int main() {
	vector<int> numbers;
	numbers.reserve(3);

	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	// �z��̗v�f�����ׂĕ\��
	for (size_t index = 0; index < numbers.size(); index++) {
		printf("numbers[%zu] : %d\n", index, numbers.at(index));
	}
	puts("========================================");
	numbers[0] = 100;
	numbers[1] = 200;
	numbers[2] = 300;
	// �z��̗v�f�����ׂĕ\��
	for (size_t index = 0; index < numbers.size(); index++) {
		printf("numbers[%zu] : %d\n", index, numbers[index]);
	}
	puts("========================================");
	// �z��̗v�f�����ׂĕ\��
	for (auto number : numbers) {
		printf("numbers : %d\n", number);
	}
	puts("========================================");

	// �z��̗v�f�����ׂĕ\��
	for (auto itr = numbers.begin(); itr != numbers.end(); itr++) {
		printf("numbers : %d\n", *itr);
	}
	puts("========================================");

	printf("count : %zu\n", numbers.size());

	return 0;
}