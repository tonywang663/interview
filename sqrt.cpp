#include <iostream>
#include <cmath>
using namespace std;

int sqrt(int x) {
	double x0 = 10;
	
	double x1;
	while(1){
		if(abs(x0 * x0 - x) < 0.1 ){
			return x0;
		}

		x1 = x0 - (x0 * x0 - x) / (2 * x0);
		x0 = x1;
	}
    
}










int sqrt1(int x) {
	double x0 = 10;
	double x1 = 0;
	while(1){
		if(abs(x0 * x0 - x) < 0.01)
			return x0;

		x1 = x0 - (x0 * x0 - x) / (2 * x0);
		x0 = x1;
	}
    
}

void mainsqrt(){
sqrt(16);
}