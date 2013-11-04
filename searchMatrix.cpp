#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) {
	int m = matrix.size();
	if(m <= 0){
		return false;
	}
	int n = matrix[0].size();
    
	if(n <= 0){
		return false;
	}

	int left = 0, right = m - 1;

	while(left <= right){
		int mid = (left + right) / 2;
		if(matrix[mid][0] == target){
			return true;
		}

		if(matrix[mid][0] < target){
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}
	
	if(right < 0){
		return false;
	}

	int row = right;

	left = 0, right = n - 1;

	while(left <= right){
		int mid = (left + right) / 2;
		if(matrix[row][mid] == target){
			return true;
		}

		if(matrix[row][mid] < target){
			left = mid + 1;
		}else{
			right = mid - 1;
		}

	}

	return false;

}


//08/05/2013
bool searchMatrix1(vector<vector<int> > &matrix, int target) {
	int m = matrix.size();

	if(m <= 0)
		return false;

	int n = matrix[0].size();

	if(n <= 0)
		return false;

	int left = 0, right = m - 1;

	while(left <= right){
		int mid = (left + right) / 2;
		if(matrix[mid][0] == target)
			return true;

		if(matrix[mid][0] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	int index = right;

	if(index < 0)
		return false;

	left = 0;
	right = n - 1;

	while(left <= right){
		int mid = (left  + right) / 2;
		if(matrix[index][mid] == target)
			return true;

		if(matrix[index][mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
    
	return false;
}

void mainsearchMatrix(){

}