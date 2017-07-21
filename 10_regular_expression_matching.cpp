// 递归，或者动态规划，dp[i][j] 表示 s[0..i] 和 p[0..j] 是否 match
/*note: 写出程序以后再考虑优化，不要一开始就想优化，可能情况太多比较难办*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.length();
        int lenp = p.length();
        if(lenp == 0)
            return lens == 0;

        if(lenp==1 || p[1]!='*')
        {
            if(lens<1 || (s[0]!=p[0] && p[0]!='.'))
                return false;
            return isMatch(s.substr(1,lens-1), p.substr(1,lenp-1));
        }
        else
        {
            int i=-1;
            while(i<lens && (i<0 || p[0]=='.' || p[0]==s[i]))
            {
                if(isMatch(s.substr(i+1,lens-i-1), p.substr(2,lenp-2)))
                    return true;
                ++i;
            }
            return false;
        }
    }
};

int main() {
	Solution solve;
	string s = "aaa";
	string p = "ab*ac*a";
	cout << solve.isMatch(s, p) << endl;
}

