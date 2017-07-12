class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), less<int>());
        int n = nums.size(), minus_i, minus_i_j, i, j, k;
        vector< vector<int> > result;
        vector<int> oneanswer(3);
        for (i = 0; ; ++i) {
            while (i && nums[i]==nums[i-1] && i < n-2) ++i;
            if (i > n-3) break;
            minus_i = ~nums[i]+1;
            j = i + 1;
            k = i + 2;
            minus_i_j = minus_i - nums[j];
            while (nums[k] < minus_i_j && k < n - 1) ++k;
            for (; ; ) {
                if (k <= j) break;
                minus_i_j = minus_i - nums[j];
                if (nums[k] > minus_i_j) {
                    --k;
                }
                else if (nums[k] == minus_i_j) {
                    oneanswer[0] = nums[i];
                    oneanswer[1] = nums[j];
                    oneanswer[2] = nums[k];
                    result.push_back(oneanswer);
                    ++j;
                    while (nums[j]==nums[j-1] && j < k) ++j;
                    --k;
                    while (nums[k]==nums[k+1] && k > j) --k;            
                }
                else {
                    j++;
                }
            }
        }
        return result;
    }
};

// beats 41.58 % of cpp submissions.


/* more simple one

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); ++k) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int target = 0 - nums[k];
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) ++i;
                    while (i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j;
                } else if (nums[i] + nums[j] < target) ++i;
                else --j;
            }
        }
        return res;
    }
};
*/
