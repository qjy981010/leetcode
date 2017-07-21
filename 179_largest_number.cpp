// 重点在数字的比较，自定义c++sort函数的比较函数
// 先把数字转化成字符串，然后换顺序将两个字符串相加，哪个字符串在前时结果大，则此字符串大

/*note: 暴力而不失优雅的比较函数*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
	static bool mycomp(const string& a, const string& b) {//开始写了半天比较函数，特别复杂有bug，后来想出来这种操作。。。
		return a+b > b+a;
	}

	string largestNumber(vector<int>& nums) {
		int size = nums.size();
		if (!size) return "";
		string array[size];
		int i = 0;
		char inttostr[10];
		for (; i < size; ++i) {
			sprintf(inttostr, "%d", nums[i]);
			array[i] = inttostr;
		}
		sort(array, array + size, mycomp);
		string result;
		bool atbegin = 1;
		for (i = 0; i < size; ++i) {
			if (atbegin && array[i]=="0" && i < size - 1) continue;
			result += array[i];
			atbegin = false;
		}
		return result;
	}
};

int main() {
	Solution solve;
	vector<int> nums;
	nums.push_back(824);
	nums.push_back(8247);
	cout << solve.largestNumber(nums) << endl;
	return 0;
}
