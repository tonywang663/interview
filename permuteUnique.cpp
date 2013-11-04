#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static void helper(vector<int>& cur, vector<int>& num, vector<int>& used, vector<vector<int>>& res){
	if(cur.size() == num.size()){
		res.push_back(cur);
		return;
	}

	int len = num.size();

	for(int i = 0; i < len; i++){
		 if (used[i] || (i != 0 && num[i] == num[i - 1] && !used[i - 1])) continue;

		if(used[i] == 0){
			cur.push_back(num[i]);
			used[i] = 1;
			helper(cur, num, used, res);
			cur.pop_back();
			used[i] = 0;
		}
	}

}

//permutations
vector<vector<int> > permuteUnique(vector<int> &num) {

    vector<vector<int> > res;
	vector<int> cur;
	vector<int> used(num.size(), 0);
	sort(num.begin(), num.end());
	helper(cur, num, used, res);
	return res;

}