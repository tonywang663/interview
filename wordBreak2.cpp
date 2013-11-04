#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;


void wordBreakhelper(string& s, set<string>& dict, string& cur, vector<string>& res){
	int len = s.length();

	if(len == 0){
		int clen = cur.length();
		cur = cur.substr(0, clen - 1);
		res.push_back(cur);
		return;
	}

	for(int i = 1; i <= len; i++){
		string subs = s.substr(0, i);
		if(dict.find(subs) != dict.end()){
			string ns = s.substr(i, len - i);
			string ncur = cur + subs + " ";
			wordBreakhelper(ns, dict, ncur, res);
		}
	}

}

vector<string> wordBreak(string s, set<string> &dict) {
	int len = s.length();

	vector<string> res;
	if(len <= 0)
		return res;

	string cur = "";
	wordBreakhelper(s, dict, cur, res);

	return res;
}

void wordhelper2(vector<vector<int>>& mat, int pos, vector<int>& path, vector<vector<int>>& res){
	int len = mat.size();

	if(pos == len - 1){
		res.push_back(path);
		return;
	}

	for(int i = pos + 1; i < len; i++){
		if(mat[pos][i] == 1){
			path.push_back(i);
			wordhelper2(mat, i, path, res);
			path.pop_back();
		}
	}

}

vector<string> wordBreak2(string s, set<string> &dict) {
	int len = s.length();

	vector<string> resstring;

	if(len == 0)
		return resstring;

	vector<vector<int>> mat(len, vector<int>(len, 0));

	for(int i = 0; i < len; i++){
		set<string>::iterator it = dict.begin();
		for(; it != dict.end(); it++){
			if(s.find( *it, i) == i){
				mat[i][i + it->length() - 1] = 1;
			}
		}
	}

	queue<int> que;
	que.push(0);

	vector<vector<int>> res;
	wordhelper2(mat, 0, vector<int>(), res);


	for(int i = 0; i < res.size(); i++){
		string str = "";
		int start = 0;
		for(int j = 0; j < res[i].size(); j++){
			str += s.substr(start, res[i][j]) + " ";
			start = res[i][j];
		}
		resstring.push_back(str.substr(0, str.length() - 1));
	}

	return resstring;
}

void DFS(string &s, int i, vector<int> &p, vector<vector<int>> &mem, vector<string> &ret) {
	for(int j = 0; j < mem[i].size(); j++) {
			int k = mem[i][j];
			p.push_back(k);
			if(k == 0) {
				string w;
				for(int k=p.size()-1; k>0; k--)
					w.append(s.substr(p[k],p[k-1]-p[k])+' ');
				w.append(s.substr(p[0]));
				ret.push_back(w);
			} else
				DFS(s, k, p, mem, ret);
			p.pop_back();
		}
	}

	vector<string> wordBreak21(string s, set<string> &dict) {
		vector<string> ret;
		vector<vector<int>> mem;
		int n=s.size();
		int maxw = 0;
		set<string>::iterator it1 = dict.begin();

		for(; it1 != dict.end(); it1++){
			maxw = max(maxw, (int)it1->size());
		}

		vector<bool> S(n+1,false);
		mem.resize(n+1);
		S[0] = true;
		for(int i=0; i<n; i++)
			if(S[i])
				for(int j=1; j<=min(maxw,n-i); j++)
					if(dict.find(s.substr(i,j)) != dict.end()) {
						S[i+j] = true;
						mem[i+j].push_back(i);
					}
		vector<int> path;
		DFS(s, n, path, mem, ret);
		return ret;
	}

void mainwordBreak2(){
	string str = "ab";
	set<string> sset;
	sset.insert("a");
	sset.insert("b");
//	wordBreak(str, sset);
	system("pause");
}