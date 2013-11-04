#include <iostream>
#include <cmath>

using namespace std;

bool isPalindrome(int x) {
  if(x < 0)
  {
	x = -x;
  }

  int num = 0;
  int t = x;
  while(t > 0)
  {
	t = t / 10;
	num++;
  }
  
  int t1 = x;
  for(int i = 1; i <= ceil((float)num / 2); i++)
  {
	int t2 = t1 % (int)(pow(10, double(i))) / (int)(pow(10, double(i-1)));
	int t3 = t1 /( pow(10, double(num - i)));
	if (t2 != t3)
	{
		return false;
	}
	t1 = t1 - t2 - t3 * pow(10, double(num - i));

  }
  return true;
}

bool isPalindrome1(int x) {
	if(x < 0)
		return false;

	int len = 0;

	while((x / pow(10, (double)len)) >= 1){
		len++;
	}

	for(int i = 0; i <= (len - 1) / 2; i++){
		int t1 = x % 10;
		int t2 = x / (pow(10, (double)(len - 1 - 2 * i)));
		if(t1 != t2)
			return false;
		x = x - t1;
		x = x - t2 * pow(10, (double)(len - 1 - 2 * i));
		x = x / 10;
	}
	
	return true;
}

int mainpalindrom()
{
	
	cout<<isPalindrome(-1);
	system("pause");
	return 0;
	
}