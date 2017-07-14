/*可以先确定一个值然后用2sum的方法求解，
循环确定第一个值，向后遍历定位第三个值，然后根据情况将第二个与第三个向中间靠拢*/
class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), less<int>());
        int n = nums.size(), minus_i, minus_i_j, i, j, k; // i为第一个，j为第二个，k为第三个；
        vector< vector<int> > result;
        vector<int> oneanswer(3);
        for (i = 0; ; ++i) {
            while (i && nums[i]==nums[i-1] && i < n-2) ++i; // 需要避免重复
            if (i > n-3) break;
            minus_i = ~nums[i]+1;
            j = i + 1;
            k = n - 1;
            minus_i_j = minus_i - nums[j];
            while (nums[k] > minus_i_j && k > j) --k; // 定位第三个
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
                    while (nums[j]==nums[j-1] && j < k) ++j; // 需要避免重复，同时向中间靠拢
                    --k;
                    while (nums[k]==nums[k+1] && k > j) --k; // 需要避免重复            
                }
                else {
                    j++;
                }
            }
        }
        return result;
    }
};

// 本来只能到50%，改为将k从后往前定位后达到92%，下面这个网址有Ksum的总结
// https://www.sigmainfy.com/blog/summary-of-ksum-problems.html
// 2sum用哈希表复杂度会变为线性，感觉用set去重效率应该不会很高
