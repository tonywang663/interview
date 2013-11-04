#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

string longestPalindrome(string& s) {

    int len = s.length();
	string mp = "";
	mp = mp + s[0];
	int plen = 1;
	for(int i = 0; i <= len - 1; i++)
	{		
		int bound = min(i, len - i - 1);
		int tlen = 1;
		for(int j = 1; j <= bound; j++)
		{
			
			if(s[i - j] == s[i+j])
			{
				tlen = tlen + 2;
				if(tlen > plen)
				{
					plen = tlen;
					mp = s.substr(i - j, 2 * j + 1);
				}
			}else
			{
				break;
			}
		}
	}

	for(int i = 1; i <= len - 1; i++)
	{
		int bound = min(i, len - i);
		int tlen = 0;
		for(int j = 1; j <= bound; j++)
		{
	
			if(s[i - j] == s[i - 1 + j])
			{
				tlen = tlen + 2;
				if(tlen > plen)
				{
					plen = tlen;
					mp = s.substr(i - j, 2 * j);
				}
			}else
			{
				break;
			}

		}
	}
    return mp;
}

string longestPalindrome1(string s) {
	int len = s.length();

	string res;

	if(len == 0)
		return res;
	
	vector<int> e(len, 0);
	vector<vector<int> > a(len, e);

	for(int i = 0; i < len; i++)
		a[i][i] = 1;

	int max = 1;
	int left = 0, right = 0;

	for(int i = 0; i < len - 1; i++){
		if(s[i] == s[i + 1]){
			a[i][i + 1] = 2;
			max = 2;
			left = i;
			right = i + 1;
		}
	}

	
	for(int i = len - 2; i >= 1; i--){
		for(int j = 0; j <= i - 1; j++){
			if(a[j + 1][j + len - i - 1] > 0 && s[j] == s[j + len - i]){
				a[j][j + len - i] = a[j + 1][j + len - i - 1] + 2;
				if(a[j][j + len - i] > max){
					max = a[j][j + len - i];
					left = j;
					right = j + len - i;
				}
			}
		}
	}

	res = s.substr(left, max);
	return res;
    
}

//09/08/2013
string longestPalindrome2(string s) {
	int len = s.length();
	if(len <= 1)
		return s;

	vector<vector<int>> dp(len, vector<int>(len, 0));

	for(int i = 0; i < len; i++)
		dp[i][i] = 1;

	int left = 0, right = 0;
	for(int i = 0; i < len - 1; i++){
		if(s[i] == s[i + 1]){
			dp[i][i + 1] = 1;
			left = i;
			right = i + 1;
		}
	}
	
	for(int step = 3; step <= len; step++){
		for(int i = 0; i <= len - step; i++){
			if(s[i] == s[i + step - 1] && dp[i + 1][i + step - 2] == 1){
				dp[i][i + step - 1] = 1;
				if(step - 1 > right - left){
					right = i + step - 1;
					left = i;
				}
			}
		
		}
	}

	return s.substr(left, right - left + 1);
}


string longestPalindrome3(string s) {
	int len = s.length();
	if(len <= 1)
		return s;

	int left = 0, right = 0;

	for(int i = 0; i <= len - 1; i++){
		int bound = min(i, len - i - 1);
		for(int j = 1; j <= bound; j++){
			if(s[i - j] == s[i + j]){
				if(2 * j > right - left){
					left = i - j;
					right = i + j;
				}
			}else
				break;
		}
	}

	for(int i = 1; i <= len - 1; i++){
		int bound  = min(i, len - i);
		for(int j = 1; j <= bound; j++){
			if(s[i - j] == s[i + j - 1]){
				if(2 * j - 1 > right - left){
					left = i - j;
					right = i + j - 1;
				}
			}else
				break;
		}
	}

	return s.substr(left, right - left + 1);
}

int mainlongestPalindrome1()
{
	string s = "ccc";
	string str =  longestPalindrome1(s);
	cout<<str<<endl;
	system("pause");
	return 0;
}