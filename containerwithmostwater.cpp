#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int> &height) {
	int len = height.size();
	int i = 0, j = len - 1;
	int maxm = 0;
	while(i < j)
	{
		int tm = (j - i) * ((height[i] < height[j])? height[i] : height[j] );
		if(tm > maxm)
		{
			maxm = tm;
		}
		if(height[i] > height[j])
		{
			j--;
		}else{
			i++;
		}
	}
	return maxm;
}






int maxArea1(vector<int> &height) {
	int len = height.size();

	if(len <= 2)
		return 0;

	int left = 0, right = len - 1;

	int max = 0;
	while(left < right){
		int minbar = min(height[left], height[right]);

		int temp = minbar * (right - left - 1);

		if(height[left] > height[right])
			right--;
		else
			left++;

	}

	return max;
    
}

int mainmaxArea1()
{

	system("pause");
	return 0;
}