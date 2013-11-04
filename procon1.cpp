#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

struct Buff{
	int* buf;
	int capacity;
	int count;
	int front;
	int rear;
	mutex mut;
	condition_variable not_full;
	condition_variable not_empty;
public:
	Buff(int _cap) : capacity(_cap), count(0), front(0), rear(0){
		buf = new int[capacity];
	}
	~Buff(){
		delete[]buf;
	}
	void deposit(int val){
		unique_lock<mutex> lock(mut);
		
		not_full.wait(lock, [this](){return count != capacity; });


		buf[rear] = val;
		rear = (rear + 1) % capacity;
		count++;
		not_empty.notify_one();
	}

	int fetch(){
		unique_lock<mutex> lock(mut);
		not_empty.wait(lock, [this](){return count != 0; });
		int res = buf[front];
		front = (front + 1) % capacity;
		count--;
		not_full.notify_one();
		return res;
	}
};