#include <iostream>
#include <vector>

using namespace std;

int numTrees(int n) {
	if(n <= 0){
		return 0;
	}

	if(n <= 1){
		return 1;
	}

	int* a = new int[n + 1];

	a[0] = 1;
	a[1] = 1;


	for(int i = 2; i <= n; i++){
		int t = 0;
		for(int k = 1; k <= i; k++){
			t = t + a[k - 1] * a[i - k];
		}
		a[i] = t;
	}

	return a[n];
}










//08/08/2013
int numTrees1(int n) {
	if(n <= 0)
		return 0;

	vector<int> dp(n + 1, 0);

	dp[0] = 1;
	dp[1] = 1;

	for(int i = 2; i <= n; i++){
		for(int j = 0; j <= i - 1; j++){
			dp[i] += dp[j] * dp[i - 1 - j];	
		}
	}

	return dp[n];
    
}

void mainnumTrees(){
 numTrees(2);
}