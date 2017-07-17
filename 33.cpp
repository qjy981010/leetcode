#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int size = nums.size(), i;
		if (!size) return -1;;
		int begin = 0, end = size - 1, mid;
		if (nums[end] == target) return end;
		for (; end - begin > 1;) {
			mid = (begin + end) >> 1;
			if (nums[mid] < nums[begin]) {
				end = mid;
			}
			else {
				begin = mid;
			}
		}

		int start = end, gap;//the position of the pivot
		++begin;
		--end;

		for (;;) {
			gap = end > begin ? end - begin : size + end - begin;
			if (gap < 2) break;
			mid = begin + (gap >> 1);
			if (mid >= size) mid = mid - size;
			if (nums[mid] > target) {
				end = mid;
			}
			else if (nums[mid] < target) {
				begin = mid;
			}
			else return mid;
		}
		if (nums[end] == target) return end;
		else if (nums[begin] == target)return begin;
		else return -1;
	}
};

int main() {
	Solution solve;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	cout << solve.search(nums, 5) << endl;
}
 
