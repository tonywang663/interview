#include <vector>

using namespace std;

vector<vector<int> > generate1(int numRows) {
	vector<vector<int>> res;
	
	if(numRows <= 0)
		return res;
	
	vector<int> v(1, 1);
	res.push_back(v);

	if(numRows == 1){
		return res;
	}

	for(int i = 2; i <= numRows; i++){
		vector<int> v(i, 0);
		v[0] = 1;
		v[i - 1] = 1;
		
		for(int j = 1; j <= i - 2; j++){
			int ind1 = j - 1;
			int ind2 = j;
			v[j] = res[i - 2][ind1] + res[i - 2][ind2];
		}

		res.push_back(v);
	}

	return res;
}

void maingenerate(){

}