/*104. ��������������
��Ŀ������
�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ����
���������� [3,9,20,null,null,15,7]
		  3
		 / \
		9  20
		  /  \
		 15   7

�������������� 3 ��
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* ����ʱ������ */
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

/* Ϊʲô�����Ϳ��ԡ��� */
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


