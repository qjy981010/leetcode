// 遍历，遇到值为‘1’的点则将岛的数量加一，然后递归向四周值为‘1’的方向扩展，并将经过的点设为‘0’

/*note: 递归，经过即删除*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int linesnum, columnsnum;

	int numIslands(vector<vector<char>>& grid) {
		linesnum = grid.size();
		if (!linesnum) return 0;
		columnsnum = grid[0].size();
		if (!columnsnum) return 0;
		int num = 0;
		for (int i = 0; i < linesnum; ++i) {
			for (int j = 0; j < columnsnum; ++j) {
				if (grid[i][j] == '1') {
					expand(grid, i, j);
					++num;
				}
			}
		}
		return num;
	}

	void expand(vector<vector<char>>& grid, int i, int j) {
		grid[i][j] = 0;
		if (j < columnsnum - 1 && grid[i][j+1] == '1') {
			expand(grid, i, j + 1);
		}
		if (i < linesnum - 1 && grid[i+1][j] == '1') {
			expand(grid, i + 1, j);
		}
		if (i > 0 && grid[i - 1][j] == '1') {
			expand(grid, i - 1, j);
		}
		if (j > 0 && grid[i][j - 1] == '1') {
			expand(grid, i, j - 1);
		}
	}
};

int main() {
	Solution solve;
	vector<vector<char>> grid = {{'1','1','1'},{'0','1','0'},{'1','1','1'}};
	cout << solve.numIslands(grid) << endl;
	return 0;
}