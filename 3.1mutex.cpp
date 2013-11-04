#include <list>
#include <thread>
#include <algorithm>
#include <mutex>

using namespace std;

list<int> some_list;
mutex some_mutex;

void add_to_list(int new_value){
	lock_guard<mutex> guard(some_mutex);
	some_list.push_back(new_value);
}

bool list_contains(int value_to_find){
	lock_guard<mutex> guard(some_mutex);
	return find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}
