#include<iostream>

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

