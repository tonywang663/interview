#include <iostream>

using namespace std;


int firstMissingPositive2(int A[], int n) {

	for(int i = 0; i < n; i++){
		if(A[i] != i + 1){
			if(A[i] > 0 && A[i] <= n  && A[i] != A[A[i] - 1]){
				int temp = A[i];
				int ind = A[i] - 1;
				A[i] = A[ind];
				A[ind]  = temp;
				i--;
			}
		}
	}

	for(int i = 0; i < n; i++){
		if(A[i] != i + 1){
			return i + 1;
		}
	}

	return n + 1;
}



int firstMissingPositive(int A[], int n) {
	int i = 0;
	while(i <= n - 1){
		if(A[i] > 0 && A[i] <= n && A[i] != A[A[i] - 1]){
			int temp = A[i];
			int ind = A[i] - 1;
			A[i] = A[ind];
			A[ind] = temp;
		}else{
			i++;
		}
	}

	for(int i = 0; i < n; i++){
		if(A[i] != i + 1){
			return i + 1;
		}
	}

	return n + 1;
}

int firstMissingPositive3(int A[], int n) {
	int index = 0;

	while(index < n){
		if(A[index] <= 0){
			index++;
			continue;
		}

		if(A[index] > n){
			index++;
			continue;
		}

		if(A[index] == index + 1){
			index++;
			continue;
		}
		
		if(A[index] == A[A[index] - 1]){
			index++;
			continue;
		}

		int i1 = index;
		int i2 = A[index] - 1;
		int t = A[i1];
		A[i1] = A[i2];
		A[i2] = t;	
	}

	for(int i = 0; i < n; i++){
		if(A[i] != i + 1)
			return i + 1;
	}

	return n + 1;
    
}

int mainfirstMissingPositive3()
{

	int a[] = {2, 1};
	int b = firstMissingPositive3(a, 2);

	system("pause");
	return 0;
}