// 二分查找分别找出要插入区间的头和尾应在位置，然后分情况处理

#include <iostream>
#include <vector>

using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution { // 74.62%
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		int size = intervals.size();
		if (!size) {
			intervals.push_back(newInterval);
			return intervals;
		}
		int left = 0, right = size - 1, mid, leftpos, rightpos;
		int start = newInterval.start, end = newInterval.end;
		if (start > intervals[right].end) {
			intervals.push_back(Interval(start, end));
			return intervals;
		}

		while (right - left > 1) { // find the position of start
			mid = (right + left) >> 1;
			if (intervals[mid].start > start) {
				right = mid;
			}
			else {
				left = mid;
			}
		}
		if (start <= intervals[left].end) leftpos = left;
		else leftpos = right;

		if (end < intervals[leftpos+1].start) {// if the end is close to the start, get the result now.
			if (start < intervals[leftpos].start) {
				if (end < intervals[leftpos].start) {
					intervals.insert(intervals.begin() + leftpos, Interval(start, end));
					return intervals;
				}
				else if (end <= intervals[leftpos].end) {
					intervals[leftpos].start = start;
					return intervals;
				}
				else if (leftpos + 1 < size && end < intervals[leftpos+1].start || leftpos + 1 >= size) {
					intervals[leftpos].start = start;
					intervals[leftpos].end = end;
					return intervals;
				}
			}
			else {
				if (end <= intervals[leftpos].end) {
					return intervals;
				}
				else if (leftpos + 1 < size && end < intervals[leftpos+1].start || leftpos + 1 == size) {
					intervals[leftpos].end = end;
					return intervals;
				}
			}
		}

		left = leftpos; right = size - 1;
		while (right - left > 1) { // find the position of end
			mid = (right + left) >> 1;
			if (intervals[mid].end < end) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		if (end >= intervals[right].start) rightpos = right;
		else rightpos = left;

		if (end >= intervals[rightpos].end) {
			if (start < intervals[leftpos].start) intervals[leftpos].start = start;
			intervals.erase(intervals.begin() + leftpos + 1, intervals.begin() + rightpos + 1);
			intervals[leftpos].end = end;
		}
		else {
			if (start < intervals[leftpos].start) intervals[leftpos].start = start;
			end = intervals[rightpos].end;
			intervals.erase(intervals.begin() + leftpos + 1, intervals.begin() + rightpos + 1);
			intervals[leftpos].end = end;
		}
		return intervals;
	}
};

int main() {
	vector<Interval> v;
	v.push_back(Interval(4, 5));
	v.push_back(Interval(6, 8));
	v.push_back(Interval(9, 12));
	Solution solve;
	solve.insert(v, Interval(12,13));
	
	int size = v.size();
	for (int i = 0; i < size; ++i) {
		cout << v[i].start << ' ' << v[i].end << endl;
	}
	return 0;
}

