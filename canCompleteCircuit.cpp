#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	
	int len = gas.size();

	for(int i = 0; i < len; i++){
		int sum = 0;
		int curgas = i;
		bool iswork = true;
		for(int j = 1; j <= len; j++){
			sum += gas[curgas];
			sum = sum - cost[curgas];

			if(sum < 0){
				iswork = false;
				break;
			}
			
			int nextgas = (i + j) % len;
			curgas = nextgas;
		}
		if(iswork)
			return i;
	}

	return -1;
}


int canCompleteCircuit1(vector<int> &gas, vector<int> &cost) {
	
 int sum = 0;
  int total = 0;
  int j = -1;
  for(int i = 0; i < gas.size() ; ++i){
    sum += gas[i]-cost[i];
    total += gas[i]-cost[i];
    if(sum < 0){
      j=i; sum = 0; 
    }
  }
  return total>=0? j+1 : -1;



}