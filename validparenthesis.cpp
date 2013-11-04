#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isValid(string s) {
	int len = s.length();

	vector<char> vec(len);
	int j = 0;
	for(int i = 0; i <= len - 1; i++){
		if(s[i] != '{' && s[i] != '}' && s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']'){
			return false;
		}
		if(s[i] ==   '{' || s[i] ==   '(' || s[i] ==   '['){
			vec[j] = s[i];
			j++;
		}

		if(s[i] ==   '}' || s[i] ==   ')' || s[i] ==   ']'){
			if( (s[i] == '}' && vec[j - 1] == '{') || (s[i] == ')' && vec[j - 1] == '(') || (s[i] == ']' && vec[j - 1] == '[')  ){
				j--;
			}else{
				return false;
			}
		}


	}

	if(j == 0){
		return true;
	}else{
		return false;
	}
}

bool isValid1(string s) {
	int len = s.length();

	if(len <= 0)
		return true;

	stack<char> stk;

	for(int i = 0; i < len; i++){
		if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
			if(stk.empty())
				return false;

			if(s[i] == ')'){
				if(stk.top() != '('){
					return false;
				}else{
					stk.pop();
					continue;
				}
			}

			if(s[i] == ']'){
				if(stk.top() != '['){
					return false;
				}else{
					stk.pop();
					continue;
				}
			}

			if(s[i] == '}'){
				if(stk.top() != '{'){
					return false;
				}else{
					stk.pop();
					continue;
				}
			}

		}else{
			stk.push(s[i]);
		}
	}

	if(stk.empty())
		return true;

	return false;
    
}



int mainisValid1()
{

	system("pause");
	return 0;
}