#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


void resfun(vector<int> &candidates, int target, vector<int> res, set<vector<int>>& resset) {
	
	int len = candidates.size();
	for(int i = 0; i <= len - 1; i++){
		if(target == candidates[i]){
			vector<int> newres = res;
			newres.push_back(candidates[i]);
			sort(newres.begin(), newres.end());
			resset.insert(newres);
		}else if(target > candidates[i]){
				vector<int> newres = res;
				newres.push_back(candidates[i]);
			    resfun(candidates, target - candidates[i], newres, resset);
		}
	}
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	set<vector<int>> resset;
	
	vector<int> res;
	resfun(candidates, target, res, resset);

	vector<vector<int>> resvec(resset.begin(), resset.end());

	return resvec;
}

void helper(vector<int> &candidates, vector<int>& curr, int index, int target, vector<vector<int>>& res){
	if(target == 0){
		res.push_back(curr);
		return;
	}else if(target < 0){
		return;
	}
	
	int len = candidates.size();

	for(int i = index; i < len; i++){
		if(i != index && candidates[i] == candidates[i - 1])
			continue;

		curr.push_back(candidates[i]);
		helper(candidates, curr, i, target - candidates[i], res);
		curr.pop_back();
	}
}

vector<vector<int> > combinationSum1(vector<int> &candidates, int target) {
	int len = candidates.size();

	vector<vector<int>> res;
	sort(candidates.begin(), candidates.end());
	
	vector<int> curr;
	helper(candidates, curr, 0, target, res);

	return res;
}

int maincombinationSum1()
{
	int a[] = {2, 2, 2};
	vector<int> can(a, a + sizeof(a) / sizeof(int));
	combinationSum1(can, 4);
	system("pause");
	return 0;
}