/*101. �Գƶ�����
��Ŀ������
	����һ����������������Ƿ��Ǿ���ԳƵġ�


���磬������ [1,2,2,3,4,4,3] �ǶԳƵġ�

    1
   / \
  2   2
 / \ / \
3  4 4  3
����������� [1,2,2,null,3,null,3] ���Ǿ���ԳƵ�:

    1
   / \
  2   2
   \   \
   3    3
*/

/* ����һ���˼·Ӧ����һ���� */
/* ��Ȼһ�ι��� */

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


