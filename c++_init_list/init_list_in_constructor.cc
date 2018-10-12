#include<iostream>
using namespace std;

class A {
public:
	A(int dummy):n2(n1+2),n1(0) { // It seems like init from right to left, but wrong...

	}
	A():n2(0),n1(n2+2) { // It seems init from right to left, but wrong...
	}
	A(int dummy, int dummy1): n1(n2+2), n2(0) { // good case
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
	A a2(1, 1);
	a2.Print();
	return 0;
}

