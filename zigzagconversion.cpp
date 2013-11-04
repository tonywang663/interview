#include <iostream>
#include <string>
#include <vector>

using namespace std;


string convert(string& s, int nRows) {
	vector<char>* vec = new vector<char>[nRows];
	int len = s.length();
	
	int oddpos = nRows / 2;
	int irow = 0;
	int icol = 0;
	
	for(int i = 0; i <= len - 1; i++)
	{
		if( (icol - 1) % 2 == 0)
		{
			for(int j = 0; j < nRows; j++)
			{
				if(j == oddpos)
				{
					vec[j].push_back(s[i]);
				}else
				{
					vec[j].push_back(' ');
				}
			}
			icol++;
		}else
		{

			vec[irow].push_back(s[i]);
			irow++;
			if(irow % nRows == 0)
			{
				icol++;
				irow = 0;
			}
		}
	}
	string str = "";
	for(int i = 0; i < nRows; i++)
	{
		for(int j = 0; j < vec[i].size(); j++)
		{
			if(vec[i][j] == ' ')
			{
				continue;
			}else
			{
				str = str + vec[i][j];
			}
		}
	}
	return str;
}


string convert1(string s, int nRows) {
	string res;
	if(s.empty())
		return res;

	if(nRows <= 1)
		return s;

	int len = s.length();

	int elen = len / (nRows - 1) + 1;

	vector<char> e(elen, ' ');
	vector<vector<char>> vec(nRows, e);

	int x = 0, y = 0;

	int drt = 1;
	for(int i = 0; i < len; i++){
		if(drt == 1){
			if(x < nRows - 1){
				vec[x][y] = s[i];
				x++;
			}else{
				vec[x][y] = s[i];
				x--;
				y++;
				if(nRows != 2)
					drt = -1;
				else
					drt = 1;
			}
		}else{
			if(x > 1){
				vec[x][y] = s[i];
				x--;
			}else{
				vec[x][y] = s[i];
				x--;
				y++;
				drt = 1;
			}
		
		}

	}
	

	for(int i = 0; i < nRows; i++){
		for(int j = 0; j < elen; j++){
			if(vec[i][j] != ' '){
				res.push_back(vec[i][j]);
			}
				
		}
	}

	return res;

	
}


int mainconvert1()
{
	string s = "PAYPALISHIRING";
	string str = convert1(s, 2);
//	cout<<str<<endl;
	system("pause");
	return 0;
}