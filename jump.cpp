#include <iostream>

using namespace std;


int recurjump(int A[], int n, int pos, int hops)
{


	if(pos == n - 1){
		return hops;
	}

	int cur = A[pos];
	int minhop =  recurjump(A, n, pos + 1, hops + 1);
	for(int i = 2; i <= A[pos]; i++){
		if(pos + i > n - 1){
			break;
		}
		int temphop = recurjump(A, n, pos + i, hops + 1);
		if(temphop < minhop){
			minhop = temphop;
		}

	}
	return minhop;
}

int jump(int A[], int n) {
	if(n <= 1){
		return 0;
	}

	int **a = new int*[n];
	for(int i = 0; i <= n - 1; i++){
		a[i] = new int[n];
	}

	for(int i = 0; i <= n - 1; i++){
		for(int j = 0; j <= n - 1; j++){
			if(i == j){
				a[i][j] = 0;
			}else{
				a[i][j] = n;
			}
			
		}
	}

	for(int step = 1; step <= n - 1; step++){ 
		for(int i = n - 1 - step; i >= 0; i--){
			int minhop = (step - A[i] > 0)? step - A[i] + 1: 1;
			for(int j = 1; j <= step - 1; j++){
				if(a[i][i + j] + a[i + j][i + step] < minhop){
					minhop =  a[i][i + j] + a[i + j][i + step];
				}
			}
			a[i][i + step] = minhop;
		}
	}

	return a[0][n - 1];
}

//jump game I
int jump1(int A[], int n){
	int target = n - 1;
	int step  = 0;

	while(target > 0){
		int i = 0;

		for(; i <= n - 1; i++){
			if(i + A[i] >= target){
				break;
			}
		}

		target = i;
		step++;
		
	}
	return step;
}

//jump game II
int jump2(int A[], int n) {
	
	int index = 0;
	int step = 0;

	while(index  < n - 1){
		int nextindex = index;
		int max = 0;
		for(int i = 1; i <= A[index]; i++){
			if(i + index == n - 1){
				nextindex = i + index;
				break;
			}

			if(i + index + A[i + index] > max){
				nextindex = index + i;
				max = i + index + A[i + index];
			}
		}
		index = nextindex;
		step++;
	}

	return step; 
}



int mainjump()
{
	int A[] = {2, 1};
	jump(A, 2);
	system("pause");
	return 0;
}