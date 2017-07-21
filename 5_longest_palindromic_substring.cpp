// 以一个字符为中心或以字符间隙为中心，向两边扩展O(n^2)
// 效率超过70%，可以用动态规划做，效率可能并不快，也可以用后缀树，时间复杂度O(n*logn)，最好的办法是用Manacher算法O(n)
// http://blog.csdn.net/dyx404514/article/details/42061017

/*note: manacher算法*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		int length = s.size(), begin = 0, j, max = 1;
		if (!length) return s;
		for (int i = 1; i < length; ++i) {
			for (j = 1; i - j >= 0 && i + j < length; ++j) {
				if (s[i-j] == s[i+j]) {
					if (max < (j << 1) + 1) {
						max = (j << 1) + 1;
						begin = i - j;
					}
				}
				else {
					break;
				}
			}
			for (j = 1; i - j >= 0 && i + j - 1 < length; ++j) {
				if (s[i-j] == s[i+j-1]) {
					if (max < j << 1) {
						max = j << 1;
						begin = i - j;
					}
				}
				else {
					break;
				}
			}
		}
		string result;
		result.assign(s, begin, max);
		return result;
    }
};

int main() {
	Solution solve;
	string s = "bb";
	cout << solve.longestPalindrome(s) << endl;
}
