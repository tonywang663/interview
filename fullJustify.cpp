#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> fullJustify(vector<string> &words, int L) {
	vector<string> res;

	int len = words.size();

	if(len <= 0){
		return res;
	}

	int index = 0;

	while(index < len){
		int linelen = 0;
		int i = index;
		for(; i <= len - 1; i++){
			linelen += words[i].length();
			if(linelen > L){
				break;
			}
			linelen++;
		}

		i--;
		int wordlen = 0;
		for(int j = index; j <= i; j++){
			wordlen += words[j].length();
		}

		int numword = i - index + 1;
		int spacelen = L - wordlen;
		
		string strline = "";
		
		if(i < len - 1){

			if(numword > 1){
				int ainter = spacelen / (numword - 1);

				int t = spacelen - ainter * (numword - 1);

				if(t == 0){
					int linter = spacelen - ainter * (numword - 2);

					string lstr(linter, ' ');

					


					strline = strline + words[index] + lstr;

					string astr(ainter, ' ');

					for(int j = index + 1; j <= i - 1; j++){
						strline = strline + words[j] + astr;
					}

					strline += words[i];
				}else{
					int linter = ainter  + 1;

					string lstr(linter, ' ');

					string astr(ainter, ' ');

					for(int j = index; j < index + t; j++){
						strline = strline + words[j] + lstr;
					}

					for(int j =  index + t; j <= i - 1; j++){
						strline = strline + words[j] + astr;
					}

					strline += words[i];
				}

			}else{
				int rinter = L - words[index].length();

				string rstr = string(rinter, ' ');
				strline  = words[index] + rstr;
			}
		}else{
			
			int rinter = L - wordlen - numword + 1;

			string rstr(rinter, ' ');
			for(int j = index; j <= i - 1; j++){
				strline = strline + words[j] + " ";
			}

			strline = strline + words[i] +  rstr;
		}

		res.push_back(strline);

		index = i + 1;

	}

	return res;
    
}

int mainfullJustify()
{
	return 0;
}