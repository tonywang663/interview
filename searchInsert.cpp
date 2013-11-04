#include <iostream>

using namespace std;

int searchInsert(int A[], int n, int target) {
    if(n <= 0){
		return -1;
	}

	if(target > A[n - 1]){
		return n;
	}

	if(target < A[0]){
		return 0;
	}

	int left = 0, right = n - 1;

	while(left <= right){
		int mid = (left + right) / 2;

		if(A[mid] == target){
			return mid;
		}
        
        if(left == right){
            if(A[mid] >= target){
                
                return mid;
            }else{
                return mid + 1;
            }
        }

		if(right - left == 1){
			if(A[right] == target){
				return right;
			}
			if(A[left] == target){
				return left;
			}
			return right;
		}

		if(A[mid] >= target){
			right = mid;
		}else{
			left = mid;
		}
	}
    return -1;
}

int searchInsert1(int A[], int n, int target) {

	int left = 0, right = n - 1;

	while(left <= right){
		int mid = (left + right) / 2;

		if(A[mid] == target)
			return mid;

		if(A[mid] > target){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}

	return left;
    
}

int mainsearchInsert()
{
	return 0;
}