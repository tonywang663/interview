#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator> 


using namespace std;

int medianAlg(const vector<int>& vec1, const vector<int>& vec2);
int medianAlgrec(const vector<int>& vec1, const vector<int>& vec2, int begin1, int end1);
int main3()
{
/*	int arraylen1 = 0;
	cout<<"input array1's length"<<endl;
	cin>>arraylen1;
	if(arraylen1 <= 0)
	{
		cerr<<"length should be bigger than 0!"<<endl;
		exit(0);
	}
	vector<int> vec1;
	for(int i = 0; i < arraylen1; i++)
	{
		int temp;
		cin>>temp;
		vec1.push_back(temp);
	}

	int arraylen2 = 0;
	cout<<"input array2's length"<<endl;
	cin>>arraylen2;
	if(arraylen2 <= 0)
	{
		cerr<<"length should be bigger than 0!"<<endl;
		exit(0);
	}
	vector<int> vec2;
	for(int i = 0; i < arraylen2; i++)
	{
		int temp;
		cin>>temp;
		vec2.push_back(temp);
	}

*/
	int a[] = {2, 2, 5};
	int b[] = {3, 77, 8, 11, 4};
	vector<int> vec1(a, a + 3);
	vector<int> vec2(b, b + 5);
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	ostream_iterator<int> os(cout, " ");
//	medianAlg(array1, arraylen1, array2, arraylen2);

	cout<<"After sorting"<<endl;
//	copy(vec1.begin(), vec1.end(), os);
	cout<<endl;
	copy(vec2.begin(), vec2.end(), os);
	cout<<endl;

//	cout<<medianAlg(vec1, vec2);
	int temp = medianAlgrec(vec1, vec2, 0, vec1.size() - 1);
	if(temp < 0)
		temp = medianAlgrec(vec2, vec1, 0, vec2.size() - 1);
	cout<<temp;
	system("pause");
	return 0;

}

int medianAlgrec(const vector<int>& vec1, const vector<int>& vec2, int begin1, int end1)
{
	if(begin1 > end1)
		return -1;
	int size1 = vec1.size();
	int size2 = vec2.size();
	int x = (begin1 + end1) / 2;
	int y = (size1 + size2) / 2 - x - 1;
	if(vec1[x] >= vec2[y] && vec1[x] <= vec2[y + 1])
	{
		return vec1[x];
	}else if(vec1[x] < vec2[y])
	{
		begin1 = x + 1;
		return medianAlgrec(vec1, vec2, begin1, end1);
	}else if(vec1[x] > vec2[y + 1])
	{
		end1 = x - 1;
		return medianAlgrec(vec1, vec2, begin1, end1);
	}
}

int medianAlg(const vector<int>& vec1, const vector<int>& vec2)
{
	size_t size1 = vec1.size();
	size_t size2 = vec2.size();
	
	size_t begin1 = 0, end1 = size1 - 1;
	size_t x1, y1;
	while(begin1 <= end1){
		x1 = (begin1 + end1) / 2;
		y1 = (size1 + size2) / 2 - x1 - 1;
		if(begin1 == end1)
		{
			if(vec1[x1] >= vec2[y1] && vec1[x1] <= vec2[y1 + 1])
				return vec1[x1];
			else 
				break;
		}

		if(vec1[x1] >= vec2[y1] && vec1[x1] <= vec2[y1 + 1])
		{
			return vec1[x1];
		}else if(vec1[x1] < vec2[y1])
		{
			begin1 = x1 + 1;
		}else if(vec1[x1] > vec2[y1 + 1])
		{
			end1 = x1 - 1;
		}
	}

	size_t begin2 = 0, end2 = size2 - 1;
	x1 = 0;
	y1 = 0;
	while(begin2 <= end2){
		y1 = (begin2 + end2) / 2;
		x1 = (size1 + size2) / 2 - y1 - 1;
		if(begin2 == end2)
		{
			if(vec2[y1] >= vec1[x1] && vec2[y1] <= vec1[x1 + 1])
				return vec2[y1];
			else 
				break;
		}


		if(vec2[y1] >= vec1[x1] && vec2[y1] <= vec1[x1 + 1])
		{
			return vec2[y1];
		}else if(vec2[y1] < vec1[x1])
		{
			begin2 = y1 + 1;
		}else if(vec2[y1] > vec1[x1 + 1])
		{
			end2 = y1 - 1;
		}
	}
}