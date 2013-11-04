#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int trap1(int A[], int n) {

	int left = 0, right = 0;
	int sum = 0;
	while(left <= n - 1){
		int right = left + 1;
		int tempmax = left + 1;
		int tempsum = 0;
		while(right <= n - 1){
			if(A[right] >= A[left]){
				break;
			}
			if(A[right] >= A[tempmax]){
				tempmax = right;
				
			}
			right++;
		}

		if(right <= n - 1){
			for(int i = left + 1; i < right; i++){
				sum = sum + A[left] - A[i];
			}

			left = right;
		}else{
			for(int i = left + 1; i < tempmax; i++){
				sum = sum + A[tempmax] - A[i];
			}

			left = tempmax;
		}


	}

	return sum;

}


int trap(int A[], int n) {
	
	if(n < 3)
		return 0;
	
	int left = 0, right = n - 1;
	int height = min(A[left], A[right]);
	int sum = 0;
	int i = 0, j = n - 1;
	while(i < j){
		if(A[left] <= A[right]){
			i++;
			if(A[i] < A[left]){
				sum += height - A[i];
			}else{
				left = i;
			}
		}else{
			j--;
			if(A[j] < A[right]){
				sum += height - A[j];
			}else{
				right = j;
			}
		}
		height = min(A[left], A[right]);
	}
	return sum;
}

int trap2(int A[], int n) {
	if(n < 3)
		return 0;

	int res = 0;

	int unit = 0;

	int left = 0, right = n - 1;

	int i = 0, j = n - 1;

	while(i < j){
		if(A[left] <= A[right]){
			i++;
			if(A[i] < A[left]){
				res += A[left] - A[i];
			}else{
				left = i; 
			}
		}else{
			j--;
			if(A[j] < A[right]){
				res += A[right] - A[j];
			}else{
				right = j;
			}
		}

	}

	return res;
    
}

int maintrap()
{
	int A[] = {0, 2, 0};
	int x  = trap(A, 3);
	system("pause");
	return 0;
}