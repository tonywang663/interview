#include <iostream>
#include <string>
#include <stack>

using namespace std;


string simplifyPath(string path) {
	stack<string> stk;

	int len = path.length();

	int state = 0;

	string res;
	int i = 0;
	string dir;
	while(i < len){
		switch(state){
			//init state
			case 0:
				if(path[i] == '/'){
					state = 1;
				}
				break;

			// /. or // or /a
			case 1:
				if(path[i] == '/'){
					state = 1;
				}else if(path[i] == '.'){
					state  = 2;
				}else {
					dir.push_back(path[i]);
					state = 3;
				}
				break;

			// /.what?
			case 2:
				if(path[i] == '/'){
					state = 1;
				}else if(path[i] == '.'){
					if(stk.empty())
						break;
					stk.pop();
					state = 0;
				}else {
					dir.push_back('.');
					dir.push_back(path[i]);
					state = 3;
				}
				break;
			
			// a+what
			case 3:
				if(path[i] == '/'){
					stk.push(dir);
					dir.clear();
					state = 1;
				}else{
					dir.push_back(path[i]);
				}
				break;
		}
		i++;
	}

	if(state == 3){
		stk.push(dir);
	}

	if(stk.empty()){
		res = "/";
	}else{
		while(!stk.empty()){
			string str = stk.top();
			stk.pop();
			res.insert(0, str);
			res.insert(0, 1, '/');
		}
	}

	return res;
}

void mainsimplifyPath(){

}