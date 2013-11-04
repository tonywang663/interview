#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;


void resip(string s, int pos, vector<string>& res, vector<string>& resvec){
	
	int len = s.length();

	int vsize = res.size();

	if(pos == len && res.size() == 4){
	
		string str = res[0] + "." + res[1] + "." + res[2] + "." + res[3];
		resvec.push_back(str);
		return;
	}

	if(pos < len && res.size() == 4){
		return;
	}

	if(pos == len && res.size() < 4){
		return;
	}

	int reslen = len - pos;
	int bound = min(reslen, 3);

	if(s[pos] == '0')
		bound = 1;

	for(int i = 1; i <= bound; i++){
		string str = s.substr(pos, i);
		int num = atoi(str.c_str());
		if(num <= 255){
			vector<string> newres = res;
			newres.push_back(str);
			resip(s, pos + i, newres, resvec);
		}
	}
}


vector<string> restoreIpAddresses(string s) {
	vector<string> resvec;

	if(s.empty())
		return resvec;

	vector<string> res;
	resip(s, 0, res, resvec);

	return resvec;
    
}


static void helper(string& s, vector<string>& ip, int index, vector<string>& res){
	if(index >= s.size() && ip.size() == 4){
		string tmp = ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3];
		res.push_back(tmp);
		return;
	}

	if(ip.size() == 4)
		return;

	int t = 0;
	string str;

	for(int i = index; i <= index + 2; i++){
		if(i >= s.size())
			break;

		str.push_back(s[i]);
		t = t * 10 + s[i] - '0';

		if(i == index + 1 && t < 10)
			continue;

		if(i == index + 2 && t < 100)
			continue;

		if(t>= 0 && t <= 255){
			ip.push_back(str);
			helper(s, ip, i + 1, res);
			ip.pop_back();
		}

	}
}

//08/08/2013
vector<string> restoreIpAddresses1(string s) {
	vector<string> res;

	if(s.empty())
		return res;

	vector<string> ip;
	helper(s, ip,  0, res);
    return res;

}

void mainrestoreIpAddresses(){
restoreIpAddresses("0000");
}