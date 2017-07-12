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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || root == p || root == q) {
			return root;
		}
		
		TreeNode* right_result = lowestCommonAncestor(root->right, p, q);
		TreeNode* left_result = lowestCommonAncestor(root->left, p, q);
		
		if (right_result && left_result) return root;
		else if (right_result) return right_result;
		else return left_result;
    }
};

// only beats 19%, but it's close to the fastest;
// maybe it's slow because of some details.
