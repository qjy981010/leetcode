#include <iostream>

using namespace std;

class Solution {
public:
	int integerBreak(int n) {
		if (n < 4) return 1 + (n == 3);
		int numof3 = n / 3;
		int gap = n - 3 * numof3;
		int result = 1;
		switch (gap) {
			case 0:
				for (int i = 0; i < numof3; ++i) {
					result *= 3;
				}
				return result;
			case 1:
				for (int i = 1; i < numof3; ++i) {
					result *= 3;
				}
				return result * 4;
			case 2:
				for (int i = 0; i < numof3; ++i) {
					result *= 3;
				}
				return result * 2;
		}
	}
};

int main() {
	Solution solve;
	cout << solve.integerBreak(2) << endl;
}
