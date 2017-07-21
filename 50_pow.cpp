// 直接二分法，递归，每次对指数进行二分，如果指数是负的就先化为正的，然后取倒数,注意边界问题...
// 不要写成pow(x,n/2) * pow(x,n/2)，这样算了两遍

/*note: 分治*/

#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) return 1 / powf(x, -n);
		else return powf(x, n);
    }
    
    double t;

	double powf(double x, int n) {
		if (n == 1) return x;
        else if (!n) return 1;
		else {
            t = powf(x, n / 2);
            return t * t * (n & 1 ? x : 1);
        }
	}
};

int main() {
	Solution solve;
	cout << solve.myPow(0.00001, 54646532) << endl;
}
