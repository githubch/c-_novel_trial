#include<iostream>
// Conclusion: the object memory model diffs , which depends on the gcc version and VC
using namespace std;
class A {
public: 
	virtual void VfuncA() {
		cout << "call A::VfuncA()" << endl;
	}
};
class A1:virtual public A {
public:
	virtual void VfuncA() {
		cout << "call A1::A::VfuncA() " << endl;
	}
	virtual void VfuncA1() {
		cout << " call A1:: VfuncA1() " << endl;
	}
	virtual void VVfuncA1() {
		cout << "call A1::VVfucnA1() " << endl;
	}
};

class B {
public:
	//int d = 2;
	virtual void Vfun() {
		cout << "call B::Vfunc() " << endl;
	};
};

class B1: virtual public B {
public:
	int d1;
	virtual void Vfun() {
		cout << "call B1::Vfunc() " << endl;
	};
	virtual void VfuncB1() {
		cout << "call B1::VfuncB1() " << endl;
	}
};

typedef void(*Fun)(void);
int main(int argv, char** argc) {
	cout << "sizoef(A) = " << sizeof(A) << endl;
	cout << "sizeof(A1) = " << sizeof(A1) << endl;
	cout << "sizeof(B) = " << sizeof(B) << endl;
	cout << "sizeof(B1) = " << sizeof(B1) << endl;	
	cout << "Upper shows thats the memory structure are different if the base class has data member for virtual inhritation cases" << endl;
	B1 b1;
	cout << "(long*)(&b1)=" << (long*)(&b1) << endl;
	cout << "(long*)*(long*)(&b1)=" << (long*)*(long*)(&b1) << endl;	
	cout << "call function: ((Fun)(*(long*)*(long*)(&b1)))(), and the result is : " ;
	 ((Fun)(*(long*)*(long*)(&b1)))();
	cout << "call function: ((Fun)(*((long*)*(long*)(&b1) + 1)))(), and the result is : " ;
	 ((Fun)(*((long*)*(long*)(&b1)+1)))();
	cout << "(long*)(&b1) + 1=" << (long*)(&b1) + 1 << endl;
	cout << "(long*)*((long*)(&b1) + 1)=" << (long*)*((long*)(&b1) + 1) << endl;
	cout << "*(long*)*((long*)(&b1) + 1)=" << *(long*)*((long*)(&b1) + 1) << endl;
	cout << "call ((Fun)*((long*)(*((long*)(&b1) + 1))))(), and the result is : " ;
	 ((Fun)*((long*)(*((long*)(&b1) + 1))))() ;
	cout << "*((long*)(&b1) + 2)=" << *((long*)(&b1) + 2) << endl;
	//cout << "*((long*)(*((long*)(&b1) + 2)))=" << *((long*)(*((long*)(&b1) + 2))) << endl;
	return 0;
}
