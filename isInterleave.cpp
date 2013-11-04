#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool resinter(string s1, string s2, string s3){
	int len1 = s1.length();
	int len2 = s2.length();
	int len3 = s3.length();

	if(len1 == 0){
		if(s2.compare(s3) == 0){
			return true;
		}else
			return false;
	}

	if(len2 == 0){
		if(s1.compare(s3) == 0)
			return true;
		else
			return false;
	}

	if(s1[0] != s3[0] && s2[0] != s3[0])
		return false;

	if(s1[0] == s3[0]){
		if(resinter(s1.substr(1, len1 - 1), s2, s3.substr(1, len3 - 1)))
			return true;
	}
	
	if(s2[0] == s3[0]){
		if(resinter(s1, s2.substr(1, len2 - 1), s3.substr(1, len3 - 1)))
			return true;
	}

	return false;
}



bool isInterleave(string s1, string s2, string s3) {
	int len1 = s1.length();
	int len2 = s2.length();
	int len3 = s3.length();

	if(len1 + len2 != len3)
		return false;
	
	return resinter(s1, s2, s3);
    
}

bool isInterleave1(string s1, string s2, string s3) {
	int len1 = s1.length();
	int len2 = s2.length();
	int len3 = s3.length();

	if(len1 + len2 != len3)
		return false;

	if(len1 == 0){
		if(s2.compare(s3) == 0){
			return true;
		}else
			return false;
	}

	if(len2 == 0){
		if(s1.compare(s3) == 0)
			return true;
		else
			return false;
	}

	int** a = new int*[len1 + 1];
	for(int i = 0; i < len1 + 1; i++){
		a[i] = new int[len2 + 1];
	}

	a[0][0] = 1;

	for(int i = 1; i <= len1; i++){
		if(a[i - 1][0] == 1 && s1[i - 1] == s3[i - 1])
			a[i][0] = 1;
		else
			a[i][0] = 0;
	}

	for(int j = 1; j <= len2; j++){
		if(a[0][j - 1] == 1 && s2[j - 1] == s3[j - 1])
			a[0][j] = 1;
		else
			a[0][j] = 0;
	}

	for(int i = 1; i <= len1; i++){
		for(int j = 1; j <= len2; j++){
			if(a[i - 1][j] == 1 && s1[i - 1] == s3[i + j - 1]){
				a[i][j] = 1;
				continue;
			}

			if(a[i][j - 1] == 1 && s2[j - 1] == s3[i + j - 1]){
				a[i][j] = 1;
				continue;
			}
			
			a[i][j] = 0;
		}
	}

	if(a[len1][len2] == 1)
		return true;
	else
		return false;
    
}



//08/09/2013
bool isInterleave2(string s1, string s2, string s3) {
	int len1 = s1.length();
	int len2 = s2.length();
	int len3 = s3.length();

	if(len1 + len2 != len3)
		return false;

	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
	
	dp[0][0] = 1;

	for(int i = 1; i <= len1; i++){
		if(s1[i - 1] == s3[i - 1] && dp[i - 1][0] == 1){
			dp[i][0] = 1;
		}
	}

	for(int j = 1; j <= len2; j++)
		if(s2[j - 1] == s3[j - 1] && dp[0][j - 1] == 1)
			dp[0][j] = 1;

	for(int i = 1; i <= len1; i++){
		for(int j = 1; j <= len2; j++){
			if( (dp[i - 1][j] == 1 && s1[i - 1] == s3[ i + j - 1]) || (dp[i][j - 1] == 1 && s2[j - 1] == s3[i + j - 1]))
				dp[i][j] = 1;
		}
	}

	return dp[len1][len2];
}


void mainisInterleave1(){

}