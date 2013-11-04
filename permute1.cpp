#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


void recurper(vector<int>& num, vector<int>& marker, vector<int>& res, vector<vector<int>>& resvec)
{
	if(res.size() == num.size()){
		resvec.push_back(res);
		return;
	}

	for(int i = 0; i <= num.size() - 1; i++){
		if(marker[i] == 0){
			vector<int> newres = res;
			vector<int> newmarker = marker;
			newmarker[i] = 1;
			newres.push_back(num[i]);
			recurper(num, newmarker, newres, resvec);
		}
	}
}


vector<vector<int> > permute(vector<int> &num) {
		
	vector<vector<int>> resvec;
	vector<int> res;
	vector<int> marker(num.size(), 0);
	
	recurper(num, marker, res, resvec);
	
	return resvec;
}

void recurper(vector<int>& num, vector<int>& marker, vector<int>& res, set<vector<int>>& resset)
{
	if(res.size() == num.size()){
//		sort(res.begin(), res.end());
		resset.insert(res);
		return;
	}

	for(int i = 0; i <= num.size() - 1; i++){
		if(marker[i] == 0){
			vector<int> newres = res;
			vector<int> newmarker = marker;
			newmarker[i] = 1;
			newres.push_back(num[i]);
			recurper(num, newmarker, newres, resset);
		}
	}
}

vector<vector<int> > permute2(vector<int> &num) {
		
//	
	set<vector<int>> resset;
	vector<int> res;
	vector<int> marker(num.size(), 0);
	
	recurper(num, marker, res, resset);
	vector<vector<int>> resvec(resset.begin(), resset.end());
	
	return resvec;
}


static void helper(vector<int>& cur, vector<int>& num, vector<int>& used, vector<vector<int>>& res){
	if(cur.size() == num.size()){
		res.push_back(cur);
		return;
	}

	int len = num.size();

	for(int i = 0; i < len; i++){
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
vector<vector<int> > permute1(vector<int> &num) {

    vector<vector<int> > res;
	vector<int> cur;
	vector<int> used(num.size(), 0);
	helper(cur, num, used, res);
	return res;

}

int mainpermute1()
{
	int a[] = {1};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	permute1(vec);
	return 0;
}