#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

bool isclose(string s1, string s2){
	int diff = 0;

	for(int i = 0; i < s1.length(); i++){
		if(s1[i] != s2[i])
			diff++;
		if(diff > 1)
			return false;
	}

	return true;
}

int ladderLength(string start, string end, set<string> &dict) {
        int dsize = dict.size();

    queue<string> stk;

	stk.push(start);
	stk.push("");
	set<string> mset;
	mset.insert(start);
	int step = 2;
	int msetsize = 1;
	while(!stk.empty()){
		string str = stk.front();
		stk.pop();

		if(str == ""){
			step++;
			if(stk.empty())
				break;
			stk.push("");
			continue;
		}

		set<string>::iterator it = dict.begin();
		for(; it != dict.end(); it++){
			if(isclose(str, *it)){
				if(*it == end){
					return step;
				}

				if(mset.find(*it) == mset.end()){
					stk.push(*it);
					mset.insert(*it);
				}
			}
		}
	

	}
	return 0;
}

bool diffone(string s1, string s2){
	int diff = 0;
	for(int i = 0; i < s1.length(); i++){
		if(s1[i] != s2[i])
			diff++;
	}

	return diff == 1;

}

//08/10/2013
int ladderLength1(string start, string end, set<string> &dict) {

	set<string> curset;
	set<string> endset;

	if(start == end)
		return 1;

	set<string>::iterator it1 = dict.begin();

	curset.insert(start);

	int step = 0;
	while(1){
		it1 = curset.begin();
		for(; it1 != curset.end(); it1++){
			if(diffone(*it1, end)){
				return 2 + step;
			}
		}

		it1 = curset.begin();
		set<string> nextset;
		
		for(; it1 != curset.end(); it1++){
			set<string>::iterator it2 = dict.begin();
			for(; it2 != dict.end(); it2++){
				if(diffone(*it1, *it2))
					nextset.insert(*it2);
			}
		}
		if(curset.size() == nextset.size())
			return 0;

		curset = nextset;
		step++;
	}
	return 0;
}

int ladderLength2(string start, string end, set<string> &dict) {	
	if(start == end)
		return 1;

	queue<string> que;
	set<string> visited;
	
	que.push(start);
	que.push("");

	int step = 2;
	while(!que.empty()){
		string str = que.front();
		que.pop();

		if(str == ""){
			if(que.empty())
				return 0;
			else{
				que.push("");
				step++;
			}
		}else{
			if(diffone(str, end)){
				return step;
			}else{
				for(int i = 0; i < start.length(); i++){
					string tmp = str;
					for(char j = 'a'; j <= 'z'; j++){
						if(tmp[i] != j){
							tmp[i] = j;
							if(visited.count(tmp) == 0 && dict.count(tmp) > 0){
								que.push(tmp);
							}
						}
					}
				}

				visited.insert(str);
			}
		}
	}
	return 0;
}


void mainladderLength(){
	set<string> dict;
	dict.insert("hot");
	dict.insert("hit");
	dict.insert("cog");
	dict.insert("dot");
	dict.insert("dog");
	ladderLength("hit", "cog", dict);	
}