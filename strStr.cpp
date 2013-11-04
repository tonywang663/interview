#include <iostream>
#include <cstring>

using namespace std;

char *strStr(char *haystack, char *needle) {
	if(haystack == NULL || needle == NULL){
		return NULL;
	}

	int len1 = strlen(haystack);
	int len2 = strlen(needle);
    
	for(int i = 0; i <= len1 - 1 - len2 + 1; i++){
		bool match = true;
		for(int j = 0; j <= len2 - 1; j++){
			if(haystack[i + j] != needle[j]){
				match = false;
			}
		}
		if(match == true){
			return haystack + i;
		}
	}
	return NULL;
}

char *strStr1(char *haystack, char *needle) {
	int len1 = strlen(haystack);
	int len2 = strlen(needle);

	for(int i = 0; i <= len1 - len2; i++){
		char* p1 = haystack + i;
		char* p2 = needle;	
		while(*p1 && *p1 == *p2){
			p1++;
			p2++;
		}
		if(*p2 == '\0')
			return haystack + i;
	}

	return NULL;
}

int mainstrStr()
{

	system("pause");
	return 0;
}