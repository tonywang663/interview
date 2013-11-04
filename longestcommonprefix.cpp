#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
	if(strs.empty())
	{
		return "";
	}
	int len = strs.size();

	string prefix = "";

	for(int i = 0; i < strs[0].size(); i++)
	{
		bool ismatch = true;
		for(int j = 1; j < len; j++)
		{
			if(strs[j].size() < i || strs[0][i] != strs[j][i])
			{
				ismatch = false;
				break;		
			}
		}
		if(ismatch == true)
		{
			prefix += strs[0][i];
		}else
		{
			return prefix;
		}
	}
    return prefix;
}

int mainlongestcommonprefix()
{
//	string str1 = "aabab";
//	string str2 = "aacad";
	string str3 = "";
	vector<string> strs;
//	strs.push_back(str1);
//	strs.push_back(str2);
//	strs.push_back(str3);
	cout<<longestCommonPrefix(strs);
	system("pause");
	return 0;
}