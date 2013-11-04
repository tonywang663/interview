#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void nextperm(vector<int>& vec){
	int len = vec.size();

	int i = len - 1;
	for(; i >= 1; i--){
		if(vec[i] > vec[i - 1]){
			break;
		}
	}

	int j = len - 1;
	for(; j >= i; j--){
		if(vec[j] > vec[i - 1]){
			break;
		}
	}

	int temp = vec[i - 1];
	vec[i - 1] = vec[j];
	vec[j] = temp;
	
	sort(vec.begin() + i, vec.end());

}

string getPermutation(int n, int k) {
	vector<int> vec(n, 0);


	for(int i = 0; i < n; i++){
		vec[i] = i + 1;
	}

	int nf = 1;

	for(int i = 1; i <= n; i++){
		nf = nf * i;
	}

	k = k % (nf + 1);

	for(int i = 0; i < k - 1; i++){
		nextperm(vec);
	}

	string res ="";
	for(int i = 0; i < n; i++){
		res.push_back(vec[i]+'0');
	}

	return res;
    
}

int resper(int& k, int m)
{
	int mf = 1;
	for(int i = m; i >= 1; i--){
		mf = mf * i;
	}

	int r = ceil(float(k) / mf);

	k = k - (r - 1) * mf;
	return r;
}


string getPermutation1(int n, int k) {
	int nf = 1;

	for(int i = 1; i <= n; i++){
		nf = nf * i;
	}

	vector<int> marker;
	for(int i = 0; i < n; i++){
		marker.push_back(0);
	}
	k = k % (nf + 1);

	string res ="";
	for(int i = 0; i < n; i++){
		int t = resper(k, n - 1 - i);

		int numunused = 0;
		int num;
		for(int j = 0; j < n; j++){
			if(marker[j] == 0){
				numunused++;
			}
			if(numunused == t){
				marker[j] = 1;
				num = j + 1;
				break;
			}
		}
		
		res.push_back(num+'0');
	}

	return res;
    
}

int fact(int m){
	int res = 1;
	for(int i = 2; i <= m; i++){
		res *= i;
	}

	return res;

}

string getPermutation2(int n, int k) {

	k = k % (fact(n) + 1);

	vector<int> used(n, 0);

	string res;

	for(int i = n; i >= 1; i--){
		int cf = fact(i - 1);
		
		int t = ceil(float(k) / cf);
		
		k = k - (t - 1) * cf;

		int numunused = 0;

		for(int j = 0; j < n; j++){
			if(used[j] == 0){
				numunused++;
			}

			if(numunused == t){
				used[j] = 1;
				res.push_back(j + 1 + '0');
				break;
			}

		}
	}

	return res;
    
}

int maingetPermutation()
{
	string str = getPermutation1(3, 4);
	return 0;

}