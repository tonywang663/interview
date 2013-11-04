#include <set>
#include <string>
#include <vector>
using namespace std;

bool wordBreak(string s, set<string> &dict) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
	set<string>::iterator it = dict.begin();

	for(;it != dict.end(); it++){
		string word = *it;
		string str = s.substr(0, word.length());
		if(str == word){
			if(wordBreak(s.substr(word.length(), s.length() - word.length()),dict))
				return true;
		}
	}

	return false;
}


bool wordBreak1(string s, set<string> &dict) {
	int len = s.length();

	vector<vector<int>> dp(len, vector<int>(len, 0));

	for(int i = 0; i < len; i++){
		set<string>::iterator it = dict.begin();
		for(;it != dict.end(); it++){
			string word = *it;
			if(i + word.length() > len)
				continue;
			string str = s.substr(i, word.length());
			if(str == word){
				dp[i][i + word.length() - 1] = 1;
			}
		}
	}

	for(int i = 0; i < len; i++){
		for(int j = 0; j <= i - 1; j++){
			if(dp[0][j] == 1 && dp[j + 1][i] == 1)
				dp[0][i] = 1;
		}
	}

	return dp[0][len - 1] == 1;
}



void mainwordBreak1(){

}