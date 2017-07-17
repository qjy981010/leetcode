#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		size = s.size();
		if (!size) return 0;
		int lvp[size];
		if (s[0] == '(') lvp[0] = 1;
		else lvp[0] = -1;
		int i = 1;
		for (; i < size; ++i) {
			if (s[i] == '(') {
				if (lvp[i-1] <= 0) lvp[i] = 1;
				else lvp[i] = lvp[i-1] + 1;
			}
			if (s[i] == ')') {
				lvp[i] = lvp[i-1] - 1;
			}
		}
	}
}

int main() {
	Solution solve;
	string s = "()())()))(()))))";
	cout << solve.longestValidParentheses(s) << endl;
	return 0;
}

/*
class Solution {
public:
	int longestValidParentheses(string s) {
		int strsize = s.size();
		if (!strsize) return 0;
		int stacksize;
		int result = 0, i = 0, j = 0;
		int shortestVP[strsize];

		for (; j < strsize; ++j) {
			shortestVP[j] = 0;
		}

		while (i < strsize) {
			if (s[i] == '(') {
				stacksize = 1;
				for (j = i + 1; j < strsize; ++j) {
					if (s[j] == '(') ++stacksize;
					else --stacksize;
					if (!stacksize) {
						shortestVP[i] = j - i + 1;
						i = j;
						break;
					}
				}
			}
			++i;
		}

		for (i = 0; i < strsize; ++i) {
			stacksize = 0;
			while (i < strsize && shortestVP[i]) {
				stacksize += shortestVP[i];
				i += shortestVP[i];
			}
			if (stacksize > result) result = stacksize;
		}
		return result;
	}
};
*/

