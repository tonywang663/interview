#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

void sortitv(vector<Interval> &intervals)
{
	int len = intervals.size();

	for(int i = 0; i <= len - 2; i++){
		for(int k = 0; k <= len - 2 - i; k++){
			if(intervals[k].start > intervals[k + 1].start ||  (intervals[k].start == intervals[k + 1].start && intervals[k].end > intervals[k + 1].end) ){
				Interval temp = intervals[k];
				intervals[k] = intervals[k + 1];
				intervals[k + 1] = temp;
			}
		}
	}


}

 static bool myfunc(const Interval &a, const Interval &b){
        return (a.start < b.start);
    }
    
vector<Interval> merge(vector<Interval> &intervals) {
   int len = intervals.size();
	vector<Interval> resvec;

	std::sort(intervals.begin(),intervals.end(), myfunc);

	int i = 0;
	
	while(i <= len - 1){
		int j = i + 1;

		int begin = intervals[i].start;
		int end = intervals[i].end;
		for(; j <= len - 1; j++){
			if(intervals[j].start > end){
				break;
			}else{
				if(intervals[j].start < begin){
					begin = intervals[j].start;
				}
				if(intervals[j].end > end){
					end = intervals[j].end;
				}
			}
		}

		Interval newitv(begin, end);
		resvec.push_back(newitv);
		i = j;


	}

	return resvec;
}

int mainmerge()
{
	Interval v1(2, 3), v2(4, 5), v3(6, 7), v4(8, 9), v5(1, 10);
	vector<Interval> vec;
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	vec.push_back(v4);
	vec.push_back(v5);
	merge(vec);
	return 0;

}