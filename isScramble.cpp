#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


bool resScr(string s1, string s2){
	int len1 = s1.length();
	int len2 = s2.length();

	if(len1 != len2){
		return false;
	}

	if(len1 == 1){
		if(s1 == s2)
			return true;
		else
			return false;
	}

	map<char, int> wordmap1;
	map<char, int> wordmap2;

	for(int i = 0; i < len1; i++){
		wordmap1[s1[i]]++;
		wordmap2[s2[i]]++;
	}

	map<char,int>::iterator it;
	for(it = wordmap1.begin(); it != wordmap1.end(); it++){
		if(it->second != wordmap2[it->first]){
			return false;
		}
	}

	for(int i = 1; i <= len1 - 1; i++){
		string s11 = s1.substr(0, i);
		string s12 = s1.substr(i, len1 - i);

		string s21 = s2.substr(0, i);
		string s22 = s2.substr(i, len1 - i);

		string s31 = s2.substr(0, len1 - i);
		string s32 = s2.substr(len1 - i, i);

		if( (resScr(s11, s21) && resScr(s12, s22)) || (resScr(s11, s32) && resScr(s12, s31))){
			return true;
		}
	}
	return false;
}


bool isScramble(string s1, string s2) {
	return resScr(s1, s2);
    
}



static bool helper(string& s1, string& s2){
	int len1 = s1.length();
	int len2 = s2.length();

	string sort1 = s1, sort2 = s2;
	sort(sort1.begin(), sort1.end());
	sort(sort2.begin(), sort2.end());

	if(sort1 != sort2)
		return false;

	if(len1 <= 2)
		return true;

	for(int i = 1; i <= len1 - 1; i++){
		string s11 = s1.substr(0, i);
		string s12 = s1.substr(i, len1 - i);

		string s21 = s2.substr(0, i);
		string s22 = s2.substr(i, len1 - i);

		string s31 = s2.substr(0, len1 - i);
		string s32 = s2.substr(len1 - i, i);

		if( (helper(s11, s21) && helper(s12, s22)) || (helper(s11, s32) && helper(s12, s31)))
			return true;
	}
	return false;
}

//08/07/2013
bool isScramble1(string s1, string s2) {
	return helper(s1, s2);
}

void mainisScramble1(){

}