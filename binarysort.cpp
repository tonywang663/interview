#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void binarysort(vector<int>& vec)
{
	int i = -1, j = 0;
	int len = vec.size() - 1;
	for(; j <= len; j++)
	{
		if(vec[j] == 1)
		{
			continue;
		}else {
			int temp;
			temp = vec[j];
			vec[j] = vec[++i];
			vec[i] = temp;
		}
	}
}

int main5()
{
	int a[15] = { 0, 1, 1, 0, 0,1, 0,1,0,1,1,1,0, 0, 0};
	vector<int> arr(a, a + 15);
	ostream_iterator<int> os(cout, " ");
	copy(arr.begin(), arr.end(), os);
	cout<<endl;
	binarysort(arr);
	copy(arr.begin(), arr.end(), os);
	cout<<endl;
	system("pause");
	return 0;

}