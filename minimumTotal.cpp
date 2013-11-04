#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int> > &triangle) {
	int len = triangle.size();

	if(len == 0)
		return 0;

	vector<int> a(len, 0);
	vector<int> b(len, 0);

	a[0] = triangle[0][0];
	for(int i = 1; i < len; i++){
		for(int j = 0; j <= i; j++){
			if(j == 0){
				b[0] = a[0] + triangle[i][0]; 
				continue;
			}

			if(j == i){
				b[j] = a[j - 1] + triangle[i][j];
				continue;
			}

			b[j] = min(a[j], a[j - 1]) + triangle[i][j];

		}
		for(int j = 0; j <= i; j++){
			a[j] = b[j];
			b[j] = 0;
		}
	}

	int min = a[0];
	for(int i = 1; i < len; i++){
		if(a[i] < min)
			min = a[i];
	}

	return min;
    
}

void mainminimumTotal(){
	int a1[] = {1};
	int a2[] = {1, 2};
	vector<int> v1(a1, a1 + sizeof(a1) / sizeof(int));
	vector<int> v2(a2, a2 + sizeof(a2) / sizeof(int));

	vector<vector<int>> vec;
	vec.push_back(v1);
	vec.push_back(v2);

	minimumTotal(vec);
}