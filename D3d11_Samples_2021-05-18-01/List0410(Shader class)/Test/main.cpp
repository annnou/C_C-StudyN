#include <new>

class Sample
{
	char values1[INT_MAX];
	char values2[INT_MAX];
};

int main(void)
{
	// ��O���X���[���Ȃ�new���Z�q
	Sample* sample = new Sample();
	//Sample* sample = new(std::nothrow) Sample();

	delete sample;

	return 0;
}