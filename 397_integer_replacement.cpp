// 递归，是偶数就除二，是奇数就先看看它上下是否为2的幂，如果是，则用位运算快速算出结果，如果不是就+1和-1递归取小的

/*note: 位运算技巧：若n & (n-1)为0，则n为2的幂*/

#include <iostream>

using namespace std;

class Solution {
public:
	int integerReplacement(int n) {
		return replace((long long)n, 0);
	}

	int replace(long long n, int step) { // long long 处理溢出
		if (n == 1) return step;
		else if (!(n & 1)) {
			step = replace(n >> 1, step + 1);
		}
		else {
			if (!(n - 1 & n - 2)) {
				--n;
				while (n != 1) {
					++step;
					n >>= 1;
				}
				return step + 1;
			}
			else if (!(n & (n+1))) {
				++n;
				while (n != 1) {
					++step;
					n >>= 1;
				}
				return step + 1;
			}
			step = min(replace(n + 1, step + 1), replace(n - 1, step + 1));
		}
		return step;
	}
};

int main() {
	Solution solve;
	cout << solve.integerReplacement(15) << endl;
}
// 2147483647