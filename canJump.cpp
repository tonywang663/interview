#include <iostream>

using namespace std;




bool canJump(int A[], int n) {

	if(n <= 1){
		return true;
	}

	int i = n - 2;
	int goal = n - 1;
	while(i >= 0){
		int j = i;
		for(; j >= 0; j--){
			if(A[j] + j >= goal){
				break;
			}
		}

		if(j < 0){
			return false;
		}else {
			goal = j;
			i = j - 1;
		}

	}

	return true;
    
}


bool canJump1(int A[], int n) {
	int index = n - 1;
	int target = n - 1;

	while(target > 0){
		int i = index - 1;
		for(; i >= 0; i--){
			if(A[i] + i >= target)
				break;
		}

		if(i == -1)
			return false;

		target = i;
		index = i;

	}

	return true;
    
}

int maincanJump()
{
	return 0;

}