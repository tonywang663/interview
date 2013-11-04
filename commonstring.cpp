#include <iostream>
#include <string>
#include <vector>
using namespace std;

void common(const char* str1, size_t len1, const char* str2, size_t len2, string & res)
{
	int m = len1;
	int n = len2;
	
	int **c = new int* [m];
	for(int i = 0; i < m; i++)
	{
		c[i] = new int [n];
	}

	for(int i = 0; i < n; i++)
	{
		c[0][i] = str2[i] == str1[0]?1:0; 
	}

	for(int i = 0; i < m; i++)
	{
		c[i][0] = str1[i] == str2[0]?1:0; 
	}

	int imax = -1, jmax = -1, vmax = 0;

	for(int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
		{
			int temp = str1[i]==str2[j] ? 1:0;
			if(temp > 0)
			{
				temp = c[i-1][j-1] + temp;
				c[i][j] = temp;
				if(temp > vmax)
				{
					vmax = temp;
					imax = i;
					jmax = j;
				}
			}else {
				c[i][j] = 0;
			}


		}
	}

	for(int i = 0; i < m; i++){
		for(int j =0; j < n; j++){
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	
	string tempstr(str1 + imax - vmax + 1, vmax);
	res = tempstr;
	delete []c;
}



int main8()
{
	char str1[100], str2[100];
	cin>>str1;
	cin>>str2;

	string res = "";
	common(str1, strlen(str1), str2, strlen(str2), res);
	cout << res <<endl;
	system("pause");
	return 0;
}