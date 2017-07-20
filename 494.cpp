// Target Sum
#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
	int result = 0;
	int size, target;

	int findTargetSumWays(vector<int>& nums, int S) {
		target = S;
		size = nums.size();
		expand(nums, 0, 0);
		return result;
	}

	void expand(vector<int>& nums, int i, int sum) {
		if (i == size) {
			if (sum == target) {
				++result;
			}
			return;
		}
		expand(nums, i + 1, sum + nums[i]);
		expand(nums, i + 1, sum - nums[i]);
	}
};

class Solution {
public:
	int result = 0;
	int size, target;

	int findTargetSumWays(vector<int>& nums, int S) {
		
	}

	void expand(vector<int>& nums, int i, int sum) {
	}
};

int main() {
	Solution solve;
	vector<int> nums = {4,4,4,4,4};
	cout << solve.findTargetSumWays(nums, 12) << endl;
}
