#include <iostream>

using namespace std;

bool search2(int A[], int n, int target) {
	if(n <= 0){
		return false;
	}

	int left = 0, right = n - 1;

	while(left <= right){
		int mid = (left + right) / 2;
		if(A[mid] == target){
			return true;
		}
		
		if(A[left] < A[mid]){
			if(target < A[mid] && target >= A[left]){
				right = mid - 1;
			}else{
				left = mid + 1;
			}
		}else if(A[left] > A[mid]){
			if(target > A[mid] && target <= A[right]){
				left = mid + 1;
			}else{
				right = mid - 1;
			}
		}else if(A[left] == A[mid]){
			left++;
		}

	}

	return false;
}






//08/06/2013
bool search21(int A[], int n, int target) {
	if(n <= 0)
		return false;

	int left = 0, right = n - 1;

	while(left <= right){
		int mid = (left + right) / 2;
		
		if(A[mid] == target)
			return true;

		if(A[mid] > A[left]){
			if(A[mid] > target){
				if(A[left] > target){
					left = mid + 1;
				}else{
					right = mid - 1;
				}
			}else{
				left = mid + 1;
			}
		}else if(A[mid] < A[left]){
			if(A[mid] > target){
				right = mid - 1;
			}else{
				if(target > A[right]){
					right = mid - 1;
				}else{
					left = mid + 1;
				}
			}
		}else if(A[mid] == A[left]){
			left++;
		}

	}

    return false;
}

void mainsearch2(){

}