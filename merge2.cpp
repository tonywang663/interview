#include <iostream>

using namespace std;


void merge(int A[], int m, int B[], int n) {
	if(n == 0)
		return;

	int a = 0;
	int b = 0;

	int end = m - 1;

	while(b <= n - 1){
		if(a > end){
			for(int i = b; i <= n - 1; i++){
				 A[a++] = B[i];
			}
			break;
		}

		if(B[b] <= A[a]){
			for(int i = end; i >= a; i--){
				A[i + 1] = A[i];
			}
			A[a] = B[b];
			b++;
			end++;
			a++;
		}else{
			a++;
		}

	}
    
}

//merge two sorted arrays
//08/07/2013
void merge1(int A[], int m, int B[], int n) {
	
	int  ai = 0, ae = m - 1;
	int  bi = 0;

	while(bi < n){
		while(ai <= ae && A[ai] <= B[bi]){
			ai++;
		}

		if(ai == ae && A[ai] <= B[bi]){
			ae++;
			A[ae] = B[bi];
		}else{
			ae++;
			for(int i = ae; i >= ai + 1; i--){
				A[i] = A[i - 1];
			}
			A[ai] = B[bi];
		}
		ai++;
		bi++;
	}
	
}

void mainmerge(){

}