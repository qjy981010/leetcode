#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int size = nums.size(), sum = 0, i = 0;
		for (; i < size; ++i) {
			sum += nums[i];
		}
		if (sum & 1) return false;
		sum >>= 1;
		int dp[sum + 1] = {1};
		for (i = 0; i < size; ++i) {
			for (int j = sum; j >= nums[i]; --j) {
				dp[j] += dp[j-nums[i]];
			}
		}
		if (dp[sum]) return true;
		else return false;
	}
};

int main(int argc, char const *argv[])
{
	Solution solve;
	vector<int> nums = {1, 2, 3, 5};
	cout << solve.canPartition(nums) << endl;
	return 0;
}
