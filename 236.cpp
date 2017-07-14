/*递归向左右查找，两边都找到则返回此节点，只有一边找到就返回那个找到的那个指针*/

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
		if (!root) return nullptr;	// 如果把这四行写为 if (root==nullptr||root==p||root==q) return root;则只能击败17%。。。
		if (root == p || root == q) {
			return root;
		}
		
		TreeNode* right_result = lowestCommonAncestor(root->right, p, q);
		TreeNode* left_result = lowestCommonAncestor(root->left, p, q);
		
		if (right_result && left_result) return root;
		else if (right_result) return right_result;
		else return left_result;
    }
};

// 击败了93%
