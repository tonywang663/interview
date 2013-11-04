#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int maxProfit(vector<int> &prices) {
	int max = 0;
	int len = prices.size();

	for(int i = 0; i < len - 1; i++){
		for(int j = i + 1; j < prices.size(); j++){
			if(prices[j] - prices[i] > max)
				max = prices[j] - prices[i];
		}
	}

	return max;
}

int maxProfit1(vector<int> &prices) {
	if(prices.empty())
		return 0;
	
	int max = 0, amin = prices[0];

	for(int i = 1; i < prices.size(); i++){
		if(prices[i] < amin)
			amin = prices[i];
		else if(prices[i] - amin > max)
			max = prices[i] - amin;
	}

	return max;
}


int maxProfit2(vector<int> &prices) {
	if(prices.empty())
		return 0;

	int left = 0, right = 1;

	int len = prices.size();
	int res = 0;
	while(left <= len - 1 && right <= len - 1){
		while(right < len - 1 && prices[right] < prices[left]){
			left = right;
			right++;
		}

		if( prices[right] < prices[left]){
			break;
		}

		res += prices[right] - prices[left];
		left = right;
		right = left + 1;
	}

	return res;
}

int maxProfit3(vector<int> &prices) {
	if(prices.empty())
		return 0;

	int len = prices.size();

	int max = 0;

	for(int i = 0; i <= len - 1; i++){
		int max1 = 0, max2 = 0;
		int ll = 0, lr = 1;
		int j = 0;
		while(j <= i && lr <= i){
			if(ll < lr){
				int t = prices[lr] - prices[ll];
				if(t > max1)
					max1 = t;
			}
			j++;
			if(prices[j] > prices[lr]){
				lr = j;
			}

			if(prices[j] < prices[ll]){
				ll = j;
			}
		}

		int rl = i + 1, rr = i + 2;
		j = i + 1;
		while(j <= len - 1 && rr <= len - 1){
			if(rl < rr){
				int t = prices[rr] - prices[rl];
				if(t > max2)
					max2 = t;
			}
			j++;
			if(prices[j] > prices[rr]){
				rr = j;
			}

			if(prices[j] < prices[rl]){
				rl = j;
			}
		}

		
		if(max < max1 + max2)
			max = max1 + max2;
	}

	return max;   
}

//08/12/2013
int maxProfit11(vector<int> &prices) {
	int len = prices.size();

	if(len < 2)
		return 0;

	int  minval = prices[0];

	int maxpro = 0;

	for(int i = 1; i < prices.size(); i++){
		if(prices[i] - minval > maxpro)
			maxpro = prices[i] - minval;
		
		if(prices[i] < minval)
			minval = prices[i];
	}
	return maxpro;
}

int maxProfit21(vector<int> &prices) {
	int len = prices.size();

	if(len < 2)
		return 0;
	
	int profit = 0;
	int left = 0, right = 1;

	while(right < len){
		if(prices[right] > prices[left]){
			profit += prices[right] - prices[left];
		}
		left++;
		right++;
	}
    return profit;
}

//08/13/2013
int maxProfit31(vector<int> &prices) {
	int len = prices.size();

	if(len <= 1)
		return 0;

	int maxpro = 0;

	vector<int> dp1(len, 0);
	vector<int> dp2(len, 0);

	int min = prices[0], maxdp1 = 0;
	for(int i = 1; i < len; i++){
		if(prices[i] < min)
			min = prices[i];

		if(prices[i] - min > maxdp1){
			dp1[i] = prices[i] - min;
			maxdp1 = dp1[i];
		}else{
			dp1[i] = dp1[i - 1];
		}
	}

	int max = prices[len - 1], maxdp2 = 0;
	for(int i = len - 2; i >= 0; i--){
		if(prices[i] > max)
			max = prices[i];

		if(max - prices[i] > maxdp2){
			dp2[i] = max - prices[i];
			maxdp2 = dp2[i];
		}else{
			dp2[i] = dp2[i + 1];
		}
	}

	for(int i = 0; i <=  len - 2; i++){
		if(dp1[i] + dp2[i + 1] > maxpro)
			maxpro = dp1[i] + dp2[i + 1];
	}

	if(maxpro > dp1[len - 1])
		return maxpro;

	return dp1[len - 1];
}

void mainmaxProfit31(){
	int a[] = {1,7,4, 2, 11};
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	maxProfit31(v);

}