#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template<typename T>
void babble(vector<T> &vec)
{
	size_t len = vec.size();
	for(size_t i = 0; i < len; i++)
	{
		for(size_t j = 0; j < len -i-1; j++)
		{
			if(vec[j] > vec[j + 1])
			{
				T temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}

	}
}

void swap(vector<int> &vec, size_t p, size_t q)
{
	int t = vec[q];
	vec[q]= vec[p];
	vec[p] = t;
}


void quick(vector<int> &vec, int left, int right)
{
	if(left >= right)
		return;

	int first = vec[left];
// p is the right end index of the array containing elements less than or equal to vec[left]
	int p = left;
	for(int i = left + 1; i <= right; i++)
	{
		if(vec[i] >= first)
		{
			continue;
		}else{
			swap(vec, p + 1, i);
			p = p + 1;
		}
		
	}
// swap left to the end of the smaller array.
	swap(vec, left, p);
	quick(vec, left, p - 1);
	quick(vec, p + 1, right);
}

int mainsort()
{
	ostream_iterator<int> os(cout, " ");
	int n;
	cout<<"Please input the number of array"<<endl;
	cin>>n;
	cout<<"Please input the number in the array"<<endl;
	if(n <= 0)
	{
		cerr<<"n should be bigger than 0"<<endl;
	}
	vector<int> vec;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin>>temp;
		vec.push_back(temp);
	}
	cout<<"Befor sorting"<<endl;
	copy(vec.begin(), vec.end(), os);
	cout<<endl;
//	babble<int>(vec);
	quick(vec, 0, vec.size() - 1);
	cout<<"After sorting"<<endl;
	copy(vec.begin(), vec.end(), os);
	system("pause");
	return 0;
}
