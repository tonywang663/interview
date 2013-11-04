#include <iostream>

using namespace std;

int removeElement(int A[], int n, int elem) {
	if(n <= 0){
		return n;
	}

	int i = 0, j = n - 1;
	while(i <= j){
		while(A[i] != elem && i <= j){
			i++;
		}
		while(A[j] == elem && j >= i){
			j--;
		}
		if(i >= j){
			return j + 1;
		}
		A[i] = A[j];
		i++;
		j--;
	
	}
	
	return j + 1;
}


int mainremoveElement()
{

	system("pause");
	return 0;
}