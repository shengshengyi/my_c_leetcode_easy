
/*021. �ϲ�������������

��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ� 

ʾ����

���룺1->2->4, 1->3->4
�����1->1->2->3->4->4

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head,*p;

	//ͷ���
	if(l1.val < l2.val)
	{
		head = l1;
		l1 = l1.next;
	}
	
	else
	{
		head = l2;
		l2 = l2.next;
	}

	p = head;
	//�Ƚ����������С��С�ĸ�ֵ�������һ�ֱȽ�
	//���l1 С�� l2  ��p�� next ָ�� ��ʱl1�Ľڵ㣬Ȼ��l1�ں���һλ��ͬʱ����p��ֵ��
	while(l1 && l2)
	{
		if(l1.val < l2.val)
		{
			p -> next = l1;
			l1 = l1 -> next;
			p = p ->next;
		}
		else
		{	
			p -> next = l2;		
			l2 = l2 -> next;
			p = p ->next;
		}
	}

	//�Ƚ���ɣ���ʣһ��������ֵ��ֱ�ӷ���p
	if(l1 != NULL)	p -> next = l1;
	if(l2 != NULL)	p -> next = l2;	

	return head;
}

