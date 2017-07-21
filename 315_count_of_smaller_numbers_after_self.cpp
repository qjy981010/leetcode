// 倒序遍历数组将每个数插入一个二叉搜索树,在每个结点记下其左分支的结点数
// 若新数大于某个其经过的结点的值，则他右面比他小的数的数量+=此结点左分支结点数
// 

#include <iostream>
#include <vector>

using namespace std;

// binary search tree!
class Solution { // 83.2%
public:
	struct node {
		node* left = nullptr;
		node* right = nullptr;
		int val;
		int leftnum = 0;
		node(int num) {val = num;}
	};
	node* root;
	int size = 0;

	vector<int> countSmaller(vector<int>& nums) {
		size = nums.size();
		int i = size - 2;
		vector<int> result(size, 0);
		if (i < 0) return result;
		root = new node(nums[size-1]);
		for (; i >= 0; --i) {
			node* it = root;
			for (;;) {
				if (nums[i] > it->val) {
					result[i] += it->leftnum + 1;
					if (it->right) it = it->right;
					else {
						it->right = new node(nums[i]);
						break;
					}
				}
				else {
					it->leftnum++;
					if (it->left) it = it->left;
					else {
						it->left = new node(nums[i]);
						break;
					}
				}
			}
			for (int k = 0; k < size; ++k) {
				cout << result[k] << ' ';
			}
			cout << '\n';
		}
		return result;
	}
};

int main() {
	Solution solve;
	vector<int> nums = {5,2,6,1};
	int size = nums.size();
	vector<int> v = solve.countSmaller(nums);
	for (int i = 0; i < size; ++i) {
		cout << v[i] << ' ';
	}
	cout << '\n';
	return 0;
}