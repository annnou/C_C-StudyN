// �����o�[�֐�

#include <cstdio>
#include <cstdlib>

// int�^�̔z����Ǘ����܂��B
struct IntArray {
	size_t capacity;	// ���̔z��ɒǉ��ł���ő�v�f��
	size_t count;		// ���ݒǉ�����Ă���v�f��
	int* data;

	// IntArray�I�u�W�F�N�g�����������܂��B
	void Initialize(size_t capacity) {
		this->capacity = capacity;
		this->count = 0;
		// ���͂���v�f�������傤�Ǌi�[�ł��郁�����[�𓮓I�Ɋm��
		this->data = new int[sizeof(int) * capacity];
		if (this->data == NULL) {
			perror("���I�������[���m�ۂł��܂���ł����B");
			exit(-1);
		}
	}

	// IntArray�I�u�W�F�N�g��������܂��B
	void Release() {
		delete[] this->data;
	}

	// �z��Ɋi�[�ł���v�f�����擾���܂��B
	size_t GetCapacity() {
		return this->capacity;
	}

	// �z��ɒǉ�����Ă���v�f�����擾���܂��B
	size_t GetCount() {
		return this->count;
	}

	// �w�肵���C���f�b�N�X�Ԗڂ̒l���擾���܂��B
	int GetAt(size_t index) {
		return this->data[index];
	}

	// �z��̖����Ɏw�肵���l��ǉ����܂��B
	void Add(int value) {
		// �z��e�ʂ�����Ȃ��ꍇ
		if (this->count == this->capacity) {
			// �z��T�C�Y���g������
			size_t newCapacity = this->capacity * 2;
			int* newData = new int[newCapacity];
			if (newData == NULL) {
				perror("���I�������[���m�ۂł��܂���ł����B");
				exit(-1);
			}
			// �V�̈�Ƀf�[�^�𕡐�
			for (size_t index = 0; index < this->count; index++) {
				newData[index] = this->GetAt(index);
			}
			// �Â��������[��������ĐV�̈���g�p����悤�ɕύX
			delete[] this->data;
			this->data = newData;
			this->capacity = newCapacity;
		}
		*(this->data + this->count) = value;
		this->count++;
	}

	// �w�肵���C���f�b�N�X�ʒu�̗v�f���폜���܂��B
	void Remove(size_t index) {
		// �폜�ʒu����Ō�̗v�f�܂ł���O�ɂ��炷
		for (size_t i = index; i < this->count - 1; i++) {
			this->data[i] = this->data[i + 1];
		}
		// �v�f��������炷
		this->count--;
	}
};

int main() {
	IntArray numbers;

	// �������i�ő�v�f���͓K���ɑ傫�߂ɐݒ�j
	numbers.Initialize(3);

	numbers.Add(10);	// 0
	numbers.Add(20);	// 1
	numbers.Add(30); // 2

	// �z��̗v�f�����ׂĕ\��
	for (size_t index = 0; index < numbers.GetCount(); index++) {
		printf("numbers[%zu] : %d\n", index, numbers.GetAt(index));
	}
	printf("count : %zu\n", numbers.GetCount());

	numbers.Remove(1);	// �C���f�b�N�X1�̗v�f(20)���폜�����

	puts("==============================");

	// �z��̗v�f�����ׂĕ\��
	for (size_t index = 0; index < numbers.GetCount(); index++) {
		printf("numbers[%zu] : %d\n", index, numbers.GetAt(index));
	}
	printf("count : %zu\n", numbers.GetCount());

	// ���I�Ɋm�ۂ����������[�̉��
	numbers.Release();

	return 0;
}