#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <iostream>

using namespace std;
typedef map<int, int> Logmap;

int main6()
{
	ifstream infile("log.txt");
	if(!infile){
//		cerr<<"error in open file "<<infile<<endl;
	}
	
	vector<set<int>*> vecvec;

	for(int i = 0; i < 10; i++)
	{
		set<int> *set1 = new set<int>;
		vecvec.push_back(set1);
	}

	string line;
	istringstream input_str("");
	while(getline(infile, line))
	{
		int pos = 0;
		string filter = ",";
		while((pos = line.find_first_of(filter, pos)) != string::npos)
		{
			line.replace(pos, 1, " ");
		}
		input_str.str(line);
		string number, userid;
		input_str>>number;
		input_str>>userid;
		int num, user;
		num = atoi(number.c_str());
		user = atoi(userid.c_str());
		vecvec[num]->insert(user);
		input_str.clear();
	}
	for(int i =0; i < 10; i++)
	{
		if(vecvec[i]->size() > 0)
		{
			cout<<i<<","<<vecvec[i]->size()<<endl;
		}
	}
	system("pause");
	return 0;
}