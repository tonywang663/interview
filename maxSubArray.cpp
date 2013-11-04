#include <iostream>

using namespace std;

int maxSubArray(int A[], int n) {

	int maxsum = A[0];
	int cursum = 0;
	for(int i = 1; i < n; i++){
		if(A[i] > maxsum)
			maxsum = A[i];
	}


	for(int i = 0; i < n; i++){
		if(cursum + A[i] < 0){
			cursum = 0;
		}else{
			cursum = cursum + A[i];
			if(cursum > maxsum){
				maxsum = cursum;
			}
		}

	}
	return maxsum;
    
}

int maxSubArray1(int A[], int n) {
	int maxsum = A[0];
	int cursum = 0;
	for(int i = 0; i < n; i++){
		if(cursum < 0)
			cursum = 0;
		cursum = cursum + A[i];
		if(cursum > maxsum)
			maxsum = cursum;
	}
	return maxsum;
}

int maxSubArray2(int A[], int n) {
	int res = A[0];

	for(int i = 1; i < n; i++){
		if(A[i] > res)
			res = A[i];
	}

	int index = 0;

	int cur = 0;
	while(index < n){
		cur += A[index];
		if(cur < 0){
			cur = 0;
		}else{
			if(cur > res)
				res = cur;
		}
		index++;
	}

	return res;
    
}

int mainmaxSubArray()
{
	return 0;
}