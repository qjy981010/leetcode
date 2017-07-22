#include <iostream>
#include <vector>

/*note: dp记忆功能的灵活运用，见SolutionPerfect*/

using namespace std;

class SolutionPerfect { // 动态规划，维护一个索引为子序列长度，值为此长度最后一个字符的数组，根据此数组递增使用二分法查找
public:
    int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if (!n) return 0;
		int lis[n];
		int lastnum[n];
		int max = 1;
		for (int i = 0; i < n; ++i) {
			lis[i] = 1;
			lastnum[i] = nums[i];
			for (int j = 0; j < i; ++j) {
				if (nums[i] > lastnum[j]) {
					if (lis[i] < lis[j]+1) {
						lis[i] = lis[j]+1;
					}
				}
			}
			if (max < lis[i]) max = lis[i];
		}
		return max;
    }
};

class Solution { // 普通dp
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if (!n) return 0;
		int lastnum[n];
		lastnum[0] = nums[0];
		int max = 1;
		for (int i = 1; i < n; ++i) {
			int begin = 0, end = max-1;
			while (end - begin > 1) {
				if (lastnum[(begin+end)>>1] > nums[i]) end = (begin + end) >> 1;
				else if (lastnum[(begin+end)>>1] < nums[i]) begin = (begin + end) >> 1;
				else goto jumpout_continue;
			}
			if (lastnum[begin] > nums[i]) lastnum[begin] = nums[i];
			else if (lastnum[end] < nums[i]) lastnum[max++] = nums[i];
			else if (lastnum[end] > nums[i] && lastnum[begin] < nums[i]) lastnum[end] = nums[i];
			jumpout_continue:;
		}
		return max;
	}
};

int main() {
	Solution solve;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(9);
	nums.push_back(4);
	nums.push_back(10);
	nums.push_back(5);
	nums.push_back(6);
	cout << solve.lengthOfLIS(nums) << endl;
}

