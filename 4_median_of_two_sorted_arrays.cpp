/*感觉好复杂的一道题。。。要求log(m+n)时间复杂度，肯定是二分法之类的，然后就写了半天bug，然而时间复杂度并没有严格达到要求
于是看了网上的解答才发现技巧，转化为求第k/2小值，递归直到得到结果，注意边界*/

/*note: 注意问题的转化*/

class Solution {
public:
    int binary_k(std::vector<int>& nums1, size_t flag1, std::vector<int>& nums2, size_t flag2, size_t k)
    {
        if (nums1.size() - flag1 > nums2.size() - flag2)
            return binary_k(nums2, flag2, nums1, flag1, k);
        if (nums1.size() - flag1 == 0)
            return nums2[flag2 + k - 1];
        if (k == 1)
            return std::min(nums1[flag1], nums2[flag2]);

        size_t index_1 = std::min(k/2, nums1.size());
        size_t index_2 = k - index_1;
        if (nums1[flag1 + index_1 - 1] < nums2[flag2 + index_2 - 1])
        {
            return binary_k(nums1, flag1 + index_1, nums2, flag2, k - index_1);
        }
        else if (nums1[flag1 + index_1 - 1] > nums2[flag2 + index_2 - 1])
        {
            return binary_k(nums1, flag1, nums2, flag2 + index_2, k - index_2);
        }
        else
        {
            return nums1[flag1 + index_1 -1];
        }
    }

    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        size_t total = nums1.size() + nums2.size();
        size_t flag1 = 0, flag2 = 0;
        if (total & 0x1)
        {
            return (double)binary_k(nums1, flag1, nums2, flag2, total/2 + 1);
        }
        else
        {
            return (double)(binary_k(nums1, flag1, nums2, flag2, total/2) + binary_k(nums1, flag1, nums2, flag2, total/2 + 1)) / 2;
        }
    }
};


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) nums1.swap(nums2);
        int len1=nums1.size(), len2=nums2.size();
        int mid=(len1+len2-1)/2, left=0, right=len1-1;
        while(left <= right)
        {
            int mid1 = (left+right)/2, mid2 = mid - mid1;
            if(nums1[mid1] >= nums2[mid2]) right = mid1-1;
            else left = mid1+1;
        }
        double med1=max(left>0?nums1[right]:INT_MIN, nums2[mid-left]);
        if((len1+len2)%2) return med1;
        double med2=min(left<len1?nums1[left]:INT_MAX,
                        mid-right<len2?nums2[mid-right]:INT_MAX);
        return (med1 + med2)/2;
    }
};