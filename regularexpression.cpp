#include <iostream>
#include <cstring>

using namespace std;

bool isMatch(const char *s, const char *p) {
	if(s == NULL || p == NULL)
	{
		return false;
	}

	if(s[0] == '\0' && p[0] == '\0')
	{
		return true;
	}else if(p[0] == '\0')
	{
		return false;
	}

	if(p[1] != '*')
	{
		if(p[0] == s[0] ||(p[0] == '.' && s[0] != '\0'))
		{
			return isMatch(s + 1, p + 1);
		}else
		{
			return false; 
		}
	}
	int i = 0;
	while(s[i] != '\0' && (s[i] == p[0] || p[0] == '.') )
	{

		if(isMatch(s + i, p + 2))
		{
			return true;
		}

		i++;
	}

	return isMatch(s+i, p+2);
}

static bool helper(const char *s, const char *p){
	if(*s == 0 && *p == 0)
		return true;
	
	if(*p == 0)
		return false;

	if(p[1] != '*'){
		if(*s != 0 && (*s == *p || *p == '.')){
			return helper(s + 1, p + 1);
		}else
			return false;

	}else{
		if(helper(s, p + 2))
			return true;

		if(*s != 0 && (*s == *p || *p == '.')){
			if(helper(s + 1, p))
				return true;
		}
	}
	return false;
}

//08/22/2013
static bool isMatch1(const char *s, const char *p) {
	if(s == NULL && p == NULL)
		return true;
	else if(s == NULL || p == NULL)
		return false;

	return helper(s, p);
}

int mainisMatch1()
{
	cout<<isMatch1("ab", ".*c");
	system("pause");
	return 0;
}