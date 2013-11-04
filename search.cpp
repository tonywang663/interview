#include <iostream>

using namespace std;


int search(int A[], int n, int target) {
	if(n <= 0){
		return -1;
	}

	int left = 0, right = n - 1;
	while(left <= right){
		int mid = (left + right) / 2;
		if(target == A[mid]){
			return mid;
		}

		// in the left acsending sequence
		if(A[left] <= A[mid]){
			if(target >= A[left] && target <= A[mid]){
				right = mid - 1;
			}else{
				left = mid + 1;
			}
		}else{
			if(target >= A[mid] && target <= A[right]){
				left = mid + 1;
			}else{
				right = mid - 1;
			}
			
				
		}
	
		
	}
	return -1;
    
}

int search1(int A[], int n, int target) {
	if(n <= 0)
		return -1;

	int left = 0, right = n - 1;

	while(left <= right){
		int mid = (left + right) / 2;
		
		if(A[mid] == target)
			return mid;

		if(A[left] <= A[mid]){
			if(A[mid] < target)
				left = mid + 1;
			else{
				if(A[left] <= target)
					right = mid - 1;
				else
					left = mid + 1;
			}
		}else{
			if(A[mid] > target){
				right = mid - 1;
			}else{
				if(A[right] >= target)
					left = mid + 1;
				else
					right = mid - 1;
			}

		}
	}

	return -1;
    
}

int mainsearch()
{
	int A[] = {4,5,6,7,8,1,2,3};
	int target = 0;
	int x  = search(A, 8, 8);
	system("pause");
	return 0;
}