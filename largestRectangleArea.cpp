#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


int largestRectangleArea(vector<int> &height) {
	int len = height.size();
	
	if(len <= 0){
		return 0;
	}

	int **a = new int*[len];
	for(int i = 0; i < len; i++){
		a[i] = new int[len];
	}

	int max = 0;
	for(int i = 0; i < len; i++){
		a[i][i] = height[i];
		if(a[i][i] > max){
			max = a[i][i];
		}
	}

	for(int i = 0; i < len - 1; i++){
		for(int j = i + 1; j < len; j++){
			int h = a[i][j - 1] / (j - 1 - i + 1);
			if(h >= a[j][j])
				a[i][j] = a[j][j] * (j - i + 1);
			else
				a[i][j] = h * (j - i + 1);
			if(a[i][j] > max){
				max = a[i][j];
			}
		}
	}

	return max;
    
}


int largestRectangleArea2(vector<int> &height) {
	int len = height.size();
	
	if(len <= 0){
		return 0;
	}

	int* a = new int[len];

	int max = 0;


	for(int i = 0; i < len; i++){
		for(int j = i; j < len; j++){
			if(i == j){
				a[i] = height[i];
				if(a[i] > max)
					max = a[i];
				continue;
			}

			int h = a[j - 1] / (j - 1 - i + 1);

			if(h >= height[j]){
				a[j] = height[j] * (j - i + 1);
			}else{
				a[j] = h * (j - i + 1);
			}
			if(a[j] > max){
				max = a[j];
			}
		}
	}

	return max;
}

//08/06/2013
int largestRectangleArea3(vector<int> &height) {
      stack<int> s;  
	  height.push_back(0);

	  int i = 0;

	  int area = 0;
	  while(i < height.size()){
		  if(s.empty() || height[i] >= height[s.top()])
			  s.push(i++);
		  else{
			  while(!s.empty() && height[s.top()] >= height[i]){
				  int ht = height[s.top()];
				  s.pop();
				  area = max(area, ht*(s.empty()? i : (i - s.top() - 1)));
			  }
		  }

	  }
	  return area;
}


void mainlargestRectangleArea3(){

	int a[] ={2, 1, 1};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	largestRectangleArea3(vec);
}