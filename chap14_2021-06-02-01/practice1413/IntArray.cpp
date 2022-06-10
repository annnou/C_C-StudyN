#include "IntArray.h"
#include <cstdio>
#include <cstdlib>

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
size_t IntArray::GetCapacity() const
{
	return capacity;
}

// �z��ɒǉ�����Ă���v�f�����擾���܂��B
size_t IntArray::GetCount() const
{
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
