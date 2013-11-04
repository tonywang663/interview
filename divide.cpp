#include <iostream>
#include <cmath>

using namespace std;

int divide(int dividend, int divisor) {
	

	long long a = dividend;
	long long b = divisor;
	if(a < 0){
		a = -a;
	}
	if(b < 0){
		b = -b;
	}

	int res = 0;
	while(a >= b){
		int t = a;
		int digits = 0;
		while(t >= b){
			if(t>>1 >= b){
				digits++;
				t = t>>1;
			}else{
				break;
			}
		}

		res = res + (1 << digits); 
		a =  a - (b << digits);
	}
	
	if( (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)){
		return -res;
	}
	return res;
}


int divide1(int dividend, int divisor) {
	long long res = 0;

	int len1 = 0;

	long long a = dividend;

	long long b = divisor;

	bool isneg = false;
	if(a < 0){
		isneg = !isneg;
		a = -a;
	}

	if(b < 0){
		isneg = !isneg;
		b = -b;
	}

	long long p = a;
	while(p > 0){
		p = p>>1;
		len1++;
	}

	int len2 = 0;
	p = b;
	while(p > 0){
		p = p>>1;
		len2++;
	}

	int index = len1 - len2;

	while(index >= 0){
		long long t = b << index;
		if(a - t < 0){
			res = res<<1;
		}else{
			a-= t;
			res = (res<<1) + 1;
		}
		index--;
	}

	if(!isneg)
		return res;
	else
		return -res;
}



int maind()
{
	int n = divide1(-2147483648, 2);
	cout<<n;
	system("pause");
	return 0;
}