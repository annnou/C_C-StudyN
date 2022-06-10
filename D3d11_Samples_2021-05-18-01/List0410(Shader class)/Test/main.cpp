#include <new>

class Sample
{
	char values1[INT_MAX];
	char values2[INT_MAX];
};

int main(void)
{
	// 例外をスローしないnew演算子
	Sample* sample = new Sample();
	//Sample* sample = new(std::nothrow) Sample();

	delete sample;

	return 0;
}