#include<iostream>
#include<thread>
#include<vector>
#include<algorithm>
using namespace std;

void f(int i) {
	cout << " i = " << i << '\n';
}

int main(int argc, char** argv) {
	vector<thread> threads;
    for(int i = 0;i < 10;i++) {
		//thread t(f, i);
		//threads.push_back(t); // TODO ch: will cause compile error because of using copy constructor, which is declared as 'deleted'
		threads.push_back(thread(f, i));
	}
	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
	return 0;
}
