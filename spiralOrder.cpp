#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void resspiral(vector<vector<int> > &matrix, int layer, vector<int>& resvec)
{
	int m = matrix.size();
	int n = matrix[0].size();

	int rm = m - 2 * layer;
	int rn = n - 2 * layer;

	if(rm <= 0 || rn <= 0){
		return;
	}

	if(rm == 1){
		for(int i = 0; i <= rn - 1; i++){
			resvec.push_back(matrix[layer][layer + i]);
		}
		return;
	}

	if(rn == 1){
		for(int i = 0; i <= rm - 1; i++){
			resvec.push_back(matrix[layer + i][layer]);
		}
		return;
	}

	for(int j = layer; j < n - 1 - layer; j++){
		resvec.push_back(matrix[layer][j]);
	}

	for(int j = layer; j < m - 1 - layer; j++){
		resvec.push_back(matrix[j][n - 1 - layer]);
	}

	for(int j = n - 1 - layer; j > layer; j--){
		resvec.push_back(matrix[m - 1 - layer][j]);
	}

	for(int j = m - 1 - layer; j > layer; j--){
		resvec.push_back(matrix[j][layer]);
	}

	 resspiral(matrix, layer + 1, resvec);

}


vector<int> spiralOrder(vector<vector<int> > &matrix) {
	int m = matrix.size();
	vector<int> resvec;
	
	if(m == 0){
		return resvec;
	}

	resspiral(matrix, 0, resvec);

	return resvec;
    
}
/*
static void helper(int layer, vector<vector<int> > &matrix, vector<int>& res){
	int m = matrix.size();
	int n = matrix[0].size();

	int lrow = m - 2 * layer;
	int lcol = n - 2 * layer;

	if(lrow == 0 || lcol == 0)
		return;

	if(lrow == 1){
		for(int i = layer; i <= n - 1 - layer; i++){
			res.push_back(matrix[layer][i]);
		}
		return;
	}

	if(lcol == 1){
		for(int i = layer; i <= m - 1 - layer; i++){
			res.push_back(matrix[i][layer]);
		}
		return;
	}

	
}
*/
vector<int> spiralOrder1(vector<vector<int> > &matrix) {
	vector<int> res;

	int m =matrix.size();
	if(m == 0)
		return res;

	int n = matrix[0].size();

	int num = 0;
	int dir = 1;//1. right, 2, bot, 3, right, 4. top 
	int i = 0, j = 0, layer = 0;
	while(num < m * n){
		switch(dir){
			case 1:
				res.push_back(matrix[i][j]);
				num++;
				if(j < n - 1 - layer){					
					j++;
				}else{
					dir = 2;
					i++;
				}
				break;

			case 2:
				res.push_back(matrix[i][j]);
				num++;
				if(i < m - 1 - layer){				
					i++;
					
				}else{
					dir = 3;
					j--;
				}
				break;
			
			case 3:
				res.push_back(matrix[i][j]);
				num++;
				if(j > layer){			
					j--;
					
				}else{
					dir = 4;
					i--;
				}
				break;

			case 4:
				res.push_back(matrix[i][j]);
				num++;
				if(i > layer + 1){
					i--;
				}else{
					dir = 1;
					j++;
					layer++;
				}
				break;
		}
	}
    return res;
}

int mainspiralOrder()
{
	int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int a2[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	vector<int> vec1(a1, a1 + sizeof(a1) / sizeof(int));
	vector<int> vec2(a2, a2 + sizeof(a2) / sizeof(int));
	vector<vector<int>> vvec;
	vvec.push_back(vec1);
	vvec.push_back(vec2);
	spiralOrder(vvec);

	system("pause");
	return 0;
}