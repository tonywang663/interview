#include <unordered_map>
#include <iostream>

using namespace std;

template<typename K, typename T>
struct Entry{
	K key;
	T data;
	Entry* next;
	Entry* pre;
	Entry():next(NULL), pre(NULL){}
	Entry(K _key, T _data) :key(_key), data(_data), next(NULL), pre(NULL){}
};

template<typename K, typename T>
class LRU{

	Entry<K, T> *head;
	Entry<K, T> *tail;
	int capacity;
	int size;

	unordered_map<K, Entry<K, T>*> hashtable;
	void pushfront(Entry<K, T>* entry){
		Entry<K, T>* next = head->next;
		head->next = entry;
		entry->pre = head;
		entry->next = next;
		next->pre = entry;
		cout << "push front entry " << "key = " << entry->key << " data =" << entry->data << endl;
	}

	void detach(Entry<K, T>* entry){
		Entry<K, T>* pre = entry->pre;
		Entry<K, T>* next = entry->next;
		pre->next = next;
		next->pre = pre;
		entry->next = NULL;
		entry->pre = NULL;
		cout << "detach entry " << "key = " << entry->key << " data =" << entry->data << endl;
	}

public:
	LRU(int c);
	void put(K& key, T&& data);
	bool get(K& key, T& data);

};

template<typename K, typename T>
LRU<K, T>::LRU(int c) :capacity(c), size(0){
	head = new Entry<K, T>();
	tail = new Entry<K, T>();
	head->next = tail;
	head->pre = NULL;
	tail->pre = head;
	tail->next = NULL;
}

template<typename K, typename T>
void LRU<K, T>::put(K& key, T&& data){
	Entry<K, T>* entry;
	if (size >= capacity){
		entry = tail->pre;
		detach(entry);
		size--;
	} else
		entry = new Entry<K, T>();

	entry->key = key;
	entry->data = data;
	hashtable.insert(pair<K, Entry<K, T>*>(entry->key, entry));
	size++;
	pushfront(entry);
}

template<typename K, typename T>
bool LRU<K, T>::get(K& key, T& data){
	auto it = hashtable.find(key);
	if (it == hashtable.end())
		return false;

	auto entry = it->second;
	data = entry->data;
	
	detach(entry);
	pushfront(entry);
	return true;
}

void mainlru(){

	LRU<int, int> lru(5);
	for (int i = 0; i < 10; i++){
		lru.put(i, i + 10);
	}
	system("pause");
}

