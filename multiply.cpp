#include <iostream>
#include <string>
#include <vector>

using namespace std;

string multiply(string num1, string num2) {
	int len1 = num1.length();
	int len2 = num2.length();
	
	string res = "";
	for(int i = len1 - 1; i >= 0; i--){
		int a = num1[i] - '0';
		int extra = 0;
		int tempsum = 0;
		for(int j = len2 - 2; j >=0; j--){
			
			int b = num2[j] - '0';
			int temp = a * b;
			

		}
	}

    
}

int main()
{
	system("pause");
	return 0;
}