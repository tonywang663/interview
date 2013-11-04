#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<string> letterCombinations(string digits) {
	vector<string> index(8, "");
	index[0] = "abc";
	index[1] = "def";
	index[2] = "ghi";
	index[3] = "jkl";
	index[4] = "mno";
	index[5] = "pqrs";
	index[6] = "tuv";
	index[7] = "wxyz";

	int len = digits.length();
	vector<string> vec(1, "");
	for(int i = 0; i < len; i++){
		int t = digits[i] - '0';
		if(t < 2 || t > 9)
			continue;
		t -= 2;
		vector<string> temp;
		for(int j = 0; j < index[t].length(); j++){
			for(int k = 0; k < vec.size(); k++){
				string str = vec[k];
				str.push_back(index[t][j]);
				temp.push_back(str);
			}
		}
		vec = temp;
	}

	return vec;
}

int mainletterCombinations()
{

	system("pause");
	return 0;
}