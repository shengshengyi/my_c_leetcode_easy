/* 83. ɾ�����������е��ظ�Ԫ��
��Ŀ������
����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�

ʾ�� 1:
	����: 1->1->2
	���: 1->2


ʾ�� 2:
	����: 1->1->2->3->3
	���: 1->2->3

*/

/*���ǲ����жϵ�ǰ�ڵ����һ���ڵ��val�Ƿ��뵱ǰ�ڵ��val��ͬ��
 *��ͬ�Ļ���ǰ�ڵ��nextָ��ָ����һ�ڵ����һ���ڵ㣬
 *����ǰ�ڵ����һ���ڵ㡣
 */
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	   int val;
 *	   struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
   	if(head == NULL || head->next == NULL)
        return head;

	struct ListNode* cur = head;

	while(cur)
	{
		
		while(cur->val == cur->next->val)/* erro */
		/* Line 10: Char 30: runtime error: member access within null pointer of type 'struct ListNode' (solution.c) */	
			cur->next = cur->next->next;
		cur = cur->next;
	}
	return head;

}

/*
����ĺ��壺����Ϊ��struct ListNode���Ŀ�ָ���ڵĳ�Ա����
���������Ҫ�����ڲ���ϵͳ��֪����ǰ�Ľ���������һ������Ƿ�ΪNULL�����Լ���û������������ϵͳ��ȷ�������Ǿͱ���
�������cur->next != NULL 
*/



struct ListNode* deleteDuplicates(struct ListNode* head){
  
    if(head == NULL || head->next == NULL)
        return head;

	struct ListNode* cur = head;
	struct ListNode* last = cur->next;

	while(cur)
	{
		
		while(cur->next != NULL &&cur->val == cur->next->val)
            {
                cur->next = cur->next->next;
            }
			cur = cur->next;
	}
	return head;
}

