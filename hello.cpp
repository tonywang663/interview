#include <iostream>
#include <thread>

using namespace std;


void hello(){
	cout << "hello Concurrent world\n";
}

struct func{
	void operator()(){
		cout << "hello func" << endl;
	}

};


void  mainhello(){

	thread t(hello);
	thread t1([]{cout << "hello lambda" << endl; });
	thread t2((func()));
	t.join();
	t1.join();
	t2.detach();
	system("pause");
}