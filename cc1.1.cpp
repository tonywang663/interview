#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;

int test(const string& str)
{
	assert(str.length()>0);
	int map[256];
	for(size_t i = 0; i < 255; i++)
	{
		map[i] = 0;
	}
	size_t len = str.length();
	for(size_t i = 0; i < len - 1; i++)
	{
		if( map[str[i]] == 0)
		{
			map[str[i]] = 1;
		}else
		{
			cout<<"duplication!\n";
			return 0;
		}
	}

}


int maincc11()
{
	string str;
//	cin>>str;

//	test(str);
	vector<int> r;
	r[1] = 1;
	r[2] = 2;
	system("pause");
	return 0;
}