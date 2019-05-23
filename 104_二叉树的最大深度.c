/*104. 二叉树的最大深度
题目描述：
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]
		  3
		 / \
		9  20
		  /  \
		 15   7

返回它的最大深度 3 。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* 超出时间限制 */
#define max(a,b)  ((a) >= (b) ? (a) : (b))

int maxDepth(struct TreeNode* root)
{
	int maxdepth = 0;
	if(root == NULL)
		return 0;
	else
	{
		maxdepth = max(maxDepth(root->left),maxDepth(root->right));
		return maxdepth+1;
    }
}

/* 为什么这样就可以。。 */
int maxDepth(struct TreeNode* root)
{
	int l_depth = 0,r_depth = 0,maxdepth = 0;
	if(root == NULL)
		return 0;
	else
	{
		l_depth = maxDepth(root->left) + 1;
		r_depth = maxDepth(root->right) + 1;
	}
	
	maxdepth = l_depth >= r_depth ? l_depth : r_depth;
	return maxdepth;

}


