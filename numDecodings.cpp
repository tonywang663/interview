#include <iostream>
#include <string>
#include <vector>

using namespace std;


void resdecode(string s, int& num){
	int len = s.length();

	if(s[0] == '0'){
		return;
	}

	if(len == 1){
		num++;
		return;
	}

	if(len == 2){
		int a  = atoi(s.c_str());
		if(a >= 1 && a <= 26){
			num++;
		}

		resdecode(s.substr(1, 2), num);
		return;
	}


	resdecode(s.substr(1, len - 1), num);

	string begin = s.substr(0, 2);

	int b = atoi(begin.c_str());

	if(b <= 26){
		resdecode(s.substr(2, len - 2), num);

	}

}


int numDecodings(string s) {
	int res = 0;

	int len = s.length();

	if(len <= 0)
		return res;

	resdecode(s, res);

	return res;
}


int numDecodings1(string s) {
	int res = 0;

	int len = s.length();

	if(len <= 0)
		return res;

	if(s[0] == '0'){
		return 0;
	}
		
	int* a= new int[len];

	a[0] = 1;
	
	if(len <= 1){
		return 1;
	}

	string head = s.substr(0, 2);

	int b = atoi(head.c_str());

	if(s[1] == '0'){
		if(b <= 26)
			a[1] = 1;
		else
			return 0;
	}else{
		if(b <= 26)
			a[1] = 2;
		else
			a[1] = 1;
	}

	for(int i = 2; i < len; i++){
		if(s[i] != '0'){
			a[i] = a[i - 1];
			string str = s.substr(i - 1, 2);
			int t = atoi(str.c_str());
			if(t <= 26 && t > 10){
				a[i] += a[i - 2];
			}
		}else{
			string str = s.substr(i - 1, 2);
			int t = atoi(str.c_str());
			if(t > 26 || t == 0){
				return 0;
			}else{
				a[i] = a[i - 2];
			}
		}
	}

	return a[len - 1];
}




//08/07/2013
int numDecodings2(string s) {
	int len = s.length();

	if(len <= 0)
		return 0;

	vector<int> dp(len + 1, 0);

	dp[0] = 1;
	
	if(s[0] != '0')
		dp[1] = 1;

	for(int i = 2; i <= len; i++){
		string str = s.substr(i - 2, 2);
		int t = atoi(str.c_str());
		if(t > 10 && t <= 26 && t != 20){
			dp[i] = dp[i - 1] + dp[i - 2];
		}else if(s[i - 1] != '0'){
			dp[i] = dp[i - 1];
		}else if(t == 10 || t == 20){
			dp[i] = dp[i - 2];
		}else{
			dp[i] = 0;
		}
	}
	
	return dp[len];
    
}

void mainnumDecodings(){

}