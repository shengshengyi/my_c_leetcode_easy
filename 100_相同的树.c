/*100. 相同的树
题目描述：
给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例1:
	输入:       1         1
	          / \       / \
	         2   3     2   3

	        [1,2,3],   [1,2,3]

	输出: true

示例2:
	输入:      1          1
	          /           \
	         2             2

	        [1,2],     [1,null,2]

	输出: false

示例3：
	输入:       1         1
	          / \       / \
	         2   1     1   2

	        [1,2,1],   [1,1,2]

	输出: false

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* 看了评论区的答案，很好的思路 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL)
      return true;
    if(p == NULL || q == NULL || p->val != q->val)
        return false;
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}



