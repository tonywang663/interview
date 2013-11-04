#include <iostream>
#include <vector>
#include <stack>

using namespace std;


void change(vector<vector<char>>& board, int x, int y, char s, char t){
	int m = board.size();
	int n = board[0].size();

	if(x >= m || y >= n || x < 0 || y < 0)
		return;

	stack<vector<int>> stk;

	vector<int> root;
	root.push_back(x);
	root.push_back(y);

	stk.push(root);

	while(!stk.empty()){
		vector<int> node = stk.top();
		stk.pop();
		if(board[node[0]][node[1]] == s){
			board[node[0]][node[1]] = t;
			if(node[1] + 1 < n){
				vector<int> vec = node;
				vec[1]++;
				stk.push(vec);
			}
				
			if(node[1] - 1 >=0 ){
				vector<int> vec = node;
				vec[1]--;
				stk.push(vec);
			}

			if(node[0] + 1 < m){
				vector<int> vec = node;
				vec[0]++;
				stk.push(vec);
			}
			
			if(node[0] - 1 >= 0){
				vector<int> vec = node;
				vec[0]--;
				stk.push(vec);
			}
		}
	}


}

void solve(vector<vector<char>> &board) {

	int m = board.size();
	if(m == 0)
		return;

	int n = board[0].size();
    if(n == 0)
		return;

	for(int i = 0; i < m; i++){
		if(board[i][0] == 'O'){
			change(board, i, 0, 'O', 'Z');
		}
	}

	for(int i = 0; i < m; i++){
		if(board[i][n - 1] == 'O'){
			change(board, i, n - 1, 'O', 'Z');
		}
	}


	for(int j = 0; j < n; j++){
		if(board[0][j] == 'O'){
			change(board, 0, j, 'O', 'Z');
		}
	}

	for(int j = 0; j < n; j++){
		if(board[m - 1][j] == 'O'){
			change(board, m - 1, j, 'O', 'Z');
		}
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j] == 'O'){
				board[i][j] = 'X';
			}else if(board[i][j] == 'Z'){
				board[i][j] = 'O';
			}
		}
	}
}

void mainsolve(){

	char a[] = {'O', 'O'};
	char b[] = {'O', 'O'};
	vector<char> v1(a, a + sizeof(a) / sizeof(char));
	vector<char> v2(b, b + sizeof(b) / sizeof(char));

	vector<vector<char>> board;
	board.push_back(v1);
	board.push_back(v2);
	solve(board);

}