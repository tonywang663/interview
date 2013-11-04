#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) {

	int lena = a.length();
	int lenb = b.length();
	if(lena == 0){
		return b;
	}

	if(lenb == 0){
		return a;
	}

	

	string res = "";

	if(lena > lenb){
		b.insert(0, lena - lenb, '0');
	}else{
		a.insert(0, lenb - lena, '0');
	}

	int len = lena > lenb ? lena : lenb;

	int overflow  = 0;
	for(int i = len - 1; i >= 0; i--){
		int t = a[i] + b[i] - '0' - '0' + overflow;
		if(t > 1){
			overflow = 1;
			res.insert(0, 1, t - 2 + '0');
		}else{
			overflow = 0;
			res.insert(0, 1, t + '0');
		}

	}

	if(overflow == 1){
		res.insert(0, 1, '1');
	}

	return res;
    
}

string addBinary1(string a, string b) {
	int len1 = a.length();
	int len2 = b.length();

	int len = len1 > len2? len1 : len2;

	if(len1 > len2){
		b.insert(0, len1 - len2, '0');
	}else{
		a.insert(0, len2 - len1, '0');
	}

	string res("");

	int overflow = 0;

	for(int i = len - 1; i >= 0; i--){
		int t = a[i] - '0' + b[i] - '0' + overflow;

		if(t >= 2)
			overflow = 1;
		else
			overflow = 0;

		t = t % 2;

		res.insert(0, 1, t + '0');
	}

	if(overflow >= 1)
		res.insert(0, 1, '1');

	return res;
    
}

int mainaddBinary(){
	string a("1"), b("111");
	addBinary(a, b);
	return 0;

}