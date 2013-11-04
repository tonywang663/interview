#include <iostream>
#include <string>

using namespace std;

void perm(string& in, char* out, int* a, int level, const int maxlevel)
{
	if(level == maxlevel)
	{
		out[maxlevel] = '\0';
		cout<<out<<endl;
		return;
	}
	int *useinthislevel = new int[maxlevel];
	for( int i = 0; i < maxlevel; i++)
	{
		useinthislevel[i] = -1;
	}
	for(int i = 1; i < maxlevel; i++)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if(in[i] == in[j]){
				useinthislevel[i] = j;
				break;
			}
		}
	}

	for(int i = 0; i <  maxlevel; i++)
	{
		if(a[i] > 0)
			continue;
		if(useinthislevel[i] >= 0 && a[useinthislevel[i]] == 0)
			continue;
		a[i] = 1;
		out[level] = in[i];
		perm(in, out, a, level + 1, maxlevel);
		a[i] = 0;
	}
	delete []useinthislevel;
}

void permute(string str)
{
	size_t len = str.size();
	int* a  = new int[len];
	for(int i = 0; i < len; i++)
	{
		a[i] = 0;
	}
	char out[100];
	perm(str, out, a, 0, len);
	delete []a;

}

void permute1(char *str,int start)
{
		int i;
        if(start==strlen(str)-1)
                printf("%s\n",str);
        for(i=start;i<strlen(str);i++){
//			if (strchr(str + start, str[i]) != str + i)
//				continue; // eliminate duplicates
                swap(str[i],str[start]);
                permute1(str,start+1);
                swap(str[i],str[start]);               
        }
}


int main7()
{
	string str;
	char bb[100];
	cin>>bb;
	permute1(bb, 0);
	system("pause");
	return 0;
}