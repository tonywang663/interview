#include <iostream>

using namespace std;

void c_imp(char* str, size_t len)
{
	int word[24] = {0};
	char* tempstr = new char[len];
	int temp_index = 0;
	for(int i = 0; i < len; i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			int index = str[i] - 'A';
			if(word[index] == 0)
			{
				word[index] = 1;
				tempstr[temp_index++] = str[i];
			}

		}else if(str[i] >= 'a' && str[i] <= 'z')
		{
			int index = str[i] - 'a';
			if(word[index] == 0)
			{
				word[index] = 1;
				tempstr[temp_index++] = str[i];
			}

		}
	}
	tempstr[temp_index] = '\0';
	strcpy(str, tempstr);
	delete []tempstr;

}

int main4()
{
	
	char str[100];
	cin>>str;
	c_imp(str, strlen(str));
	cout<<str<<endl;
	system("pause");
	return 0;
}
