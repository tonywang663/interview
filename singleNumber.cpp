#include <map>

using namespace std;

int singleNumber(int A[], int n) {

	int res = A[0];

	for(int i = 1; i < n; i++){
		res ^= A[i];
	}

	return res;   
}

int singleNumber2(int A[], int n) {
    // Note: The Solution object is instantiated only once and is reused by each test case.

	int bitlen = sizeof(A[0]) * 8;

	int res = 0, x = 0;
	for(int i = 0; i < bitlen; i++){
		int ind = 0;
		x = 1 << i;
		for(int j = 0; j < n; j++){
			if((A[j] & x) != 0){						// not > 0
				ind++;
			}
		}
		if(ind % 3)
			res |= x;
	}

	return res;
}

void mainsingleNumber2(){
	int A[] = {1};

	singleNumber2(A, 1);
}