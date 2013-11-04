#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<int> plusOne(vector<int> &digits) {
	int len = digits.size();
	list<int> reslist;
	
	
	if(len == 0){
		vector<int> res;
		return res;
	}

	int overflow = 0;

	for(int i = len - 1; i >= 0; i--){
		int t = 0;
		if(i == len - 1){
			t = digits[i] + 1;
		}else{
			t = digits[i] + overflow;
		}

		if(t > 9){
			overflow = 1;
			reslist.insert(reslist.begin(), t - 10);
		}else{
			overflow = 0;
			reslist.insert(reslist.begin(), t);
		}

	}

	if(overflow == 1){
		reslist.insert(reslist.begin(), 1);
	}

	vector<int> res(reslist.begin(), reslist.end());

	return res;
    
}

int mainplusOne()
{
	vector<int> a;
	a.push_back(0);
	plusOne(a);
	return 0;
}