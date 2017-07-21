#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int size = s.size();
		stack<int> mystack;
		int i = 0;
		for (; i < size; ++i) {
			if (s[i] == '(') {
				mystack.push(i);
			}
			else {
				if (!mystack.empty() && s[mystack.top()] == '(') mystack.pop();
				else mystack.push(i);
			}
		}
		int max = 0 ,j;
		if (!mystack.size()) return size;
		i = size;
		while (!mystack.empty()) {
			j = mystack.top();
			mystack.pop();
			if (max < i - j - 1) max = i - j - 1;
			i = j;
		}
		if (max < j) max = j;
		return max;
	}
};

int main() {
	Solution solve;
	string s = "(";
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

