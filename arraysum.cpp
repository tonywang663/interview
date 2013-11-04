#include <iostream>

using namespace std;

void calcsum(int* arr, int num)
{
	int biggest = 0;
	for(int i = 0; i < num; i++)
	{
		if(arr[i] > biggest)
		{
			biggest = arr[i];
		}

	}
	int *hash = new int[biggest + 1];
	for(int i = 0; i < biggest + 1; i++)
	{
		hash[i] = 0;
	}
	for(int i = 0; i < num; i++)
	{
		hash[arr[i]] = 1; 
	}

	for(int i = 0; i < num; i++)
	{
		for(int j = i; j < num; j++)
		{
			if(hash[arr[i] + arr[j]] == 1)
			{
				cout<<arr[i]<<" "<<arr[j]<<endl;
			}
		}
	}
	delete []hash;
}

int main11()
{
	
	cout<<"input number of integers"<<endl;
	int num;
	cin>>num;
	int* arr = new int[num];
	for(int i = 0; i < num; i++)
	{
		cin>>arr[i];
	}

	calcsum(arr, num);

	system("pause");

	delete []arr;
	return 0;
}