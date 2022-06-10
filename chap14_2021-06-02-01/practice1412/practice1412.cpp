// �\���̂̒�`�Ǝ����̕���

#include <cstdio>
#include <cstdlib>

// int�^�̔z����Ǘ����܂��B
struct IntArray {
private:
	size_t capacity;	// ���̔z��ɒǉ��ł���ő�v�f��
	size_t count;		// ���ݒǉ�����Ă���v�f��
	int* data;

public:
	// ���̃I�u�W�F�N�g�����������܂��B
	IntArray(size_t capacity);
	// IntArray�I�u�W�F�N�g��������܂��B
	~IntArray();

	// �z��Ɋi�[�ł���v�f�����擾���܂��B
	size_t GetCapacity();
	// �z��ɒǉ�����Ă���v�f�����擾���܂��B
	size_t GetCount();
	// �w�肵���C���f�b�N�X�Ԗڂ̒l���擾���܂��B
	int GetAt(size_t index);

	// �z��̖����Ɏw�肵���l��ǉ����܂��B
	void Add(int value);
	// �w�肵���C���f�b�N�X�ʒu�̗v�f���폜���܂��B
	void Remove(size_t index);
};

// ���̃I�u�W�F�N�g�����������܂��B
IntArray::IntArray(size_t capacity) {
	this->capacity = capacity;
	count = 0;
	// ���͂���v�f�������傤�Ǌi�[�ł��郁�����[�𓮓I�Ɋm��
	data = new int[sizeof(int) * capacity];
	if (data == nullptr) {
		perror("���I�������[���m�ۂł��܂���ł����B");
		exit(-1);
	}
}

// IntArray�I�u�W�F�N�g��������܂��B
IntArray::~IntArray() {
	delete[] data;
}

// �z��Ɋi�[�ł���v�f�����擾���܂��B
size_t IntArray::GetCapacity() {
	return capacity;
}

// �z��ɒǉ�����Ă���v�f�����擾���܂��B
size_t IntArray::GetCount() {
	return count;
}

// �w�肵���C���f�b�N�X�Ԗڂ̒l���擾���܂��B
int IntArray::GetAt(size_t index) {
	return data[index];
}

// �z��̖����Ɏw�肵���l��ǉ����܂��B
void IntArray::Add(int value) {
	// �z��e�ʂ�����Ȃ��ꍇ
	if (count == capacity) {
		// �z��T�C�Y���g������
		size_t newCapacity = capacity * 2;
		int* newData = new int[newCapacity];
		if (newData == nullptr) {
			perror("���I�������[���m�ۂł��܂���ł����B");
			exit(-1);
		}
		// �V�̈�Ƀf�[�^�𕡐�
		for (size_t index = 0; index < count; index++) {
			newData[index] = GetAt(index);
		}
		// �Â��������[��������ĐV�̈���g�p����悤�ɕύX
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}
	*(data + count) = value;
	count++;
}

// �w�肵���C���f�b�N�X�ʒu�̗v�f���폜���܂��B
void IntArray::Remove(size_t index) {
	// �폜�ʒu����Ō�̗v�f�܂ł���O�ɂ��炷
	for (size_t i = index; i < count - 1; i++) {
		data[i] = data[i + 1];
	}
	// �v�f��������炷
	count--;
}

int main() {
	IntArray* numbers = new IntArray(3);

	numbers->Add(10);	// 0
	numbers->Add(20);	// 1
	numbers->Add(30);	// 2
	// �z��̗v�f�����ׂĕ\��
	for (size_t index = 0; index < numbers->GetCount(); index++) {
		printf("numbers[%zu] : %d\n", index, numbers->GetAt(index));
	}
	printf("count : %zu\n", numbers->GetCount());

	delete numbers;

	return 0;
}