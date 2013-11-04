#include <vector>

using namespace std;


int candy(vector<int> &ratings) {
	int sum = 0;

	int len = ratings.size();

	if(len == 0)
		return 0;

	vector<int> candy(len, 1);

	for(int i = 0; i <= len - 2; i++){
		if(ratings[i] > ratings[i + 1]){
			int j = i;
			while(j >= 0 && ratings[j] > ratings[j + 1] && candy[j] <= candy[j + 1]){
				candy[j]++;
				j--;
			}
		}else if(ratings[i] < ratings[i + 1])
			candy[i + 1] = candy[i] + 1;			
	}

	for(int i = 0; i < len; i++)
		sum += candy[i];

	return sum;
}

int candy1(vector<int> &ratings) {
	int len = ratings.size();

	int sum = 0;

	if(len == 0)
		return 0;

	vector<int> candy(len, 1);

	for(int i = 1; i <= len - 1; i++){
		if(ratings[i] > ratings[i - 1])
			candy[i] = candy[i - 1] + 1;
	}

	for(int i = len - 2; i >= 0; i--){
		if(ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1] + 1)
			candy[i] = candy[i + 1] + 1;
	}

	for(int i = 0; i < len; i++)
		sum += candy[i];

	return sum;

}



void maincandy(){
	int a[] = {4,2,3,4,1};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));

	candy1(vec) ;
}