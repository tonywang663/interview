#include <iostream>
#include <vector>
#include <string>

using namespace std;

void resqueen(int n, int row, vector<int>& curqueens, vector<vector<string>>& resvec)
{
	if(row == n){
		vector<string> vecstr;
		for(int i = 0; i < curqueens.size(); i++){
			int pos = curqueens[i];
			string rowstr(n, '.');
			rowstr[pos] = 'Q';
			vecstr.push_back(rowstr);
		}
		resvec.push_back(vecstr);
		return; 
	}

	for(int ncol = 0; ncol < n; ncol++){
		bool ismatch = true;
		for(int qrow = 0; qrow < row; qrow++){
			int qcol = curqueens[qrow];
			int offset = row - qrow;
			int scol1 = qcol + offset;
			int scol2 = qcol - offset;
			if(ncol == qcol || ncol == scol1 || ncol == scol2){
				ismatch = false;
				break;
			}
		}
		if(ismatch){
			vector<int> newcurqueens = curqueens;
			newcurqueens.push_back(ncol);
			resqueen(n, row + 1, newcurqueens, resvec);
		}
	}

}



vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> resvec;
	
	for(int col = 0; col < n; col++){
		vector<int> curqueens;
		curqueens.push_back(col);
		resqueen(n, 1, curqueens, resvec);
	}

	return resvec;
}








void helper(int n, vector<int>& cur, vector<vector<string>>& res){
	int len = cur.size();
	if(len == n){
		vector<string> vecstr;
		for(int i = 0; i < n; i++){
			string str(n, '.');
			str[cur[i]] = 'Q';
			vecstr.push_back(str);
		}
		res.push_back(vecstr);
	}
	

	int row = len;
	for(int i = 0; i < n; i++){

		bool isvalid = true;
		for(int j = 0; j <= row - 1; j++){
			if(cur[j] == i){
				isvalid = false;
				break;
			}

			if(row - j == i - cur[j]){
				isvalid = false;
				break;
			}

			if(row - j == cur[j] - i){
				isvalid = false;
				break;
			}
		}
		if(isvalid){
			cur.push_back(i);
			helper(n, cur, res);
			cur.pop_back();
		}

	}

}


vector<vector<string> > solveNQueens1(int n) {
	vector<vector<string> > res;
	vector<int> cur;
	helper(n, cur, res);
	return res;
    
}

int mainqueen()
{
	solveNQueens1(2);
	system("pause");
	return 0;
	
}