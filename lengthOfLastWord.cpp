#include <iostream>
#include <cstring>

using namespace std;

int lengthOfLastWord(const char *s) {
	int len = strlen(s);

	for(int i = len - 1; i >= 0; i--){
		if(s[i] != ' '){
			int right = i;
			int j = i - 1;
			for(; j >= 0; j--){
				if(s[j] == ' '){
					break;
				}
			}
			return i - j;
		}
	}
	return 0;
}

int mainlengthOfLastWord()
{
	return 0;
}
