#include <iostream>

using namespace std;

class Solution {
public:
	int integerReplacement(int n) {
		return replace((long long)n, 0);
	}

	int replace(long long n, int step) {
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