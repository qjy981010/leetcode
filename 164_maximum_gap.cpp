// Maximum Gap
// 排序后再找最大间隔，不符合线性时间复杂度。可以使用桶排序达到线性时间复杂度，最大间隔在桶之间

/*note：桶排序*/

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int size = nums.size(), maxgap = 0;
		for (int i = 1; i < size; ++i) {
			if (maxgap < nums[i] - nums[i-1]) maxgap = nums[i] - nums[i-1];
		}
		return maxgap;
	}
};

class Solutionbad {
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
	vector<int> nums = {-1, 2, 4, 5};
	cout << solve.maximumGap(nums) << endl;
}

