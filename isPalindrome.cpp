#include <iostream>
#include <string>
#include <algorithm>
#include <cmath> 

using namespace std;

bool isPalindrome(string s) {
	int len = s.length();
	if(len <= 1)
		return true;

	int left = 0, right = len - 1;
//	transform(s.begin(), s.end(), s.begin(), tolower);

	for(int i = 0; i < len; i++){
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - ('A' - 'a');

	}

	while(left < right){
		if(!(s[left] >= 'a' && s[left] <= 'z') &&  !(s[left] >= '0' && s[left] <= '9')){
			left++;
			continue;
		}

		if(!(s[right] >= 'a' && s[right] <= 'z') &&  !(s[right] >= '0' && s[right] <= '9')){
			right--;
			continue;
		}

		if(s[left] != s[right])
			return false;
		else{
			left++;
			right--;
		}

	}

	return true;

}

//08/10/2013
bool isPalindrome1(string s) {
	int len = s.length();

	if(len == 0)
		return true;

	for(int i = 0; i < len; i++){
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] -= 'A' - 'a';
	}

	int left = 0, right = len - 1;

	while(left < right){
		if(!(s[left] >= 'a' && s[left] <= 'z') && !(s[left] >= '1' && s[left] <= '9')){
			left++;
			continue;
		}

		if(!(s[right] >= 'a' && s[right] <= 'z') && !(s[right] >= '1' && s[right] <= '9')){
			right--;
			continue;
		}

		if(s[left] != s[right])
			return false;
		else{
			left++;
			right--;
		}
	}
	return true;
    
}



void mainisPalindrome1(){
	cout<<INT_MAX;
	system("pause");
}