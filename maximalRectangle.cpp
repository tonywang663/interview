#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximalRectangle(vector<vector<char> > &matrix) {
	int m = matrix.size();

	if(m <= 0){
		return 0;
	}

	int n = matrix[0].size();
	if(n == 0){
		return 0;
	}

	int** a = new int*[m];

	for(int i = 0; i < m; i++){
		a[i] = new int[n];
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(matrix[i][j] == '1'){
				a[i][j] = 1;
			}else{
				a[i][j] = 0;
			}
		}
	}

	for(int i = 0; i < m; i++){
		for(int j = 1; j < n; j++){
			if(a[i][j] == 0)
				continue;
			a[i][j] = a[i][j - 1] + 1;
		}
	}

	int max = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == 0)
				continue;
			int tempmax = 0;
			int h = a[i][j];
			for(int k = i; k < m; k++){
				if(a[k][j] == 0)
					break;
				if(a[k][j] < h){
					h = a[k][j];
				}
				int area = h * (k - i + 1);
				if(area > tempmax)
					tempmax = area;
			}
			if(tempmax > max)
				max = tempmax;
		}
	}

	return max;
}

//08/06/2013

int maximalRectangle1(vector<vector<char> > &matrix) {
	int m = matrix.size();
	if(m == 0)
		return 0;

	int n = matrix[0].size();
	if(n == 0)
		return 0;

	vector<vector<int>> dp(m, vector<int>(n, 0));

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(matrix[i][j] == '1')
				dp[i][j] = 1;
		}
	}

	for(int i = 0; i < m; i++){
		for(int j = 1; j < n; j++){
			if(dp[i][j] != 0){
				dp[i][j] += dp[i][j - 1];   // wrong! no +1
			}
		}
	}

	int area = 0;

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){

			int h = dp[i][j];
			for(int k = i; k >= 0; k--){
				if(dp[k][j] == 0)
					break;
				
				if(dp[k][j] < h)
					h = dp[k][j];

				area = max(area, h * (i - k + 1));
			}

		}
	}

	return area;
    
}

void mainmaximalRectangle1(){
	vector<char> vec;
	vec.push_back('0');
	vec.push_back('1');
	vector<vector<char>> vec1;
	vec1.push_back(vec);
	maximalRectangle1(vec1);
}