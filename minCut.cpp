#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool ispal(string& str){
	int len = str.length();

	for(int i = 0; i <= (len - 1) / 2; i++){
		if(str[i] != str[len - 1 - i])
			return false;
	}

	return true;
}

int minCut(string s) {
	int len = s.length();

	if(len <= 1)
		return 0;
	
	vector<int> a(len, len - 1);

	a[0] = 0;

	for(int i = 1; i < len; i++){
		int min = len - 1;
		for(int j = 0; j <= i; j++){
			string str = s.substr(j, i - j + 1);
			if(ispal(str)){
				if(j > 0){
					if(min > a[j - 1] + 1){
						min = a[j - 1] + 1;
					}
				}else{
					if(min > 0)
						min = 0;
				}
			}else{
				if(j > 0){
					if(min > a[j - 1] + i - j + 1)
						min = a[j - 1] + i - j + 1;
				}else{
					if(min > i)
						min = i;
				}
			}
		}
		a[i] = min;
	}
	return a[len - 1];
}

int minCut1(string s) {
	int len = s.length();

	if(len <= 1)
		return 0;

	vector<int> dp;

	for(int i = 0; i <= len; i++){
		dp.push_back(len - 1 - i);
	}

	vector<vector<int>> pal(len, vector<int>(len, 0));

	for(int i = len - 2; i >= 0; i--){
		for(int j = i; j < len; j++){
			if(s[i] == s[j] && (j - i< 2 || pal[i + 1][j - 1] == 1)){
				pal[i][j] = 1;
				dp[i] = min(dp[i], dp[j + 1] + 1);
			}
		}

	}

	return dp[0];

}

void mainminCut1(){
	string str("coder");
	minCut(str); 
}