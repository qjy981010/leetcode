#include<iostream>

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
