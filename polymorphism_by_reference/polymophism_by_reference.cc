#include<iostream>
using namespace std;

class A{
public:
	virtual void Vfunc(){
		cout<<"A::Vfunc()"<<'\n';
	}
};
class B : public A {
public:
	virtual void Vfunc() override {
		cout<<"B::Vfunc(), which B inhrit from A" << '\n';
	}
};
int main(int argc, char** argv) {
	B b;
	A& a = b;
	a.Vfunc();
	return 0;
}
	
