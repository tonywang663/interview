#include <iostream>
#include <thread>

using namespace std;

struct func{
	int& i;

	func(int& i_) :i(i_){}

	void operator()(){
		cout << "hello func " << i << endl;
	}
};

class thread_guard{
	thread& t;
public:
	explicit thread_guard(thread& t_) :t(t_){}
	~thread_guard(){
		if (t.joinable()){
			t.join();
			cout << "joined here" << endl;
		}
	}
	thread_guard(thread_guard const&) = delete;
	thread_guard& operator=(thread_guard const&) = delete;
};

void f(){
	int local = 0;
	func my_func(local);
	thread t(my_func);
	thread_guard g(t);
}

void mainfunc(){
	unsigned long const hardware_threads =
		std::thread::hardware_concurrency();
	cout << hardware_threads << endl;
	f();
	system("pause");
}