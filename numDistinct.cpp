#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDistinct(string S, string T) {
	int len1 = S.length();
	int len2 = T.length();

	if(len1 == 0 || len2 == 0)
		return 0;

   vector<int> v(len2, 0);
	vector<vector<int>> a(len1, v);

	if(S[0]== T[0])
		a[0][0] = 1;
	
	for(int i = 1; i <= len1 - 1; i++){
		if(S[i] == T[0]){
			a[i][0] = a[i - 1][0] + 1;
		}else{
			a[i][0] = a[i - 1][0];
		}
	}

	for(int i = 1; i < len1; i++){
		for(int j = 1; j < len2; j++){
			if(S[i] == T[j]){
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}else{
				a[i][j] =a[i - 1][j];
			}
		}
	}

	return a[len1 - 1][len2 - 1];
}


//08/09/2013
int numDistinct1(string S, string T) {
	int len1 = S.length();
	int len2 = T.length();

	if(len2 == 0)
		return 1;

	if(len1 == 0)
		return 0;

	vector<vector<int>> dp(len1, vector<int>(len2, 0));
	
	if(S[0] == T[0])
		dp[0][0] = 1;

	for(int i = 1; i < len1; i++){
		if(S[i] == T[0]){
			dp[i][0] = dp[i - 1][0] + 1;
		}else
			dp[i][0] = dp[i - 1][0];
	}

	for(int i = 1; i < len1; i++){
		for(int j = 1; j < len2; j++){
			if(S[i] == T[j]){
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[len1 - 1][len2 - 1];
    
}

void mainnumDistinct(){

}