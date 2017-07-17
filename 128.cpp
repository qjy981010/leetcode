#include<iostream>
#include<unordered_set>

using namespace std;

class Solution {
public:
	unordered_set<int> myset;

	int longestConsecutive(vector<int>& nums) {
		if (!n) return 0;
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			myset.insert(nums[i]);
		}
		int cs, lcs = 1;
		for (int i = 0; i < n; ++i) {
			cs = 1;
			myset.erase(nums[i]);
			int j;
			for (j = 1; ; ++j) {
				if (myset.find(nums[i]+j) != myset.end()) {
					++cs;
					myset.erase(nums[i]+j);
				}
				else break;
			}
			for (j = 1; ; ++j) {
				if (myset.find(nums[i]-j) != myset.end()) {
					++cs;
					myset.erase(nums[i]-j);
				}
				else break;
			}
			if (lcs < cs) lcs = cs;
		}
		return lcs;
	}
};
