
/*021. 合并两个有序链表

将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

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

	//头结点
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
	//比较两个链表大小，小的赋值，大的下一轮比较
	//如果l1 小于 l2  则将p的 next 指向 此时l1的节点，然后l1在后移一位，同时更新p的值。
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

	//比较完成，还剩一个链表有值，直接放入p
	if(l1 != NULL)	p -> next = l1;
	if(l2 != NULL)	p -> next = l2;	

	return head;
}

