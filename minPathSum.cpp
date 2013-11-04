#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int> > &grid) {
	int m = grid.size();
	if(m == 0){
		return 0;
	}

	int n = grid[0].size();
	if(n == 0){
		return 0;
	}

	int **a = new int*[m];
	for(int i = 0; i < m; i++){
		a[i] = new int[n];
	}

	a[0][0] = grid[0][0];
	for(int i = 1; i < m; i++){
		a[i][0] = a[i - 1][0] + grid[i][0];
	}

	for(int j = 1; j < n; j++){
		a[0][j] = a[0][j - 1] + grid[0][j];
	}

	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			a[i][j] = min(a[i - 1][j], a[i][j - 1]) + grid[i][j];
		}
	}

	return a[m - 1][n - 1];
    
}

int mainminPathSum()
{
	return 0;
}