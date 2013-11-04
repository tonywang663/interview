#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(int A[], int n, int target) {
	vector<int> res(2, -1);
	if(n <= 0){
		return res;
	}

	int left = 0, right = n - 1;
	
	int lres = -1, rres = -1;
	while(left <= right){
		int mid = (left + right) / 2;
		if(A[mid] == target){
			if(mid == 0){
				lres = 0;
				break;
			}else if(A[mid - 1] != target){
				lres = mid;
				break;
			}
		}

		if(A[mid] >= target){
			right = mid - 1;
		}else {
			left = mid + 1;
		}
	}

	if(lres == -1){
		return res;
	}

	left = 0, right = n - 1;
	
	while(left <= right){
		int mid = (left + right) / 2;
		if(A[mid] == target){
			if(mid == n - 1){
				rres = n - 1;
				break;
			}else if(A[mid + 1] != target){
				rres = mid;
				break;
			}
		}

		if(A[mid] <= target){
			left = mid + 1;
		}else {
			right = mid - 1;
		}
	}

	res[0] = lres;
	res[1] = rres;
	return res;

    
}

vector<int> searchRange1(int A[], int n, int target) {
	vector<int> res;

	res.push_back(-1);
	res.push_back(-1);

	int left = 0, right = n - 1;

	int lindex = -1, rindex = -1;

	while(left <= right){
		int mid = (left + right) / 2;

		if(A[mid] == target){
			if(mid == 0 || A[mid] != A[mid - 1]){
				lindex = mid;
				break;
			}
		}

		if(A[mid] >= target){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}

	if(lindex == -1){
		return res;
	}

	left = 0;
	right = n - 1;
	while(left <= right){
		int mid = (left + right) / 2;

		if(A[mid] == target){
			if(mid == n - 1 || A[mid] != A[mid + 1]){
				rindex = mid;
				break;
			}
		}

		if(A[mid] > target){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}

	res[0] = lindex;
	res[1] = rindex;
	
	return res;
}

void mainsearchRange1()
{

}