// Target Sum
#include <iostream>
#include <vector>

using namespace std;

class Solution1 { // DFS
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

class Solution12 {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = 0, i = 0, size = nums.size();
		for (; i < size; ++i) sum += nums[i];
		if (sum < S || (sum + S) & 1) return 0;
		sum = (sum + S) >> 1;
		int dp[sum + 1] = {1};
		for (i = 0; i < size; ++i) {
			for (int j = sum; j >= nums[i]; --j) {
				dp[j] += dp[j-nums[i]];
			}
		}
		return dp[sum];
	}
};

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = 0, i = 0, size = nums.size();
		for (; i < size; ++i) sum += nums[i];
		if (sum < S || (sum + S) & 1) return 0;
		sum = (sum - S) >> 1;
		int dp[sum + 1] = {1};
		for (i = 0; i < size; ++i) {
			for (int j = sum; j >= nums[i]; --j) {
				dp[j] += dp[j-nums[i]];
			}
		}
		return dp[sum];
	}
};

int main() {
	Solution solve;
	vector<int> nums = {4,4,4,4,4};
	cout << solve.findTargetSumWays(nums, 12) << endl;
}
