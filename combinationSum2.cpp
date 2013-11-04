#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


void resfun2(vector<int> &candidates, int target, vector<int> res, set<vector<int>>& resset, vector<int> marker) {
	
	int len = candidates.size();
	for(int i = 0; i <= len - 1; i++){
		if(marker[i] == 1){
			continue;
		}
		if(target == candidates[i]){
			vector<int> newres = res;
			newres.push_back(candidates[i]);
			sort(newres.begin(), newres.end());
			resset.insert(newres);
		}else if(target > candidates[i]){
				vector<int> newres = res;
				newres.push_back(candidates[i]);
				vector<int> newmarker = marker;
				newmarker[i] = 1;
			    resfun2(candidates, target - candidates[i], newres, resset, newmarker);
		}
	}
}

vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
	set<vector<int>> resset;
	
	vector<int> res;
	vector<int> marker(candidates.size(), 0);

	resfun2(candidates, target, res, resset, marker);
	

	vector<vector<int>> resvec(resset.begin(), resset.end());

	return resvec;
}

static void helper(vector<int> &candidates, vector<int>& curr, int index, int target, vector<vector<int>>& res){
	if(target == 0){
		res.push_back(curr);
		return;
	}else if(target < 0){
		return;
	}
	
	int len = candidates.size();

	for(int i = index; i < len; i++){
		if(i > index && candidates[i] == candidates[i - 1])
			continue;

		curr.push_back(candidates[i]);
		helper(candidates, curr, i + 1, target - candidates[i], res);
		curr.pop_back();
	}
}

vector<vector<int> > combinationSum21(vector<int> &candidates, int target) {
	int len = candidates.size();

	vector<vector<int>> res;
	sort(candidates.begin(), candidates.end());
	

	vector<int> curr;
	helper(candidates, curr, 0, target, res);

	return res;
}


int maincombinationSum21()
{

	system("pause");
	return 0;
}