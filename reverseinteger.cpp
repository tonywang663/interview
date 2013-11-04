#include <iostream>
#include <cmath>

using namespace std;

int reverse(int x) {
	bool isneg = false;
	if(x < 0)
	{
		isneg = true;
		x = -x;
	}

	int res = 0;
	int tens = 0;
	while(x > 0)
	{
		int cur = x % 10;
		res = 10 * res + cur;
		x = x / 10;
		tens++;
	}
	if(isneg == true)
	{
		res = - res;
	}
	return res;
}

int reverse1(int x) {
	bool neg = false;

	if(x < 0){
		x = -x;
		neg = true;
	}

	int y = 0;

	while(x > 0){
		int t = x % 10;
		x = x / 10;
		y = y * 10 + t;
	}

	if(neg)
		y = -y;

	return y;
    
}


//09/09/2013
int reverse2(int x) {
	bool isneg = false;
	if(x < 0){
		x = -x;
		isneg = true;
	}

	int res = 0;
	while(x > 0){
		int t = x % 10;
		x = x / 10;
		res = res * 10 + t;
	}

	if(isneg)
		return -res;

	return res;
}

int mainreverse()
{
	
	cout<<reverse(321);
	system("pause");
	return 0;
}