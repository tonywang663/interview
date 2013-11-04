#include <iostream>
#include <vector>

using namespace std;


void respath(int m, int n, int x, int y, int& num){
	if(x == m - 1 && y == n - 1){
		num++;
		return;
	}

	if(x + 1 <= m - 1){
		respath(m, n, x + 1, y, num);
	}

	if(y + 1 <= n - 1){
		respath(m, n, x, y + 1, num);
	}

}

int uniquePaths(int m, int n) {
	
	int num = 0;
	respath(m, n, 0, 0, num);

	return num; 
}


int uniquePaths1(int m, int n) {
	int** a = new int*[m];
	for(int i = 0; i < m; i++){
		a[i] = new int[n];
	}

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			a[i][j] = 0;

	for(int i = 0; i < m; i++)
		a[i][0] = 1;

	for(int j = 0; j < n; j++)
		a[0][j] = 1;

	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			a[i][j] += a[i-1][j];
			for(int k = j - 1; k >= 0; k--){
				a[i][j] += a[i-1][k];
			}
		}
	}

	return a[m-1][n-1];

}


int uniquePaths2(vector<vector<int> > &obstacleGrid) {
	int m = obstacleGrid.size();
	if(m <= 0){
		return 0;
	}

	int n = obstacleGrid[0].size();

	if(n <= 0){
		return 0;
	}


	int** a = new int*[m];
	for(int i = 0; i < m; i++){
		a[i] = new int[n];
	}

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			a[i][j] = 0;

	bool blocked = false;
	for(int i = 0; i < m; i++){
		if(obstacleGrid[i][0] == 1){
			blocked = true;
		}

		if(!blocked){
			a[i][0] = 1;
		}else{
			a[i][0] = 0;
		}
	}
		
	blocked = false;
	for(int j = 0; j < n; j++){
		if(obstacleGrid[0][j] == 1){
			blocked = true;
		}

		if(!blocked){
			a[0][j] = 1;
		}else{
			a[0][j] = 0;
		}
	}


	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			if(obstacleGrid[i][j] == 0)
				a[i][j] = a[i - 1][j] + a[i][j - 1];
			else
				a[i][j] = 0;
		}
	}

	return a[m-1][n-1];

}


int uniquePaths11(int m, int n) {
	if(m <= 0 || n <= 0)
		return 0;

	vector<vector<int>> dp(m, vector<int>(n, 0));

	for(int i = 0; i < m; i++){
		dp[i][0] = 1;
	}

	for(int j = 0; j < n; j++){
		dp[0][j] = 1;
	}

	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	return dp[m - 1][n - 1];
    
}

int uniquePathsWithObstacles2(vector<vector<int> > &obstacleGrid) {
	int m = obstacleGrid.size();

	if(m == 0)
		return 0;

	int n = obstacleGrid[0].size();

	if(n == 0)
		return 0;

	vector<vector<int>> dp(m, vector<int>(n, 0));

	if(obstacleGrid[0][0] == 1)
		dp[0][0] = 0;
	else
		dp[0][0] = 1;

	for(int i = 1; i < m; i++){
		if(dp[i - 1][0] == 1 && obstacleGrid[i][0] == 0){
			dp[i][0] = 1;
		}else{
			dp[i][0] = 0;
		}
	}

	for(int j = 1; j < n; j++){
		if(dp[0][j - 1] == 1 && obstacleGrid[0][j] == 0){
			dp[0][j] = 1;
		}else{
			dp[0][j] = 0;
		}
	}

	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			if(obstacleGrid[i][j] == 1)
				dp[i][j] = 0;
			else{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; 
			}
		}
	}
 
	return dp[m - 1][n - 1];
}

int mainuniquePaths2()
{
	uniquePaths1(2, 1);
	return 0;
}