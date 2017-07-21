/*先求第一个window里的最大值，然后根据他在这个window里的位置设置ttl（time to live），
继续向后面走，如果ttl>0就说明以前的这个最大值对此window还有效，如果新加入的节点比有效的以前的最大值大，
此window的最大值就是新的值，并重置ttl，否则最大值仍为以前的最大值；若以前的最大值无效，则要重新找出最大值
最坏情况复杂度为kn*/

/* 可以维护优先队列实现，O(n*logk)
   deque实现，O(n)*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (nums.size() == 0) return nums;
		vector<int> result;
		int i, max = nums[0], ttl = 0;
		for (i = 1; i < k; ++i) {
			if (nums[i] > max) {
				max = nums[i];
				ttl = i;
			}
		}
		result.push_back(max);
		int N = nums.size() - k;
		for (i = 0; i < N; ++i) {
			if (nums[k+i] >= max) {
				max = nums[k+i];
				result.push_back(max);
				ttl = k - 1;
			}
			else {
				if (ttl > 0) {
					result.push_back(max);
					ttl--;
				}
				else {
					max = nums[i+1];
					for (int j = i+2; j < i+k+1; ++j) {
						if (nums[j] > max) {
							max = nums[j];
							ttl = j-i-1;
						}
					}
					result.push_back(max);
				}
			}
		}
		return result;
    }
};


int main() {
	Solution solve;
	vector<int> v;
	vector<int> result = solve.maxSlidingWindow(v, 0);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	cout << endl;
}

//击败了78%

/* 用deque实现，击败95%
	vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        deque<int> idq;
        vector<int> result;
        int i = 0;

        for (i = 0; i < k - 1; i++)
        {
            while (!idq.empty() && (idq.back() < nums[i]))
                idq.pop_back();
            idq.push_back(nums[i]);
        }

        for (i = k - 1; i < nums.size(); i++)
        {
            while (!idq.empty() && (idq.back() < nums[i]))
                idq.pop_back();
            idq.push_back(nums[i]);
            
            result.push_back(idq.front());
            
            if (idq.front() == nums[i - k + 1])
                idq.pop_front();
        }
        
        return result;
    }
*/


