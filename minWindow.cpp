#include <iostream>
#include <string>
#include <vector>
#include <map>
//#include <unordered_map>

using namespace std;

string minWindow(string S, string T) {

	int len1 = S.length();
	int len2 = T.length();

	if(len1 == 0 || len2 == 0){
		return "";
	}
	
	map<char, int> gmap;

	for(int i = 0; i < len2; i++){
		gmap[T[i]]++;
	}

	int index = 0;

	int hits = 0;
	int rb = -1, re = len1;
	int begin = 0;
	map<char, int> cmap;
	while(index < len1){
		if(gmap[S[index]] > 0){
			cmap[S[index]]++;
			if(cmap[S[index]] <= gmap[S[index]]){
				hits++;
			}
		}

		if(hits == len2){
			while(1){
				if(gmap[S[begin]] == 0){
					begin++;
					continue;
				}
				if(cmap[S[begin]] > gmap[S[begin]]){
					cmap[S[begin]]--;
					begin++;
					continue;
				}else{
					if(index - begin < re - rb){
						rb = begin;
						re = index;
					}
					cmap[S[begin]]--;
					hits--;
					begin++;
					break;
				}
			}
		}
		index++;
	}

	if(rb == -1)
		return "";
	else
		return S.substr(rb, re - rb + 1);
}

void mainminWindow(){
	minWindow("a", "aa");
}