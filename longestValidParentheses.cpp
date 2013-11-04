#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int longestValidParentheses(string s) {
	stack<int> stk;
	int longest = 0;
	for(int i = 0; i <= s.size(); i++){
		char c = s[i];
		
		if(c == '('){
			stk.push(i);
		}else if(c == ')'){
			if(!stk.empty() && s[stk.top()] == '('){
				stk.pop();
				longest = max( stk.empty() ? i + 1: i-stk.top() , longest);
			}else{
				stk.push(i);
			}
		}
	}

	return longest;

    
}

int longestValidParentheses1(string s) {
	int len = s.length();

	if(len <= 0)
		return 0;

	stack<int> stk;

	int max = 0;
	for(int i = 0; i < len; i++){
		if(s[i] == '('){
			stk.push(i);
		}else{
			if(stk.empty() || s[stk.top()] == ')'){
				stk.push(i);
				continue;
			}


			stk.pop();
			

			int left = -1;
			if(!stk.empty())
				left = stk.top();

			if(i - left > max)
				max = i - left;
		}
	}
    
	return max;
}

int mainlongestValidParentheses()
{
	longestValidParentheses("()(()");
	system("pause");
	return 0;
}