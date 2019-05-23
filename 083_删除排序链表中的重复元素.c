/* 83. 删除排序链表中的重复元素
题目描述：
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:
	输入: 1->1->2
	输出: 1->2


示例 2:
	输入: 1->1->2->3->3
	输出: 1->2->3

*/

/*就是不断判断当前节点的下一个节点的val是否与当前节点的val相同，
 *相同的话当前节点的next指针指向下一节点的下一个节点，
 *否则当前节点后移一个节点。
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
错误的含义：类型为“struct ListNode”的空指针内的成员访问
这个问题主要是由于测试系统不知道当前的结点与结点的下一个结点是否为NULL，而自己有没有声明，所以系统不确定，于是就报错
添加条件cur->next != NULL 
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

