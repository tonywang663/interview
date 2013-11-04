#include <vector>
#include <iostream>

using namespace std;

void trace(vector<int>& tr, vector<int>& vec, int index){
	while(index >= 0){
		cout<<vec[index]<<" ";
		index = tr[index];
	}
	cout<<endl;
}

int lis(vector<int>& vec){
	int len = vec.size();

	if(len <= 0)
		return 0;

	vector<int> dp(len, 1);
	vector<int> tr(len, -1);

	int max = 1;
	int index = 0;

	for(int i = 1; i < len; i++){
		for(int j = i - 1; j >= 0; j--){
			if(vec[i] > vec[j] && dp[j] >= dp[i]){
				dp[i] = dp[j] + 1;
				tr[i] = j;
				if(dp[i] > max){
					max = dp[i];
					index  = i;
				}
			}
		}
	}

	trace(tr, vec, index);
	return max;
}

int binarysearch(vector<int>& vec, vector<int>& m, int target, int right){

	int left = 1;

	while(left <= right){
		int mid = (left + right) / 2;
		if(vec[m[mid]] >= target){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	return right;
}
//nlogL solution
int efflis(vector<int>& vec){
	int len = vec.size();

	if(len <= 0)
		return 0;

	vector<int> dp(len, 1);
	vector<int> tr(len, -1);
	vector<int> m(len + 1, -1);

	m[1] = 0;

	int max = 1;
	int index = 0;
	for(int i = 1; i < len; i++){
		int pre = binarysearch(vec, m, vec[i], max);
		if(pre == 0){
			m[1] = i;
			continue;
		}
		dp[i] = dp[m[pre]] + 1;
		tr[i] = m[pre];
		if(dp[i] > max){
			max = dp[i];
			m[dp[i]] = i;
			index = i;
		}else{
			if(vec[i] < vec[m[pre + 1]])
				m[pre + 1] = i; 
		}
	}

	trace(tr, vec, index);
	return max;
}

void mainlis(){

	int a[] = {6, 3, 5, 2, 7, 8, 1};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	cout<<efflis(vec);
	system("pause");
}