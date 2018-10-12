#include<iostream>
using namespace std;

class A {
public:
	A(int dummy):n2(n1+2),n1(0) { // Init from right to left

	}
	A():n2(0),n1(n2+2) { // Init from right to left
	}
	void Print() {
		cout << "n1=" << n1 << " ,n2=" << n2 << endl;
	}
private:
	int n1;
	int n2;
};

int main(int argc, char** argv) {
	A a;
	a.Print();
	A a1(1);
	a1.Print();	
	return 0;
}

