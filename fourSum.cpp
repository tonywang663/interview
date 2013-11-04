#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target) {
	vector<vector<int>> res;

	set<vector<int>> resset;

	int len = num.size();

	if(len < 4)
		return res;

	map<int, vector<vector<int>>> umap;

	for(int i = 0; i < len - 1; i++){
		for(int j = i + 1; j < len; j++){
			int t = num[i] + num[j];
			vector<int> vt;
			vt.push_back(i);
			vt.push_back(j);
			if(umap.count(t) == 0){
				vector<vector<int>> tvv;
				tvv.push_back(vt);
				umap.insert(pair<int, vector<vector<int>>>(t, tvv));
			}else{
				umap[t].push_back(vt);
			}
		}
	}

	map<int, vector<vector<int>>>::iterator it1 = umap.begin();
	for(; it1 != umap.end(); it1++){
		int t = it1->first;
		if(umap.count(target - t) == 0){
			continue;
		}else{
			vector<vector<int>> vec1 = it1->second;
			vector<vector<int>> vec2 = umap[target-t];
			for(int i = 0; i < vec1.size(); i++){
				for(int j = 0; j < vec2.size(); j++){
					set<int> eset;
					eset.insert(vec1[i][0]);
					eset.insert(vec1[i][1]);
					eset.insert(vec2[j][0]);
					eset.insert(vec2[j][1]);
					if(eset.size() < 4)
						continue;
					

					vector<int> evec;
					evec.push_back(num[vec1[i][0]]);
					evec.push_back(num[vec1[i][1]]);
					evec.push_back(num[vec2[j][0]]);
					evec.push_back(num[vec2[j][1]]);
					sort(evec.begin(), evec.end());
					resset.insert(evec);
				}
			}
		}
		
	}

	copy(resset.begin(), resset.end(), back_inserter(res));
	return res;
    
}

void mainfourSum(){
	vector<vector<int>> v(3, vector<int>(5, 0));
	int a[] = {2, 1, 0 -1, 2};

	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	fourSum(vec, 2);

}