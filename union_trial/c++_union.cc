#include<iostream>
using namespace std;
union UnionTest {
	UnionTest() : i(10) {} // default is public
    int i;
	double d;
};

static union{ //global anonymous union must be static
	int i;
	double d;
};

int main(int argc, char** argv) {
	UnionTest u;
	union {  // non-global anonymous union do not have to be static
		int i;
		double d;
	};
	std::cout << "u.i=" << u.i << std::endl;
	::i = 20;
	std::cout << "::i=" << ::i << std::endl;	

	i = 30;
	std::cout << "i=" << i << std::endl;
	return 0;
}
