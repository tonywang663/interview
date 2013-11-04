#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<int> findSubstring1(string S, vector<string> &L) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    
	set<int> ind;


	int esize = L[0].length();
	int slen = S.length();

	for(int i = 0; i <= S.length() - 1; i++){
		
//		string str = S.substr(i, esize);
		
		if(S.compare(i, esize, L[0]) != 0){
			continue;
		}else{

			{
			vector<int> marker(L.size(), 0);
			int lres = i;
			int sum = 1;
			marker[0] = 1;
			int rind = i + esize;
			
			if(sum == L.size()){
				ind.insert(lres);
				continue;
			}
			
			while(rind <= slen - 1){
				bool match = false;
				for(int j = 1; j <= L.size() - 1; j++){
					if(marker[j] == 1){
						continue;
					}
					if(S.compare(rind, esize, L[j]) == 0){
						marker[j] = 1;
						match = true;
						break;
					}
				}

				if(match == false){
					break;
				}else{
					sum++;
					rind += esize;
					if(sum == L.size()){
						ind.insert(lres);
						break;
					}
				}
			}



			int lind = i - esize;
			while(lind >= 0 && sum != L.size()){
				bool match = false;
				for(int j = 1; j <= L.size() - 1; j++){
					if(marker[j] == 1){
						continue;
					}
					if(S.compare(lind, esize, L[j]) == 0){
						marker[j] = 1;
						match = true;
						break;
					}
				}

				if(match == false){
					break;
				}else{
					sum++;
					lres = lind;
					lind -= esize;
					if(sum == L.size()){
						ind.insert(lres);
						break;
					}
				}
			}

			}

			{
			vector<int> marker(L.size(), 0);
			int lres = i;
			int sum = 1;
			marker[0] = 1;
			int lind = i - esize;
			
			if(sum == L.size()){
				ind.insert(lres);
				continue;
			}

						
			while(lind >= 0){
				bool match = false;
				for(int j = 1; j <= L.size() - 1; j++){
					if(marker[j] == 1){
						continue;
					}
					if(S.compare(lind, esize, L[j]) == 0){
						marker[j] = 1;
						match = true;
						break;
					}
				}

				if(match == false){
					break;
				}else{
					sum++;
					lres = lind;
					lind -= esize;
					if(sum == L.size()){
						ind.insert(lres);
						break;
					}
				}
			}

			int rind = i + esize;
			while(rind <= slen - 1 && sum != L.size()){
				bool match = false;
				for(int j = 1; j <= L.size() - 1; j++){
					if(marker[j] == 1){
						continue;
					}
					if(S.compare(rind, esize, L[j]) == 0){
						marker[j] = 1;
						match = true;
						break;
					}
				}

				if(match == false){
					break;
				}else{
					sum++;
					rind += esize;
					if(sum == L.size()){
						ind.insert(lres);
						break;
					}
				}
			}


			}

		}

	}
	vector<int> indvec(ind.begin(), ind.end());
	return indvec;
}


bool recur(string& S, int bindex, vector<string> &L, vector<int>& marker)
{
	
	int lsize = L.size();
	int sum = 0;
	int esize = L[0].length();

	if(bindex > S.length()){
		return false;
	}

	for(int i = 0; i < lsize; i++){
		sum = sum + marker[i];
	}
	
	if(sum == lsize){
		return true;
	}

	for(int i = 0; i < lsize; i++){
		if(marker[i] == 0){
			if(S.compare(bindex, esize, L[i]) == 0){
				vector<int> nmarker = marker;
				nmarker[i] = 1;
				if(recur(S, bindex + esize, L, nmarker) == true){
					return true;
				}
			}

		}
	}
	return false;
}


vector<int> findSubstring2(string S, vector<string> &L) {
	vector<int> ind;
	
	int esize = L[0].length();
	int slen = S.length();
	int lsize = L.size();

	for(int i = 0; i <= S.length() - 1; i++){
		vector<int> marker(lsize, 0);
		if( recur(S, i, L, marker) == true){
			ind.push_back(i);
		}
	}
	return ind;

}






vector<int> findSubstring(string S, vector<string> &L) {

	map<string, int> words;
	vector<int> ind;	
	int esize = L[0].length();
	int slen = S.length();
	int lsize = L.size();

	if(lsize <= 0){
		return ind;
	}

	for(int i = 0; i <= lsize - 1; i++){
		words[L[i]]++;
	}

	map<string, int> curmap;
	for(int i = 0; i <= slen - lsize * esize; i++){
//		string str = S.substr(i, lsize * esize);
		curmap.clear();

		int j = 0;
		for(; j < lsize; j++){
			string s1 = S.substr(i + j * esize, esize);
			if(words.find(s1) == words.end()){
				break;
			}else{
				curmap[s1]++;
			}
			if(words[s1] < curmap[s1]){
				break;
			}
		}
		if(j == lsize){
			ind.push_back(i);
		}

	}

	return ind;
}



vector<int> findSubstring3(string S, vector<string> &L) {
	vector<int> res;

	int len1 = S.length();

	int sizeL = L.size();

	if(sizeL == 0)
		return res;

	int len2 = L[0].length();

	if(len2 == 0)
		return res;

	map<string, int> words;

	for(int i = 0; i < sizeL; i++){
		words[L[i]]++;
	}

	for(int i = 0; i <= len1 - len2 * sizeL; i++){
		int j = 0;
		map<string, int> curmap;
		for(; j <sizeL; j = j++){
			string str = S.substr(i + j * len2, len2);
			if(words.count(str) == 0)
				break;
			curmap[str]++;
			if(curmap[str] > words[str])
				break;
		}
		if(j == sizeL)
			res.push_back(i);
	}

	return res;
}

int mainfindSubstring3()
{
	string s = "abaababbaba";
	string s1 = "ab", s2 = "ba", s3 = "ab", s4 = "ba";
	vector<string> v;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	vector<int> vec = findSubstring(s, v);


	system("pause");
	return 0;
}