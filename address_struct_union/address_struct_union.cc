#include<iostream>
using namespace std;
typedef struct StructUnion {
	union {
		int* p;
		uintptr_t placehold;
	} next_data;
	int i;
} StructUnion;

int main(int argc, char** argv) {
	StructUnion su;
	cout << "&su=" << &su << " &su.next_data" << &su.next_data << " &su.next_data.p=" << &su.next_data.p << "\n";	
	return 0;
}
