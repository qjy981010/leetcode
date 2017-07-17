#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int size = nums.size();
		if (size < 2) return 0;
		else if (size == 2) return nums[1] > nums[0] ? nums[1]-nums[0] : nums[0]-nums[1];
		unordered_set<int> myset;
		int std, i = 0;

		if (nums[0] > nums[size>>1]) {
			if (nums[0] < nums[size-1]) std = 0;
			else std = nums[size>>1] > nums[size-1] ? size>>1 : size-1;
		}
		else {
			if (nums[0] > nums[size-1]) std = 0;
			else std = nums[size>>1] > nums[size-1] ? size-1 : size>>1;
		}
		
		for (; i < size; ++i) {
			myset.insert(nums[i] - nums[std]);
		}
		if ((size = myset.size() - 1) == 0) return 0;
		myset.erase(0);

		int max = 1, lastgreater = 0, lastless = 0;
		for (i = 1; size > 0; ++i) {
			if (myset.find(i) != myset.end()) {
				--size;
				if (max < i - lastgreater) max = i - lastgreater;
				lastgreater = i;
				myset.erase(i);
			}
			if (myset.find(-i) != myset.end()) {
				--size;
				if (max < lastless + i) max = i + lastless;
				lastless = -i;
				myset.erase(-i);
			}
		}
		return max;
	}
};

int main() {
	Solution solve;
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(5);
	cout << solve.maximumGap(nums) << endl;
}

