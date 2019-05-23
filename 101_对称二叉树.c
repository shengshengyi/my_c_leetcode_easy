/*101. 对称二叉树
题目描述：
	给定一个二叉树，检查它是否是镜像对称的。


例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
*/

/* 和上一题的思路应该是一样的 */
/* 竟然一次过了 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSymmetric(struct TreeNode* root){

	struct TreeNode *root1 = root;

	bool isMirro(struct TreeNode* root, struct TreeNode* root1)
	{
	    if(root == NULL && root1 == NULL)
			return true;
	    if(root == NULL || root1 == NULL)
			return false;

		return (root->val == root1->val) && isMirro(root->left,root1->right) && isMirro(root->right,root1->left);
	}


	return isMirro(root,root1);
}


