#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;


int lengthOfLongestSubstring(string s) {
	int res = 0;

	if(s.empty() == true)
		return res;


	int i = 0, j = 0;

	int len = s.length();

	map<char, int> wmap;
	wmap[s[0]] = 0;
	while(i <= len - 1){
		bool isdup = false;
		for(j = i + 1; j <= len - 1; j++){
			if(wmap.count(s[j]) > 0){
				
				isdup = true;
				if(j - 1 - i + 1 > res)
					res = j - i;
				i = wmap[s[j]] + 1;
				wmap.clear();
				wmap[s[i]] = i;
				break;
			}else{
				wmap[s[j]] = j;
			}
		}

		if(j > len - 1)
			j = len - 1;

		if(!isdup){
			if(j - i + 1 > res)
				res = j - i + 1;
			break;
		}

	}

	return res;
    
}

int lengthOfLongestSubstring1(string s) {

	if(s.empty() == true)
		return 0;

	int i = 0, j = 1;

	int len = s.length();

	map<char, int> wmap;
	wmap[s[0]] = 0;

	int res = 1;
	while(j <= len - 1){
		if(wmap.count(s[j]) == 0){
			wmap[s[j]] = j;
			if(j - i + 1 > res)
				res = j - i + 1;
			j++;
		}else{
			int tlen = j - 1 - i + 1;
			if(tlen > res)
				res = tlen;
			i = wmap[s[j]] + 1;
			j = i + 1;
			wmap.clear();
			wmap[s[i]] = i;
		}

	}

	return res;
}

//08/25/2013
int lengthOfLongestSubstring2(string s) {
	int len = s.length();
	if(len <= 0)
		return 0;

	set<char> wset;

	int left = 0, right = 0;

	int max = 1;

	while(right < len){
		if(wset.count(s[right]) == 0){
			wset.insert(s[right]);
			if(right - left + 1 > max)
				max = right - left + 1;
			right++;
		}else{
			while(s[left] != s[right]){
				wset.erase(s[left]);
				left++;
			}
			wset.erase(s[left]);
			left++;
		}
	}
    return max;
}


//09/08/2013
int lengthOfLongestSubstring3(string s) {
	     int len = s.length();

	if(len <= 0)
		return 0;

	int max = 1;

	map<char, int> wmap;

	int left = 0, right = 0;

	while(right < len){
		if(wmap[s[right]] == 0){
			wmap[s[right]]++;
			if(right - left + 1 > max)
				max = right - left + 1;
			right++;
		}else{
			while(s[left] != s[right]){
				wmap[s[left]] = 0;						//error
			    left++;
			}
			wmap[s[left]] = 0;
			left++;
		}

	}

	return max;
}

void mainlengthOfLongestSubstring3(){
	string s("abcabcbb");

	lengthOfLongestSubstring3(s);

}