#include <iostream>
#include <string>

using namespace std;

int longestsubstring(const string& s)
{
	int length = s.length();
	int index[256];
	for(int i = 0; i < 256; i++)
	{
		index[i] = -1;
	}

	int i=0, j = 0;
	int max = 0;
	while(j <= length - 1)
	{
		if(index[s[j]] == -1)
		{
			index[s[j]] = 1;
			j++;

		}
		else
		{
			if(max < j - i)
			{
				max = j - i;
			}
			while(i <= j - 1)
			{
				index[s[i]] = -1;
				if(s[i] == s[j])
				{
					i++;
					break;
				}
				i++;
			}
		}
	}
	if(max < j - i)
	{
		max = j - i;
	}
	return max;
}




int mainlong()
{
	string s = "abcabcbb";
	cout<<longestsubstring(s)<<endl;
	system("pause");
	return 0;
}