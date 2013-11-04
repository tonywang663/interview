#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


void ressubset(vector<int> &S, int k, int pos, set<vector<int>>& resset, vector<int>& res){
	if(res.size() == k){
		resset.insert(res);
		return;
	}

	int len = S.size();

	for(int i = pos; i < len; i++){
		vector<int> newres = res;
		newres.push_back(S[i]);
		ressubset(S,  k, i + 1, resset, newres);
	}


}

vector<vector<int> > subsetsWithDup(vector<int> &S) {
	

	int len = S.size();

	if(len == 0){
		vector<vector<int>> res;
		return res;
	}

	sort(S.begin(), S.end());
	set<vector<int>> resset;

	vector<int> empty;

	resset.insert(empty);

//	vector<int> marker(len, 0);

	for(int i = 1; i <= len - 1; i++){
		ressubset(S, i, 0, resset, empty);
	}

	resset.insert(S);

	vector<vector<int>> resvec(resset.begin(), resset.end());

	return resvec;

    
}

static void helper(int n, int k, vector<int>& vec, vector<int>&S, vector<vector<int>>& res){
	if(vec.size() == n){
		res.push_back(vec);
		return;
	}

	for(int i = k + 1; i < S.size(); i++){
		if(i > k + 1 && S[i] == S[i - 1])            //the only difference
			continue;

		vec.push_back(S[i]);
		helper(n, i, vec, S, res);
		vec.pop_back();
	}
}

//08/07/2013
vector<vector<int> > subsetsWithDup1(vector<int> &S) {
	vector<vector<int>> res;

	sort(S.begin(), S.end());

	for(int i = 0; i <= S.size(); i++){
		vector<int> vec;
		helper(i, -1, vec, S, res);
	}

	return res;
}

void mainsubsetsWithDup(){

}