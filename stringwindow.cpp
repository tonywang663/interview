#include <iostream>
#include <string>
#include <vector>
//#include <unorder_map>
#include <cstring>
using namespace std;

bool contain(const char* strlong, size_t start, size_t end, const char* str)
{
	for(int i = 0; i < strlen(str); i++)
	{
		bool isexist = false;
		for(int j = start; j <= end; j++)
		{
			if(strlong[j] == str[i])
			{
				isexist = true;
				break;
			}
		}
		if(!isexist)
		{
			return false;
		}
	}
	return true;
}

string window(const char* strlong, const char* strsmall)
{
	size_t lenl = strlen(strlong);
	size_t lens = strlen(strsmall);
	int start = 0, end = 0;
	bool isstart = true, isend = false;
	int temps = -1,  tempe = -1, templen = 1000;
	while(start < lenl && end < lenl)
	{
		if(isstart && !isend)
		{
			if(end - start + 1 >= lens)
			{
				if(contain(strlong, start, end, strsmall))
				{
					if(end - start + 1 < templen)
					{
						templen = end - start + 1;
						temps = start;
						tempe = end;
					}
					isstart = false;
					isend = true;
					end++;
					start = end - lens + 1;
				}else
				{
					end++;
				}
			}else
			{
				end++;
			}
		}else if(!isstart && isend)
		{
			if(end - start + 1 >= lens)
			{
				if(contain(strlong, start, end, strsmall))
				{
					if(end - start + 1 < templen)
					{
						templen = end - start + 1;
						temps = start;
						tempe = end;
					}
					isstart = true;
					isend = false;
					start++;
					end = lens - start - 1;
				}else
				{
					start--;
				}
			}else
			{
				start--;
			}
		}
	}
	return string(strlong + temps, strlong + tempe + 1);
}

//time complexity is o(n^2), if use a bitmap.
int main10()
{
//	string strlong, strsmall;
//	cin>>strlong;
//	cin>>strsmall;
	string strlong = "acdbabb";
	string strsmall = "ab";
	string res = window(strlong.c_str(), strsmall.c_str());
	cout<<res;
	system("pause");
	return 0;
}

