#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int> > &matrix) {
	int m = matrix.size();
	if(m == 0){
		return;
	}

	int n = matrix[0].size();
	if(n == 0){
		return;
	}

	bool fcol0 = false, frow0 = false;

	for(int i = 0; i < m; i++){
		if(matrix[i][0] == 0){
			fcol0 = true;
			break;
		}
	}

	for(int j = 0; j < n; j++){
		if(matrix[0][j] == 0){
			frow0 = true;
			break;
		}
	}

	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			if(matrix[i][j] == 0){
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for(int i = 1; i < m; i++){
		if(matrix[i][0] == 0){
			for(int j = 1; j < n; j++){
				matrix[i][j] = 0;
			}
		}
	}

	for(int j = 1; j < n; j++){
		if(matrix[0][j] == 0){
			for(int i = 1; i < m; i++){
				matrix[i][j] = 0;
			}
		}
	}

	if(fcol0){
		for(int i = 0; i < m; i++){
			matrix[i][0] = 0;
		}
	}

	if(frow0){
		for(int j = 0; j < n; j++){
			matrix[0][j] = 0;
		}
	}
    
}



//08/05/2013
void setZeroes1(vector<vector<int> > &matrix) {
	int m = matrix.size();
	int n = matrix[0].size();

	bool frow0 = false, fcol0 = false;
	for(int i = 0; i < m; i++){
		if(matrix[i][0] == 0)
			fcol0 = true;
	}

	for(int j = 0; j < n; j++){
		if(matrix[0][j] == 0)
			frow0 = true;
	}

	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			if(matrix[i][j] == 0){
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	for(int i = 1; i < m; i++){
		if(matrix[i][0] == 0){
			for(int j = 1; j < n; j++)
				matrix[i][j] = 0;
		}
	}

	for(int j = 1; j < n; j++){
		if(matrix[0][j] == 0){
			for(int i = 1; i < m; i++)
				matrix[i][j] = 0;
		}
	}

	if(fcol0){
		for(int i = 0; i < m; i++)
			matrix[i][0] = 0;
	}

	if(frow0){
		for(int j = 0; j < n; j++)
			matrix[0][j] = 0;
	}

    
}

void mainsetZeroes()
{

}