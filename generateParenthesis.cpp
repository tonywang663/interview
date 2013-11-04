#include <iostream>
#include <set>
#include <vector>
#include <cassert>
#include <string>
using namespace std;


set<string> genset(int n){
	set<string> res;
	if(n == 0)
	{
		return res;
	}

	if(n == 1)
	{
		string s = "()";
		res.insert(s);
		return res;
	}

	if(n == 2)
	{
		string s1 = "()()";
		string s2 = "(())";
		res.insert(s1);
		res.insert(s2);
		return res;
	}

	set<string> tres = genset(n-1);

	string ele = "()";
	
	for(set<string>::iterator it1 = tres.begin(); it1 != tres.end(); it1++){
		string s = *it1;
		int len = s.length();
//		res.insert("()"+s);
		for(int i = 0; i <= len - 1; i++)
		{
			string temp1 = s.substr(0, i);
			string temp2 = s.substr(i, len - i);
			string s1 = temp1 + ele + temp2;
			res.insert(s1);
		}
		res.insert(s + ele);
	}
	return res;	
}

vector<string> generateParenthesis(int n) {


	set<string> resset = genset(n);

	vector<string> resvec(resset.begin(), resset.end());

	return resvec;
}

void resgen(vector<string>& res, string& str, int left, int right, int n){
	if(str.size() == n){
		res.push_back(str);
	}else{
		if(left < n){
			str.push_back('(');
			resgen(res, str, left + 1, right, n);
			str.resize(str.length() - 1);
		}

		if(right < left){
			str.push_back(')');
			resgen(res, str, left, right + 1, n);
			str.resize(str.length() - 1);
		}
	}

}


vector<string> generateParenthesis1(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<string> res;

    string str;

    resgen(res, str, 0, 0, n);
   
    return res;
}



int maingenerateParenthesis1()
{
	string str = "0";

	str.insert(1, "11");

	generateParenthesis1(2);

	cout<< str;

	system("pause");
	return 0;
}