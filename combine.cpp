#include <iostream>
#include <vector>

using namespace std;


void rescombine(int n, int k, int biggest, vector<int> res, vector<vector<int>>& resvec){
	if(res.size() == k){
		resvec.push_back(res);
		return;
	}


	for(int i = biggest + 1; i <= n; i++){
			vector<int> newres = res;
			newres.push_back(i);
			rescombine(n, k, i, newres, resvec);
	}


}
    
vector<vector<int> > combine(int n, int k) {
	vector<vector<int>> resvec;
	if(n <= 0 || k <= 0){
		return resvec;
	}
	
	vector<int> res;
	rescombine(n, k, 0, res, resvec);
    return resvec;
}

void helper(int n, vector<int>& vec, int k, int f, vector<vector<int> >& res){
	if(k == 0){
		res.push_back(vec);
		return;
	}

	for(int i = f; i < n; i++){
			vec.push_back(i + 1);
			helper(n,vec, k - 1, i + 1, res);
			vec.pop_back();
	}
}


//08/05/2013
vector<vector<int> > combine1(int n, int k) {
	vector<vector<int> > res;

	if(n <= 0 || k <= 0 || k > n)
		return res;

	vector<int> vec;

	helper(n, vec,  k, 0, res);
    return res;
}

void maincombine(){

}