#include <iostream>
#include <vector>
#include <set>

using namespace std;

int longestConsecutive(vector<int> &num) {
	set<int> numset;

	for(int i = 0; i < num.size(); i++){
		numset.insert(num[i]);
	}

	int max = 0;
	while(numset.size() >= max){
		int t = 0;
		int val = *numset.begin();
		int i = 1;
		while(1){
			set<int>::iterator it = numset.find(val + i);
			if(it == numset.end())
				break;
			i++;
			numset.erase(it);
		}
		int j = 1;
		while(1){
			set<int>::iterator it = numset.find(val - j);
			if(it == numset.end())
				break;
			j++;
			numset.erase(it);
		}
		t = i + j - 1;
		numset.erase(numset.begin());
		if(t > max)
			max = t;
	}
	return max;
}


//08/12/2013
int longestConsecutive1(vector<int> &num) {
	set<int> numset;

	for(int i = 0; i < num.size(); i++){
		numset.insert(num[i]);
	}

	int max = 1;
	while(numset.size() >= max){
		int val = *numset.begin();
		int cur = 1;
		numset.erase(numset.begin());
		int i = 1;
		while(1){
			if(numset.find(val + i) == numset.end()){
				break;
			}else{
				numset.erase(numset.find(val + i));
				i++;
			}
		}
		int j = 1;
		while(1){
			if(numset.find(val - j) == numset.end()){
				break;
			}else{
				numset.erase(numset.find(val - j));
				j++;
			}
		}
		cur += i + j - 2;
		if(cur > max)
			max = cur;
	}
	return max;
}

void mainlongestConsecutive1(){
	int a[] = {0, -1};

	vector<int> vec(a, a + sizeof(a) / sizeof(int));

	longestConsecutive1(vec);


}