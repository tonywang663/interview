#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n) {
	if(n <= 1){
		return n;
	}

	int i = 0;
	int tail = n - 1;
	while(i < tail){
		if(A[i] == A[i+1]){
			if(i + 1 == tail){
				tail--;
			}else{
				for(int j = i + 2; j <= tail; j++){
					A[j - 1] = A[j];
				}
				tail--;
			}
		}else{
			i++;
		}

	}
	return tail + 1;
    
}

int removeD2(int A[], int n){
	if(n <= 1){
		return n;
	}

	int i = 0;
	int tail = n - 1;
	while(i < tail){
		int k = i + 1;
		for(; k <= tail; k++){
			if(A[k] != A[i]){
				break;
			}
		}
		k--;
		if(k == i){
			i++;
		}else{
			for(int j = k + 1; j <= tail; j++){
				A[j - k + i] = A[j];
			}
			tail = tail - (k - i);
		}

	}
	return tail + 1;
	
}

int removeDuplicates3(int A[], int n) {
	if(n <= 1)
		return n;

	int index = 0;

	int curlen = n;

	while(index <= curlen - 1){
		int right = index + 1;

		while(right < curlen && A[right] == A[index])
			right++;

		right--;

		if(right == index){
			index++;
			continue;
		}

		if(right == curlen - 1){
			curlen = index + 1;
			break;
		}

		for(int i = right + 1; i <= curlen - 1; i++){
			A[i - right + index] = A[i]; 
		}

		curlen = curlen - right  + index;
		index++;
	}

	return curlen;
}

int mainremoveDuplicates3()
{
	int a[] = {1, 1, 2};
	removeDuplicates3(a, 3);
	system("pause");
	return 0;
}