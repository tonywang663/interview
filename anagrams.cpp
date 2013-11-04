#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> anagrams(vector<string> &strs) {
	vector<string> resvec;
	map<string, vector<int>> smap;
	for(int i = 0; i <= strs.size() - 1; i++){
		string str = strs[i];
		sort(str.begin(), str.end());
		smap[str].push_back(i);
	}
	map<string, vector<int>>::iterator it1 = smap.begin();
	for(; it1 != smap.end(); it1++){
		if(it1->second.size() > 1){
			vector<int> & tempvec = it1->second;

			for(int i = 0; i < tempvec.size(); i++){
				resvec.push_back(strs[tempvec[i]]);
			}
		}
	}

	return resvec;
}

vector<string> anagrams1(vector<string> &strs) {
	vector<string> res;

	int len = strs.size();

	if(len <= 1)
		return res;

	map<string, vector<int>> umap;

	for(int i = 0; i < len; i++){
		string str = strs[i];
		sort(str.begin(), str.end());
		umap[str].push_back(i);
	}

	map<string, vector<int>>::iterator it1 = umap.begin();

	for(; it1 != umap.end(); it1++){
		if(it1->second.size() > 1){
			vector<int> & vec = it1->second;
			for(int i = 0; i < vec.size(); i++){
				res.push_back(strs[vec[i]]);
			}
		}
	}
	return res;

}

int mainanagrams()
{


	system("pause");
	return 0;
}