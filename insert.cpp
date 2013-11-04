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

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	int len = intervals.size();



	int begin = -1, end = len;

	vector<Interval> resvec;
	if(len == 0){
		resvec.push_back(newInterval);
		return resvec;
	}

	if(intervals[0].start > newInterval.end){
		resvec.push_back(newInterval);
		for(int i = 0; i < len; i++){
			resvec.push_back(intervals[i]);
		}
		return resvec;
	}
	
	if(intervals[len - 1].end < newInterval.start){
		for(int i = 0; i < len; i++){
			resvec.push_back(intervals[i]);
		}
		resvec.push_back(newInterval);
		return resvec;
	}

	for(int i = 0; i <= len - 1; i++){
		if(intervals[i].end >= newInterval.start){
			begin = i;
			break;
		}
	}

	for(int i = len - 1; i >= 0; i--){
		if(intervals[i].start <= newInterval.end){
			end = i;
			break;
		}
	}

	for(int i = 0; i <= begin - 1; i++){
		resvec.push_back(intervals[i]);
	}

	int left, right;

	if(intervals[begin].start > newInterval.start){
		left = newInterval.start;
	}else{
		left = intervals[begin].start;
	}

	if(intervals[end].end < newInterval.end){
		right = newInterval.end;
	}else{
		right = intervals[end].end;
	}

	Interval itv1(left, right);

	resvec.push_back(itv1);

	for(int i = end + 1; i <= len - 1; i++){
		resvec.push_back(intervals[i]);
	}

	return resvec;

	
}

static bool myfunc(Interval& a, Interval& b){
	return a.start < b.start;
}


vector<Interval> insert1(vector<Interval> &intervals, Interval newInterval) {
	sort(intervals.begin(), intervals.end(), myfunc);

	vector<Interval> res;

	vector<Interval>::iterator it1 = intervals.begin();

	for(; it1 != intervals.end(); it1++){
		if(it1->start > newInterval.start){
			intervals.insert(it1, newInterval);
			break;
		}
	}

	if (it1==intervals.end()){intervals.insert(it1,newInterval);}

	res.push_back(intervals[0]);

	for(int i = 1; i < intervals.size(); i++){
		if(res.back().end < intervals[i].start){
			res.push_back(intervals[i]);
		}else{
			if(res.back().end < intervals[i].end)
				res.back().end = intervals[i].end;
		}
	}

	return res;
}

int maininsert()
{
	Interval v1(1, 5); 
//		v2(6, 9);
	Interval nv(2, 3);
	vector<Interval> vec;
	vec.push_back(v1);
//	vec.push_back(v2);
	insert(vec, nv);
	return 0;
}