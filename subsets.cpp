#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void ressubsetk(vector<int> &S, int k, int pos, vector<int>& res, vector<vector<int>>& resvec)
{
	if(res.size() == k){
		resvec.push_back(res);
		return;
	}

	for(int i = pos + 1; i < S.size(); i++){
		vector<int> newres = res;
		newres.push_back(S[i]);
		ressubsetk(S, k, i, newres, resvec);
	}
}


vector<vector<int> > subsets(vector<int> &S) {
	sort(S.begin(), S.end());
	int len = S.size();
	vector<vector<int>> resvec;
	vector<int> empty;
	resvec.push_back(empty);
	if(len == 0){
		return resvec;
	}

	


	for(int i = 1; i < len; i++){
		vector<int> res;
		ressubsetk(S, i, -1, res, resvec);
	}
    resvec.push_back(S);
	return resvec;
}

static void helper(vector<int>&S, vector<int>& vec, int n, int k, vector<vector<int> >& res){
	if(vec.size() == n){
		res.push_back(vec);
		return;
	}

	for(int i = k; i < S.size(); i++){
		vec.push_back(S[i]);
		helper(S, vec, n, i + 1, res);
		vec.pop_back();
	}


}

//08/06/2013
vector<vector<int> > subsets1(vector<int> &S) {
	vector<vector<int>> res;

	sort(S.begin(), S.end());

	for(int i = 0; i <= S.size(); i++){   // <= not <
		vector<int> vec;
		helper(S, vec, i, 0, res);
	}
	    
	return res;
}

void mainsubsets(){

}