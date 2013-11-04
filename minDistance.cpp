#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2) {
	int len1 = word1.length();

	int len2 = word2.length();

	if(len1 == 0){
		return len2;
	}

	if(len2 == 0){
		return len1;
	}

	int **a = new int*[len1];

	for(int i = 0; i < len1; i++){
		a[i] = new int[len2];
	}

//	int dist = 1;
	if(word1[0] == word2[0]){
		a[0][0] = 0;
	}else{
		a[0][0] = 1;
	}

	for(int i = 1; i < len1; i++){
		if(a[i - 1][0] == i - 1 || word1[i] == word2[0]){
			a[i][0] = i;
		}else{
			a[i][0] = i + 1;
		}
	}

	for(int j = 1; j < len2; j++){
		if(a[0][j - 1] == j - 1 || word1[0] == word2[j]){
			a[0][j] = j;
		}else{
			a[0][j] = j + 1;
		}
	}

	for(int i = 1; i < len1; i++){
		for(int j = 1; j < len2; j++){
			int t1 = a[i - 1][j - 1] + 1;
			if(word1[i] == word2[j]){
				t1 = a[i - 1][j - 1];
			}
			int t2 = a[i - 1][j] + 1;
			int t3 = a[i][j - 1] + 1;

			int d1 = min(t2, t3);
			int d2 = min(t1, d1);
			a[i][j] = d2;

		}
	}

	return a[len1 - 1][len2 - 1];
    
}








//08/04/2013
int minDistance1(string word1, string word2) {
	int len1 = word1.length();
	int len2 = word2.length();

	if(len1 == 0)
		return len2;

	if(len2 == 0)
		return len1;

	vector<vector<int>> dp(len1, vector<int>(len2, 0));
    
	if(word1[0] != word2[0])
		dp[0][0] = 1;

	for(int i = 1; i < len1; i++){
		if(dp[i - 1][0] == i - 1 || word1[i] == word2[0]){
			dp[i][0] = i;
		}else{
			dp[i][0] = i + 1;
		}
	}

	for(int j = 0; j < len2; j++){
		if(dp[0][j - 1] == j - 1 || word1[0] == word2[j]){
			dp[0][j] = j; 
		}else{
			dp[0][j] = j + 1;
		}
	}

	for(int i = 1; i < len1; i++){
		for(int j = 1; j < len2; j++){
			int t1;
			if(word1[i] == word2[j]){
				t1 = dp[i - 1][j - 1];
			}else{
				t1 = dp[i - 1][j - 1] + 1;
			}

			int t2 = dp[i - 1][j] + 1;
			int t3 = dp[i][j - 1] + 1;

			int t4 = min(t1, t2);
			int t5 = min(t4, t3);
			dp[i][j] = t5;
		}
	}

	return dp[len1 - 1][len2 - 1];
}

void mainminDistance(){
	minDistance("a", "ab"); 

}