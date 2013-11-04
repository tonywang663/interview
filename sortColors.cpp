#include <iostream>

using namespace std;

void sortColors(int A[], int n) {
	if(n == 0){
		return;
	}

	int a = -1, b = -1, c = -1;

	int i = 0;

	while(i <= n - 1){
		if(A[i] == 0){
			A[++a] = 0;
			if(b >= 0 && b != a - 1)
				A[++b] = 1;
			else
				b = a;
			if(c >= 0 && c != b - 1)
				A[++c] = 2;
			else
				c = b;
			i++;
			continue;
		}
		
		if(A[i] == 1){
			A[++b] = 1;
			if(c >= 0 && c != b - 1){
				A[++c] = 2;
			}else
				c = b;
			i++;
			continue;
		}

		if(A[i] == 2){
			A[++c] = 2;
			i++;
			continue;
		}

	}
    
}

void swap(int A[], int i, int j){
	int t = A[i];
	A[i] = A[j];
	A[j] = t;
}

//08/05/2013
void sortColors1(int A[], int n) {
	if(n <= 1)
		return;

	int i0 = 0, i2 = n - 1, index = 0;

	while(index <= i2){
		if(A[index] == 0){
			swap(A, index, i0);
			i0++;
			index++;
		}else if(A[index] == 2){
			swap(A, index, i2);
			i2--;
		}else
		    index++;		
	}
}

void mainsortColors(){

}