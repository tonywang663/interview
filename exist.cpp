#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool ismatched(vector<vector<char> > &board, string word, int x, int y, vector<vector<int>>& marker){
	if(word.empty()){
		return true;
	}

	int m = board.size();
	int n = board[0].size();
	int len = word.length();

	if(x > 0 && marker[x - 1][y] == 0 && board[x - 1][y] == word[0]){
		string newstr = word.substr(1, len - 1);
		vector<vector<int> > newmarker = marker;
		newmarker[x - 1][y] = 1;
		if(ismatched(board, newstr, x - 1, y, newmarker)){
			return true;
		}
	}

	if(y > 0 && marker[x][y - 1] == 0 && board[x][y - 1] == word[0]){
		string newstr = word.substr(1, len - 1);
		vector<vector<int> > newmarker = marker;
		newmarker[x][y - 1] = 1;
		if(ismatched(board, newstr, x, y - 1, newmarker)){
			return true;
		}
	}

	if(x < m - 1 && marker[x + 1][y] == 0 && board[x + 1][y] == word[0]){
		string newstr = word.substr(1, len - 1);
		vector<vector<int> > newmarker = marker;
		newmarker[x + 1][y] = 1;
		if(ismatched(board, newstr, x + 1, y, newmarker)){
			return true;
		}
	}

	if(y < n - 1 && marker[x][y + 1] == 0 && board[x][y + 1] == word[0]){
		string newstr = word.substr(1, len - 1);
		vector<vector<int> > newmarker = marker;
		newmarker[x][y + 1] = 1;
		if(ismatched(board, newstr, x, y + 1, newmarker)){
			return true;
		}
	}

	return false;
}

bool exist(vector<vector<char> > &board, string word) {
	int m = board.size();

	if(m == 0){
		return false;
	}

	int n = board[0].size();

	if(n == 0){
		return false;
	}

	int len = word.length();

	vector<int> t1(n, 0);

	vector<vector<int>> marker(m, t1);

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j] == word[0]){
				vector<vector<int>> newmarker = marker;
				newmarker[i][j] = 1;
				string newstr = word.substr(1, len - 1);
				if(ismatched(board, newstr, i, j, newmarker)){
					return true;
				}
			}
		}
	}
    
	return false;
}

static bool helper(int x, int y, vector<vector<char> > &board,int index, string& word, vector<vector<int> > & used){


	if(board[x][y] != word[index])
		return false;

	index++;
	if(index >= word.size())
		return true;

	int m = board.size();
	int n = board[0].size();

	used[x][y] = 1;
	if(x > 0 && used[x - 1][y] == 0 && helper(x - 1, y, board, index, word, used))
		return true;

	if(x < m - 1 && used[x + 1][y] == 0 && helper(x + 1, y, board, index, word, used))
		return true;

	if(y > 0 && used[x][y - 1] == 0 && helper(x, y - 1, board, index, word, used))
		return true;

	if(y < n - 1 && used[x][y + 1] == 0 && helper(x, y + 1, board, index, word, used))
		return true;
	used[x][y] = 0;    //!!! do not forget this

	return false;
}

//08/06/2013
bool exist1(vector<vector<char> > &board, string word) {
	int m = board.size();
	int n = board[0].size();

	int len = word.length();

	vector<vector<int> > used(m, vector<int>(n, 0));

	if(len <= 0)
		return true;

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(helper(i, j, board, 0, word, used))
				return true;
		}
	}

	return false;
}

void mainexist1(){
	char a1[] = "a";
	vector<char> vec(a1, a1 + sizeof(a1) / sizeof(char));
	vector<vector<char>> b;
	b.push_back(vec);
	exist1(b, "a");

}