#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int threeSumClosest(vector<int> &num, int target) {
	sort(num.begin(), num.end());	
    int len = num.size();
	if(len < 3)
	{
		return 0;
	}

	
	int best = num[1] + num[2] + num[0] - target;
	best = (best > 0)? best : -best;
	int best3sum =  num[1] + num[2] + num[0];
	for(int i = 0; i <= len - 1; i++)
	{
		int nt = target - num[i];
		int left = 0, right = len - 1;
		if(i == left)
		{
			left++;
		}
		if(i == right)
		{
			right--;
		}
		while(left < right)
		{
			int tnt = num[left] + num[right] - nt;
			int tnt1 = (tnt > 0) ? tnt: -tnt;
			if(tnt1 <= best)
			{
				best = tnt1;
				best3sum = num[i] + num[left] + num[right];
				if(best == 0)
				{
					return best3sum;
				}
			}
			if(tnt < 0)
			{
				left++;
			}
			if(tnt > 0)
			{
				right--;
			}
			if(i == left)
			{
				left++;
			}
			if(i == right)
			{
				right--;
			}
				
			}
	}
	return best3sum;
}


int threeSumClosest1(vector<int> &num, int target) {
	
	sort(num.begin(), num.end());

	int best = num[0] + num[1] + num[2];

	int len = num.size();

	for(int i = 0; i < len; i++){
		int left = 0, right = len - 1;
		if(i == 0)
			left++;
		
		if(i == len - 1)
			right = len - 2;

		int curbest = num[i] + num[left] + num[right];

		while(left < right){
			int t = num[i] + num[left] + num[right];

			if(t - target == 0)
				return t;
			
			if(abs(t - target) > abs(curbest - target))
				break;

			if(abs(t - target) < abs(curbest - target))
				curbest = t;

			if(abs(t - target) < abs(best - target))
				best = t;



			if(t - target < 0){
				left++;
			}

			if(t - target > 0){
				right--;
			}

			if(left == i)
				left++;

			if(right == i)
				right--;
		}


	}
	   
	return best;
}


int mainthreeSumClosest1()
{
	int a1[] = {-1, 0, 1}; 
	vector<int> v1(a1, a1 + sizeof(a1) / sizeof(int) );

	int a2[] = {-1, 0, 1}; 
	vector<int> v2(a2, a2 + sizeof(a2) / sizeof(int) );
	set<vector<int>> s;
	s.insert(v1);
	s.insert(v2);
	cout<<s.size();
//	cout<<threeSumClosest(v, -1);

	system("pause");
	return 0;
}