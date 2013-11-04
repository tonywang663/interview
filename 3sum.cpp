#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num) {
	int len = num.size();

	vector<vector<int>> res;

	if (len < 3)
		return res;

	set<vector<int>> resset;

	sort(num.begin(), num.end());

	for (int i = 1; i < len - 1; i++){
		int left = 0, right = len - 1;


		while (left < i && i < right){
			if (num[left] + num[right] == -num[i]){
				vector<int> t;
				t.push_back(num[left]);
				t.push_back(num[i]);
				t.push_back(num[right]);
				sort(t.begin(), t.end());
				resset.insert(t);
				left++;

				right--;

			}
			else if (num[left] + num[right] < -num[i]){
				left++;

			}
			else if (num[left] + num[right] > -num[i]){
				right--;

			}
		}


	}
	res.resize(resset.size());
	copy(resset.begin(), resset.end(), res.begin());
	return res;
}

//currently best 11/1/2013
vector<vector<int> > threeSum1(vector<int> &num) {
	int len = num.size();

	vector<vector<int>> res;

	if (len < 3)
		return res;

	set<vector<int>> resset;

	sort(num.begin(), num.end());

	for (int i = 0; i <= len - 3; i++){
		if (i > 0 && num[i] == num[i - 1])
			continue;

		int mid = i + 1, right = len - 1;

		while (mid < right){
			if (mid > i + 1 && num[mid] == num[mid - 1]){
				mid++;
				continue;
			}
			if (right < len - 1 && num[right] == num[right + 1]){
				right--;
				continue;
			}
			if (num[i] + num[right] + num[mid] == 0){
				vector<int> t = { num[i], num[mid], num[right] };
				res.push_back(t);
				mid++;
				right--;
			}
			else if (num[i] + num[right] + num[mid] < 0){
				mid++;
			}
			else {
				right--;
			}
		}
	}
	return res;
}

//can be solved using hash table
vector<vector<int> > threeSum2(vector<int> &num) {
	vector<vector<int>> res;
	set<vector<int>> resset;
	int len = num.size();

	if (len <= 2)
		return res;

	unordered_map < int, vector < vector<int >> > umap;


	for (int i = 0; i < len - 1; i++){
		for (int j = i + 1; j < len; j++){
			vector<int> temp = { i, j };
			int key = num[i] + num[j];
			umap[key].push_back(temp);
		}
	}

	for (int i = 0; i < len; i++){
		int key = -num[i];
		if (umap.find(key) != umap.end()){
			vector<vector<int>>& vec = umap[key];
			for (int j = 0; j < vec.size(); j++){
				if (i > vec[j][1]){
					vector<int> resvec = { num[i], num[vec[j][0]], num[vec[j][1]] };
					sort(resvec.begin(), resvec.end());
					resset.insert(resvec);
				}
			}
		}
	}
	copy(resset.begin(), resset.end(), back_inserter(res));
	return res;
}


vector<vector<int> > threeSum4(vector<int> &num) {
	vector<vector<int>> res;
	set<vector<int>> resset;
	int len = num.size();

	if (len <= 2)
		return res;

	unordered_map < int, int>umap;

	for (int i = 0; i < len; i++)
		umap[num[i]] = i;

	for (int i = 0; i < len - 1; i++){
		for (int j = i + 1; j < len; j++){
			int key = -(num[i] + num[j]);
			if (umap.find(key) != umap.end() && umap[key] > j){
				vector<int> temp = { num[i], num[j], num[umap[key]] };
				sort(temp.begin(), temp.end());
				resset.insert(temp);
			}
		}
	}

	copy(resset.begin(), resset.end(), back_inserter(res));
	return res;
}


int mainthreeSum4()
{
	int a[] = {0, 0, 0};
	vector<int> b(a, a + sizeof(a) / sizeof(int));
	 threeSum4(b); 
	system("pause");
	return 0;
}