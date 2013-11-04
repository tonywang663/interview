#include <iostream>

using namespace std;

double pow0(double x, int n) {
	double res = 1;
	if(n == 0){
		return res;
	}

	if(n < 0){
		n = -n;
		x = 1 / x;
	}

	int bit = 0;
	for(int t = n; t > 0; t = t / 2){
		bit++;
	}

	

	for(int i = 0; i < bit; i++){
		int temp = 1 << (bit - i - 1);
		if((n & temp) == 0){
			res = res * res;
		}else{
			res = res * res;
			res = res * x;
		}
	}

	return res;
}




double pow1(double x, int n) {
	
	double res = 1;

	bool isneg = false;

	if(n < 0){
		n = -n;
		isneg = true;
	}

	int len = 0;

	int t = n;
	while(t > 0){
		t = t >> 1;
		len++;
	}

	for(int i = len; i >= 1; i--){
		int t = n & (1 << (i - 1));
		if(t > 0){
			res = res * res * x;	
		}else{
			res = res * res;
		}

	}

	if(isneg)
		res = 1 / res;
    
	return res;
}

int mainpow1()
{
	pow1(0.00000, 1); 
	system("pause");
	return 0;
}