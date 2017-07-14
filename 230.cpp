/* 从小到大，中序遍历，思路比较简单*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	int count = 0;

public:
    int kthSmallest(TreeNode* root, int k) {
        return searchKth(root, k)->val;
    }

	TreeNode *searchKth(TreeNode* root, int k) {
		if (root == nullptr) return nullptr;
		TreeNode *result = searchKth(root->left, k);
		if (result) return result;
		++count;
		if (count == k) return root;
		return searchKth(root->right, k);
	}
};
