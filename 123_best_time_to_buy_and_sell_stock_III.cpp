// 动态规划，从左上角开始向下表示保持状态，向右表示买入或卖出，最多只有5列

/*note: 二维dp，可优化*/

#include <iostream>
#include <vector>

using namespace std;

class Solution { // 44.64% ,空间复杂度还可以优化，见188
public:
    int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n < 2) return 0;
		prices.push_back(0);
		prices.push_back(0);
		prices.push_back(0);
		prices.push_back(0);
		int profit[n][5], i, j;
		for (i = 0; i < n; ++i) profit[i][0] = 0;
		profit[0][1] = -prices[0];
		profit[0][2] = prices[1] - prices[0];
		profit[0][3] = profit[0][2] - prices[2];
		profit[0][4] = profit[0][3] + prices[3];
		for (i = 1; i < n; ++i) {
			for (j = 1; j < 5; ++j) {
				if (j & 1) profit[i][j] = max(profit[i][j-1] - prices[i+j-1], profit[i-1][j]);
				else profit[i][j] = max(profit[i][j-1] + prices[i+j-1], profit[i-1][j]);
			}
		}
		int maxprofit = max(profit[n-1][0], profit[n-1][2]);
		for (i = 1; i < n; ++i) {
			if (maxprofit < profit[i][4]) maxprofit = profit[i][4];
		}
		for (i = 0; i < n; ++i) {
			for (j = 0; j < 5; ++j) {
				cout << profit[i][j] << ' ';
			}
			cout << endl;
		}
		return maxprofit;
	}
};

int main() {
	Solution solve;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	cout << solve.maxProfit(v) << endl;
}

