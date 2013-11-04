#include <iostream>
#include <vector>
#include <set>

using namespace std;

void resclimb(int pos, int n, set<vector<int>>& resset, vector<int>& marker)
{
	if(pos == n){
		resset.insert(marker);		
	}

	vector<int> marker1 = marker;
	marker1[pos + 1] = 1;
	resclimb(pos + 1, n, resset, marker1);

	if(pos <= n - 2){
		vector<int> marker2 = marker;
		marker2[pos + 2] = 1;
		resclimb(pos + 2, n, resset, marker2);
	}
	
}


int climbStairs(int n) {

	set<vector<int>> resset;

	vector<int> marker(n, 0);

	return resset.size();

	
}


int climbStairs1(int n) {
	
	if(n <= 0){
		return 0;
	}

	if(n <= 1){
		return 1;
	}
	int *a = new int[n + 1];

	a[n] = 0;

	a[n - 1] = 1;

	a[n - 2] = 1;

	for(int i = n - 3; i >= 0; i--){
		a[i] = a[i + 1] + a[i + 2];
	}

	return a[0];
}




int climbStairs2(int n) {
	if(n <= 0)
		return 0;

	vector<int> dp(n + 1, 0);

	dp[1] = 1;
	dp[2] = 2;

	for(int i = 3; i <= n; i++){
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

void mainclimbStairs1(){

}