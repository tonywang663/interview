#include <iostream>
#include <string>

using namespace std;

string multiply(string num1, string num2) {
	int len1 = num1.length();
	int len2 = num2.length();

	string res = "0";
	for(int i = len1 - 1; i >= 0; i--){
		string tempres = "";
		int a = num1[i] - '0';
		int f = 0;
		for(int j = len2 - 1; j >= 0; j--){
			int b = num2[j] - '0';
			int c = a * b + f;
			f = c / 10;
			int d = c % 10;
			char nd = d + '0';
			tempres.insert(0, 1, nd);
		}
		if(f > 0){
			char nf = f + '0';
			tempres.insert(0, 1, nf);
		}

		for(int j = i; j <= len1 - 2; j++){
			tempres += string("0");
		}

		if(tempres[0] == '0'){
			tempres = "0";
		}



		string tres = res;
		res = "";
		int tlen = tempres.length();
		int rlen = tres.length();

		if(tlen < rlen){
			tempres.insert(0, rlen - tlen, '0');
		}else{
			tres.insert(0, tlen - rlen, '0');
		}
		
		int ntlen = tempres.length();;
		

		int g = 0;
		for(int j = ntlen - 1; j >= 0; j--){
			int b = tempres[j] - '0';
			int c = tres[j] - '0';
			int d = b + c + g;
			g = d / 10;
			int h = d % 10;
			char nh = h + '0';
			res.insert(0, 1, nh);
		}
		if(g > 0){
			res.insert(0, 1, g + '0');
		}
		
	}

	return res;

}

string multiply1(string num1, string num2) {
	int len1 = num1.length();
	int len2 = num2.length();

	if(num1 == "0" || num2 == "0")
		return "0";

	string res = "";
	for(int i = len2 - 1; i >= 0; i--){
		int overflow = 0;
		string unit = "";
		for(int j = len1 - 1; j >= 0; j--){
			int t = (num1[j] - '0') * (num2[i] - '0') + overflow;
			overflow = t / 10;
			t = t % 10;
			unit.insert(0, 1, t + '0');
		}
		if(overflow > 0)
			unit.insert(0, 1,  overflow + '0');

		unit.insert(unit.length(), len2 - 1 - i, '0'); 
		//add
		int lenu = unit.length();
		int lenr = res.length();

		int len = 0;
		if(lenu > lenr){
			len = lenu;
			res.insert(0, lenu - lenr, '0');
		}
		else{
			len = lenr;
			unit.insert(0, lenr - lenu, '0');
		}

		overflow = 0;
		string newres = "";
		for(int k = len - 1; k >= 0; k--){
			int t = res[k] - '0' + unit[k] - '0' + overflow;
			overflow = t / 10;
			t = t % 10;
			newres.insert(0, 1, t + '0');
		}
		if(overflow > 0)
			newres.insert(0, 1, overflow + '0');

		res = newres;
	}

    return res;
}


int mainmultiply1()
{
	string str1("9"), str2("99");
	 multiply1(str1, str2);

	system("pause");
	return 0;
}