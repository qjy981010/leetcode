/*第一次自己从头到尾写动态规划，果然炸了，运行效率感人。。
没找到正确的姿势，自己的代码到处都是遍历。。。

（错误）思路：首先保证不是长变短（感觉这样方便些），然后对短字符串（其实可能一样长），
先考虑第一个字符变到长字符串需要几步，然后算前两个字符变过去需要几步。。。太慢啦*/

#include <iostream>
#include <string>
#include <map>
#include <climits>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
	vector<int*> minstepof;

    int minDistance(string word1, string word2) {
		if (!word1.size()) return word2.size();
		if (!word2.size()) return word1.size();
        if (word1.size() > word2.size()) return minStep(word2, word1);
		else return minStep(word1, word2);
    }

	int minStep(string originstr, string targetstr) {
		int i, j, k;
		int osize = originstr.size();
		int tsize = targetstr.size();
		for (i = 0; i < osize; ++i) {
			int min, tstep, ostep, gap;
			vector<int> index(0);
			for (j = 0; j < tsize; ++j) {
				if (targetstr[j] == originstr[i]) index.push_back(j);
			}
			min = INT_MAX;
			if (!index.size()) {
				int * myarray = new int[3];
				myarray[0] = tsize;
				myarray[1] = tsize;
				myarray[2] = i;
				minstepof.push_back(myarray);
			}

			int judge;
			for (j = 0; j < index.size(); ++j) {
				judge = 0;
				for (k = 0; k < minstepof.size(); ++k) {
					if (minstepof[k][2] == i) continue;
					if (index[j] > minstepof[k][1]) {
						gap = i - minstepof[k][2] - index[j] + minstepof[k][1];
						if (gap > 0) gap += minstepof[k][0] - 1;
						else gap = minstepof[k][0] - 1;
						if (gap < min) {
							min = gap;
							tstep = index[j];
						}
						judge = 1;
					}
				}
				if (judge) {
					int * myarray = new int[3];
					myarray[0] = min;
					myarray[1] = tstep;
					myarray[2] = i;
					minstepof.push_back(myarray);
				}
				int * myarray = new int[3];
				myarray[0] = tsize - 1;
				if ((gap = i - index[j]) > 0) myarray[0] += gap;
				myarray[1] = index[j];
				myarray[2] = i;
				minstepof.push_back(myarray);
			}
			for (j = 0; j < minstepof.size(); ++j) {
				cout << minstepof[j][0] << minstepof[j][1] << minstepof[j][2] << endl;
			}
		}

		int min = tsize;
		for (i = 0; i < minstepof.size(); ++i) {
			int gap = osize - minstepof[i][2] - tsize + minstepof[i][1];
			if (gap > 0) minstepof[i][0] += gap;
			cout << gap << ' ' << minstepof[i][0] << endl;
			if (minstepof[i][0] < min) min = minstepof[i][0];
		}
		return min;
	}
};


int main() {
	Solution solve;
	string word1 = "botcher";
	string word2 = "teacher";
	cout << solve.minDistance(word1, word2) << endl;
}


/*原来下面这才是dp的正确姿势。。。。
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int> > distance(m+1,vector<int>(n+1));
         
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(0==i){
                    distance[i][j]=j;
                }
                else if(0==j){
                    distance[i][j]=i;
                }
                else{
                    distance[i][j]=min(distance[i-1][j-1]+((word1[i-1]==word2[j-1])?0:1),  // 状态转移方程；
                                       min(distance[i-1][j]+1,distance[i][j-1]+1)
                                       );
                }  
            }       
        }
        return distance[m][n];
    }
};

简化为一维：处理第i行时只需要知道第i-1行的值即可，不需要把整个矩阵一直存起来
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<int> distance(n+1);
         
        for(int i=0;i<=m;i++){
            int last;
            for(int j=0;j<=n;j++){
                if(0==i){
                    distance[j]=j;
                }
                else if(0==j){
                    last=distance[j];
                    distance[j]=i;
                }
                else{
                    int temp=distance[j];
                    distance[j]=min(last+((word1[i-1]==word2[j-1])?0:1),
                                       min(distance[j]+1,distance[j-1]+1)
                                       );
                    last=temp;
                }  
            }       
        }
        return distance[n];
    }
};
*/
