#include<iostream>
using namespace std;
struct TestStruct {
	int i;
	void(*func)(int);
	int a[0];
};
struct Test2{
	int i;
	void(*func)(int);
};
class Base{
public:
	int a;
	virtual void Vfunc() {
		cout << "call Base::Vfunc()" << endl;
	}
	virtual void Vfunc0() {
		cout << "call Base::Vfunc0()" << endl;
	}
};

class B1 : public Base {
	public :
		virtual void Vfunc() {
			cout << "call B1::Vfunc() \n";
		}
		virtual void VfuncB1() {
			cout << " call B1::VfuncB1() \n";
		}
};
class B2: public Base {
public:
	virtual void Vfunc() {
		cout << "call B2::Vfunc()\n";
	}
	virtual void VfuncB2() {
		cout << "call B2::VfuncB2\n";
	}
};
class C: public B1, public B2 {
public:
	virtual void Vfunc() {
		cout << "call C::Vfunc()\n";
	}
	virtual void VfuncC() {
		cout << "call C:VfuncC() \n";
	}
};
	
	

typedef void (*Fun)(void);
typedef void* VOID;
int main(int argc, char** argv) {

	cout << "struct TestStruct { int a; void(*func)(int); int a[0];} \n";
	cout << "sizeof(int) = " << sizeof(int) << endl;
	cout << "sizeof (TestStruct)=" << sizeof(TestStruct) << endl;
	cout << "struct Test2 { int a; void(*func)(int);} \n";
	cout << "sizeof(Test2) = " << sizeof(Test2) << endl;
	Base b1;
    Base b2;
	int * vptr1 = (int *)(&b1);
	int * vptr2 = (int *)(&b2);
	cout << "Base b1, b2;" << endl;
	cout << "(int*)(&b1)=" << vptr1 << endl;
	cout << "(int*)(&b2)=" << vptr2 << endl;
	cout << "&b1=" << &b1 << endl;
	cout << "&b2=" << &b2 << endl;
	cout << "(void*)*(void*)(&b1) not work, but\n";
	//cout << "after typedef void* VOID, (VOID*)*(VOID*)(&b1) =: " << (VOID*)*(VOID*)(&b1) << endl;
	cout << "(Fun*)*(Fun*)(&b1)=" << (Fun*)*(Fun*)(&b1) << endl;
	cout << "(int*)*(int*)(&b1)=" << (int*)*(int*)(&b1) << endl;
	cout << "(int*)*(int*)(&b2)=" << (int*)*(int*)(&b2) << endl;
	cout << "*(int*)*(int*)(&b1)=" << *(int*)*(int*)(&b1) << endl;
	cout << "*(int*)*(int*)(&b2)=" << *(int*)*(int*)(&b2) << endl;
	cout << "(int*)(*(int*)(&b2) + 1)=" << (int*)(*(int*)(&b2) + 1) << endl;
	cout << "(int*)(*(int*)(&b2) + sizeof(void*))=" << (int*)(*(int*)(&b2) + sizeof(void*)) << endl;
	cout << "(int*)*(int*)(&b2) + 1=" << (int*)*(int*)(&b2) + 1 << endl;
	cout << "*** Please notice that 32bit and 64bit are different *** \n";
	cout << "*((int*)*(int*)(&b2) + 1)=" <<*((int*)*(int*)(&b2) + 1) << endl;
	cout << "(Fun*)(*(Fun*)(&b2)) + 1 = " << (Fun*)(*(Fun*)(&b2)) + 1 << endl;

	Fun f = (Fun)*((int*)*(int*)(&b1));
	f();
	auto f1 = (Fun)*((Fun*)(*(Fun*)(&b1)) + 1);
	f1();

	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(B1) = " << sizeof(B1) << endl;
	cout << "sizeof(B2) = " << sizeof(B2) << endl;
	cout << "sizeof(C) = " << sizeof(C) << endl;
	return 0;
}
