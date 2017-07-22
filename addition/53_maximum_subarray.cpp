// 算法导论的一道课后题，简单的dp

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int size = nums.size(), i = 1, max = nums[0], sum = nums[0];
		for (; i < size; ++i) {
			if (sum > 0) sum += nums[i];
			else sum = nums[i];
			if (max < sum) max = sum;
		}
		return max;
	}
};
