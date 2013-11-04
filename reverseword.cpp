#include <iostream>
#include <cstring>
#include <string>
#include <cassert>

using namespace std;

void reverse(char* str, int start, int len)
{
	assert(str != NULL && start >= 0 && len > 0);
	for(int i = 0; i < len / 2; i++)
	{
		char temp = str[start + i];
		str[start + i] = str[start + len - 1 - i];
		str[start + len - 1 - i] = temp;
	}
}

void reverse_sen(char* str, size_t len)
{
	assert(str != NULL);
	size_t start = 0, cur = 0;
	size_t curpos = 0, wordstartpos = 0, wordendpos = 0;
	bool iswordstart = false, iswordend = false;
	while(curpos <= len)
	{
		if(str[curpos] == ' ' || str[curpos] == '\n' || str[curpos] == '\0')
		{
			if(iswordstart == true && iswordend == false)
			{
				wordendpos = curpos - 1;
				reverse(str, wordstartpos, wordendpos - wordstartpos + 1);
				iswordstart = false;
				iswordend = false;
			}
			curpos++;
			continue;
		}else {
			if(iswordstart == false)
			{
				iswordstart = true;
				wordstartpos = curpos;
			}
		}

		curpos++;
	}
	reverse(str, 0, len);
}

int main9()
{
	char str[100];
	fgets(str, 100, stdin);
	reverse_sen(str, strlen(str));
	cout<<str;
	system("pause");
	return 0;
}