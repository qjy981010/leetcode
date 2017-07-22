// 感觉比较考验逻辑性的一道题，开始以为是动态规划，感觉很乱
// 但是仔细想想就能发现一些规律，可以简化问题，然后写着写着就变成堆了
// 感觉自己对堆的使用更熟练了，用堆简单的时候能马上想到它

/*note: 贪心*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
	static bool mycomp(const vector<int>& a, const vector<int>& b) {
		return a[1] < b[1];
	}

	int scheduleCourse(vector<vector<int>>& courses) {
		int size = courses.size();
		if (size < 2) return size;

		sort(courses.begin(), courses.end(), mycomp);

		priority_queue<int> maxheap;
		maxheap.push(courses[0][0]);
		int i = 1, max = 1, time_taken = courses[0][0];
		for (; i < size; ++i) {
			if (courses[i][1] - courses[i][0] >= time_taken) {
				time_taken += courses[i][0];
				maxheap.push(courses[i][0]);
				++max;
			}
			else {
				if (courses[i][0] < maxheap.top()) {
					time_taken -= maxheap.top() - courses[i][0]; 
					maxheap.pop();
					maxheap.push(courses[i][0]);
				}
			}
		}
		return max;
	}
};

int main(int argc, char const *argv[])
{
	Solution solve;
	vector<vector<int>> courses = {{7,17},{3,12},{10,20},{9,10},{5,20},{10,19},{4,18}};
	cout << solve.scheduleCourse(courses) << endl;
	return 0;
}
