#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

bool binarysearch(vector<int>& arr, int len, int target)
{
	assert(len >=0);

	int start = 0;
	int end = len - 1;
	int cur = 0;
	while(start >= 0 && end >= 0 && start <= end)
	{
		if(arr[start] > arr[end])
		{
			cerr<<"array not sorted"<<endl;
			exit(0);
		}
		cur = (start + end) / 2;
		if(arr[cur] == target)
		{
			return true;
		}else if(arr[cur] > target)
		{
			end = cur - 1;
		}else 
		{
			start = cur + 1;
		}
	}
	return false;
}

int main12()
{
	cout<<"input number of integers:";
	int num;
	cin>>num;
	vector<int> arr;
	int temp;
	for(int i = 0; i < num; i++)
	{
		cout<<"number 1: ";
		cin>>temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	cout<<"search number: ";
	int target;
	cin>>target;
	cout<<binarysearch(arr, num, target);
	system("pause");
	return 0;
}