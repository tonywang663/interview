#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void nextPermutation1(vector<int> &num) {
	int nsize = num.size();

	if(nsize <= 1)
		return;

	int indr = 0, indl = 0;
	for(int i = nsize - 2; i >= 0; i--){
		bool find = false;
		for(int j = nsize - 1; j >= i + 1; j--){
			if(num[i] < num[j]){
				indl = i;
				indr = j;
				find = true;
				break;
			}
		}
		if(find){
			break;
		}
	}


	if(indr != 0){
		int temp = num[indr];
		num[indr] = num[indl];
		num[indl] = temp;
		for(int i = indl + 1; i <= (nsize + indl) / 2; i++){
			temp = num[i];
			num[i] = num[nsize - 1 - i + indl + 1];
			num[nsize - 1 - i + indl + 1] = temp;
		}

	}else{
		for(int i = 0; i <= (nsize - 1) / 2; i++){
			int temp = num[i];
			num[i] = num[nsize - 1 - i];
			num[nsize - 1 - i] = temp;
		}
	}
    
}

void nextPermutation(vector<int> &num) {
	int n = num.size() - 1;

	int ind = n;
	for(; ind >= 1; ind--){
		if(num[ind] > num[ind - 1])
			break;
	}
	
	int indr = n;
	int indl = ind - 1;
	if(ind != 0){
		for(int i = ind; i <= n; i++){
			if(num[indl] <= num[i - 1] && num[indl] >= num[i]){
				indr = i;
			}
		}
		int temp = num[indl];
		num[indl] = num[indr];
		num[indr] = temp;
	}


//	sort(num.begin() + ind, num.end());


}

void nextPermutation2(vector<int> &num) {
	int len = num.size();

	int index = -1;
	for(int i = len - 2; i >= 0; i--){
		if(num[i + 1] > num[i]){
			index = i;
			break;
		}
	}

	if(index == -1){
		sort(num.begin(), num.end());
		return;
	}

	for(int i = len - 1; i >= 0; i--){
		if(num[i] > num[index]){
			int t = num[index];
			num[index] = num[i];
			num[i] = t;
			break;
		}
	}
	
	sort(num.begin() + index + 1, num.end());
}

int mainnextPermutation2()
{

	system("pause");
	return 0;
}