// Binary Tree Maximum Path Sum
// 从每个结点向左右递归，将左右的和与当前最大值比较，需要时更新最大值
// 然后左右若有和为负则置0，并返回左右最大值与次结点值的和，注意左右有null以及值为负的情况

/*note: 分治递归*/

#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution { // 51.05%
public:
	int maxsum = -2147483648;

	int maxPathSum(TreeNode* root) {
		if (root) maxBranchSumofThisNode(root);
		return maxsum;
	}

	int maxBranchSumofThisNode(TreeNode* root) {
		if (!root->left) {
			if (root->right) {
				int rightsum = maxBranchSumofThisNode(root->right);
				if (root->val < 0) {
					if (maxsum < rightsum) maxsum = rightsum;
				}
				if (rightsum < 0) rightsum = 0;
				if (rightsum + root->val > maxsum) maxsum = rightsum + root->val;
				return rightsum + root->val;
			}
			else {
				if (root->val > maxsum) maxsum = root->val;
				return root->val;
			}
		}
		else {
			if (!root->right) {
				int leftsum = maxBranchSumofThisNode(root->left);
				if (root->val < 0) {
					if (maxsum < leftsum) maxsum = leftsum;
				}
				if (leftsum < 0) leftsum = 0;
				if (leftsum + root->val > maxsum) maxsum = leftsum + root->val;
				return leftsum + root->val;
			}
		}
		int leftsum = maxBranchSumofThisNode(root->left);
		int rightsum = maxBranchSumofThisNode(root->right);
		if (root->val < 0) {
			if (maxsum < leftsum) maxsum = leftsum;
			if (maxsum < rightsum) maxsum = rightsum;
		}
		if (leftsum < 0) leftsum = 0;
		if (rightsum < 0) rightsum = 0;
		if (leftsum + rightsum + root->val > maxsum) maxsum = leftsum + rightsum + root->val;
		return max(leftsum, rightsum) + root->val;
	}
};
