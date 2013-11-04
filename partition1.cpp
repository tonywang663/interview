#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

bool isp(string s){
	int len = s.length();

	for(int i = 0; i < (len / 2); i++){
		if(s[i] != s[len - 1 - i])
			return false;
	}

	return true;

}

void resp(string s, vector<string>& res, set<vector<string>>& resset){
	int len = s.length();

	if(len == 0){
		sort(res.begin(), res.end());
		resset.insert(res);
	}

	for(int i = 1; i <= len; i++){
		string str = s.substr(0, i);
		if(isp(str)){
			vector<string> newres = res;
			newres.push_back(str);
			resp(s.substr(i, len - i), newres, resset);
		}
	}

}


vector<vector<string>> partition(string s) {
	vector<vector<string>> resvec;
	if(s.empty())
		return resvec;

	vector<string> res;
	set<vector<string>> resset;
	resp(s, res, resset);

	copy(resset.begin(), resset.end(), back_inserter(resvec));
	return resvec;
        
}

static void helper(string s, vector<string>& vec, vector<vector<string>>& res){
	if(s.empty()){
		res.push_back(vec);
		return;
	}

	for(int i = 1; i <= s.length(); i++){
		string str = s.substr(0,i);
		if(isp(str)){
			vec.push_back(str);
			helper(s.substr(i, s.length() - i), vec, res);
			vec.pop_back();
		}
	}
}

//08/11/2013 palindrome partition I
vector<vector<string>> partition1(string s) {
	vector<vector<string>> res;

	vector<string> vec;
	helper(s,vec, res);

	return res;
}

void mainpartition1()
{

}