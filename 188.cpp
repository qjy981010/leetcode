#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		long long n = prices.size();
		if (n < 2 || !k) return 0;
        if (k > n / 2){ // simple case
            int ans = 0;
            for (int i=1; i<len; ++i){
                ans += max(prices[i] - prices[i-1],0);
            }
            return ans;
        }
		long long columes = min(n + 1, ((long long)k << 1) + 1); // the number of columns
		int profit[2][columes], i = 1, j, currentline;
		profit[0][0] = profit[1][0] = 0; // the first column
		for (; i < columes; ++i) { // the first line
			profit[0][i] = profit[0][i-1] + (i & 1 ? -prices[i-1] : prices[i-1]);
		}
		int maxprofit = max(profit[0][columes-1], 0);
		for (i = 1; i < n; ++i) {
			for (j = 1; j < columes; ++j) {
				if (i + j > n) break;
				currentline = i & 1;
				if (j & 1) profit[currentline][j] = max(profit[currentline][j-1] - prices[i+j-1], profit[!currentline][j]);
				else profit[currentline][j] = max(profit[currentline][j-1] + prices[i+j-1], profit[!currentline][j]);
			}
			if (maxprofit < profit[currentline][j-1]) maxprofit = profit[currentline][j-1];
		}
		return maxprofit;
	}
};

/* DP solution from the discuss
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int len = prices.size();
        if (len<2) return 0;
        if (k>len/2){ // simple case
            int ans = 0;
            for (int i=1; i<len; ++i){
                ans += max(prices[i] - prices[i-1],0);
            }
            return ans;
        }
        int hold[k+1];
        int rele[k+1];
        for (int i=0;i<=k;++i){
            hold[i] = INT_MIN;
            rele[i] = 0;
        }
        int cur;
        for (int i=0; i<len; ++i){
            cur = prices[i];
            for(int j=k; j>0; --j){
                rele[j] = max(rele[j],hold[j] + cur);
                hold[j] = max(hold[j],rele[j-1] - cur);
            }
        }
        return rele[k];
    }
};
*/

int main() {
	Solution solve;
	vector<int> v = {1,2};
	cout << solve.maxProfit(1, v) << endl;
}


/*
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		long long n = prices.size();
		if (n < 2) return 0;
		long long columes = min(n + 1, ((long long)k << 1) + 1);
		int profit[n][columes], i = 1, j;
		for (; i < columes; ++i) {
			prices.push_back(0);
		}
		for (i = 0; i < n; ++i) profit[i][0] = 0;
		for (i = 1; i < columes; ++i) {
			profit[0][i] = profit[0][i-1] + (i & 1 ? -prices[i-1] : prices[i-1]);
		}
		for (i = 1; i < n; ++i) {
			for (j = 1; j < columes; ++j) {
				if (j & 1) profit[i][j] = max(profit[i][j-1] - prices[i+j-1], profit[i-1][j]);
				else profit[i][j] = max(profit[i][j-1] + prices[i+j-1], profit[i-1][j]);
			}
		}
		int maxprofit = 0;
		for (i = 2; i < columes; i += 2) {
			if (maxprofit < profit[n-1][i]) maxprofit = profit[n-1][i];
		}
		cout << maxprofit << ' ';
		for (i = 1; i < n; ++i) {
			if (maxprofit < profit[i][columes-1]) maxprofit = profit[i][columes-1];
		}
		cout << maxprofit << ' ';
		for (i = 0; i < n; ++i) {
			for (j = 0; j < columes; ++j) {
				cout << profit[i][j] << ' ';
			}
			cout << endl;
		}
		return maxprofit;
	}
};
*/