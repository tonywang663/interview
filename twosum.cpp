#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


vector<int> twoSum(vector<int> &numbers, int target) {
	
    vector<int> newnumbers = numbers;
    sort(numbers.begin(), numbers.end());

	vector<int> res;

	int left = 0, right = 1;

	int len = numbers.size();

	if(len <= 1)
		return res;

	while(left <= len - 1){
		right = left + 1;
		for(;right <= len - 1; right++){
			if(numbers[left] + numbers[right] == target){
				for(int i = 0; i < len; i++){
					if(numbers[left] == newnumbers[i]){
						res.push_back(i + 1);
						break;
					}
				}
				for(int i = len - 1; i >= 0; i--){
					if(numbers[right] == newnumbers[i]){
						res.push_back(i + 1);
						break;
					}
				}
                sort(res.begin(), res.end());
				return res;
			}

			if(numbers[left] + numbers[right] > target){
				break;
			}
		}

		left++;
	}
    
}

vector<int> twoSum1(vector<int> &numbers, int target) {
	vector<int> res;

	int left = 0, right = 1;

	int len = numbers.size();

	if(len <= 1)
		return res;

	map<int, int> nummap;
	for(int i = 0; i < len; i++){
		pair<int, int> e(numbers[i], i);
		nummap.insert(e);
	}

	for(int i = 0; i < len; i++){
		int rest = target - numbers[i];
		if(rest == numbers[i]){
			if(nummap.size() == numbers.size())
				continue;
			else{
				for(int j = 0; i < len; j++){
					if(j == i)
						continue;
					if(numbers[j] == numbers[i]){
						res.push_back(i + 1);
						res.push_back(j + 1);
						sort(res.begin(), res.end());
						return res;
					}

				}
			}
		}else{
			if(nummap.count(rest) > 0){
				res.push_back(i + 1);
				res.push_back(nummap[rest] + 1);
				sort(res.begin(), res.end());
				return res;
			}

		}
	}

	return res;

}

//08/24/2013
vector<int> twoSum2(vector<int> &numbers, int target) {
	map<int, vector<int>> umap;
	vector<int> res;

	for(int i = 0; i < numbers.size(); i++){
		umap[numbers[i]].push_back(i);
	}

	for(int i = 0; i < numbers.size(); i++){
		int b = target - numbers[i];
		if(umap.count(b) > 0){
			if(b != numbers[i]){
				res.push_back(i + 1);
				res.push_back(umap[b][0] + 1);
				sort(res.begin(), res.end());     //takes two iterators as input
				return res;
			}else{
				if(umap[b].size() > 1){
					res.push_back(umap[b][0] + 1);
					res.push_back(umap[b][1] + 1);
					return res;
				}
			}
		}
	}
    
}

int maintwosum()
{
	int a[] = {5,75,25};

	vector<int> input(a, a + sizeof(a) / sizeof(int));
//	twoSum(input, 100);
	map<int, int> m;
	pair<int, int> p1(1, 1), p2(1, 2);
	m.insert(p1);
	m.insert(p2);
	if(m[2] == 0){
		cout<<"dfsf";
	}
	system("pause");
	return 0;
}