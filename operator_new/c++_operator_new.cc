#include<iostream>
using namespace std;

void* operator new (size_t size, void* p, const char* s, int line) {
	cout << "input arguments[0]:p= " << s << " , and arguments[1]:line=" << line<< endl;
}
class A {
};
int main(int argv, char ** argc) {
	A a;
	A* pa = new(&a, "hello, workd", __LINE__)A();
	return 0;
}
