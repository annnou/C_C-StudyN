#pragma once

// int�^�̔z����Ǘ����܂��B
class IntArray {
public:
	// ���̃I�u�W�F�N�g�����������܂��B
	IntArray(size_t capacity);
	// IntArray�I�u�W�F�N�g��������܂��B
	~IntArray();

	// �z��Ɋi�[�ł���v�f�����擾���܂��B
	size_t GetCapacity() const;
	// �z��ɒǉ�����Ă���v�f�����擾���܂��B
	size_t GetCount() const;
	// �w�肵���C���f�b�N�X�Ԗڂ̒l���擾���܂��B
	int GetAt(size_t index);

	int operator[](size_t index) const { return data[index]; }
	int& operator[](size_t index) { return data[index]; }

	// �z��̖����Ɏw�肵���l��ǉ����܂��B
	void Add(int value);
	// �w�肵���C���f�b�N�X�ʒu�̗v�f���폜���܂��B
	void Remove(size_t index);

private:
	size_t capacity;	// ���̔z��ɒǉ��ł���ő�v�f��
	size_t count;		// ���ݒǉ�����Ă���v�f��
	int* data;
};
