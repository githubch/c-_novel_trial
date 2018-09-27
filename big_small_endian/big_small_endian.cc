#include<iostream>
using namespace std;
union {
	int a;
	char b[4];
}*p, u;


int main(int argc, char ** argv) {
	p = &u;
	p->b[0] = '1';
    p->b[1] = '2';
	cout<< "p->a=" << p->a << '\n';
	cout<< "p->b[0]= " << p->b[0] << " p->b[1]=" << p->b[1] << '\n';
	cout<< "&p->b[0]=" << &p->b[0] << " &p->b[1]= "<< &p->b[1]<< '\n'; // TODO 此时并不能打印出地址，count 会将其解析成字符串的首地址，进而打印字符串
	cout<< "&p->b: by cout<<p->b will output the string instead of the address of the string" << p->b << '\n'; // TODO 打印以b为首地址的字符串
	cout<< "&p->a=" << &p->a << '\n';
	cout<< "p->b = " << static_cast<void*>(p->b) << " , by cout << static_cast<void*>(p->b)" << '\n';
	cout<< "&p->b[0]" << static_cast<void*>(&p->b[0]) << ", by cout << static_cast<void*>(p->b[0])" << '\n';
	cout<< "&p->b[1]" << static_cast<void*>(&p->b[1]) << ", by cout << static_cast<void*>(p->b[1])" << '\n';
	cout<< "&p->b[2]" << static_cast<void*>(&p->b[2]) << ", by cout << static_cast<void*>(p->b[2])" << '\n';
	cout<< "&p->b[3]" << static_cast<void*>(&p->b[3]) << ", by cout << static_cast<void*>(p->b[3])" << '\n';


	p->a=1;
	cout << "p->b[0]=" << static_cast<int>(p->b[0]) << '\n';
	cout << "p->a=" << p->a << '\n';
	return 0;
}	
