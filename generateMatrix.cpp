#include <iostream>
#include <vector>

using namespace std;

void resgen(int n, int m, int beginnum, vector<vector<int>>& resvec)
{
	int tn = n - 2 * m;
	
	if(tn == 1){
		resvec[m][m] = beginnum;
		return;
	}

	if(tn == 0){
		return;
	}
	
	//top
	for(int i = 0; i < tn - 1; i++){
		resvec[m][m + i] = beginnum++;
	}

	//right
	for(int i = 0; i < tn - 1; i++){
		resvec[m + i][m + tn - 1] = beginnum++;
	}

	//bot
	for(int i = 0; i < tn - 1; i++){
		resvec[m + tn - 1][m + tn - 1 - i] = beginnum++;
	}

	//left
	for(int i = 0; i < tn - 1; i++){
		resvec[m + tn - 1 - i][m] = beginnum++;
	}

	 resgen(n, m + 1, beginnum, resvec);

}

vector<vector<int> > generateMatrix(int n) {

	vector<vector<int>> resvec;

	for(int i = 0; i < n; i++){
		vector<int> tempvec(n, 0);
		resvec.push_back(tempvec);
	}

	resgen(n, 0, 1, resvec);

	return resvec;

}


vector<vector<int> > generateMatrix1(int n) {
	vector<vector<int>> res;
	
	if(n <= 0)
		return res;

	for(int i = 0; i < n; i++)
		res.push_back(vector<int>(n, 0));

	int i = 0, j = 0, num = 1;

	int layer = 0, dir = 1; //1. right, 2, down, 3. right, 4. up
	while(num <= n * n){
		res[i][j] = num;
		num++;

		switch(dir){
			case 1:
				if(j < n - 1 - layer){
					j++;
				}else{
					i++;
					dir = 2;
				}
				break;

			case 2:
				if(i < n - 1 - layer){
					i++;
				}else{
					j--;
					dir = 3;
				}
				break;

			case 3:
				if(j > layer){
					j--;
				}else{
					i--;
					dir = 4;
				}
				break;

			case 4:
				if(i > layer + 1){
					i--;
				}else{
					j++;
					dir = 1;
					layer++;
				}
				break;
		}
	}
	
	return res;
}

int maingenerateMatrix()
{
	return 0;
}