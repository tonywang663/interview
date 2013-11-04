#include <iostream>

using namespace std;

int removeDuplicates2(int A[], int n) {
	if(n <= 0){
		return 0;
	}	

	int i = 0, end = n - 1;

	while(i <= end){
		int left = i;
		int right = i;
		while(right <= end && A[right] == A[left]){
			right++;
		}
		right--;

		int len = right - left + 1 - 2;

		if(len > 0){
			for(int newb = right + 1; newb <= end; newb++){
				 A[newb - len] = A[newb];
			}
			end = end - len;
		}

		
		if(right - left + 1 >= 2)
			i = i + 2;
		else
			i++;
	}

	return end + 1;

}

//08/06/2013
int removeDuplicates21(int A[], int n) {
	if(n <= 2)
		return n;

	int index = 0, end = n - 1;

	while(index <= end){
		
		while(index + 2 <= end && A[index] == A[index + 2]){
			for(int i = index; i < end; i++){

					A[i] = A[i + 1];

			}
			end--;
		}

		index++;

	}

	return end + 1;
}

void mainremoveDuplicates2(){

}