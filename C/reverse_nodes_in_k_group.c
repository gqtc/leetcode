/*****************************************************
Given a linked list, reverse the nodes of a linked list k at a time 
and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes 
in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may 
be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
};


struct ListNode *reverseknode(struct ListNode *begin, int k)
{
	struct ListNode *endnext = begin;
	while(k && endnext)
	{
		k--;
		endnext = endnext->next;
	}
	if(k > 0)	return begin;

	struct ListNode *reshead = endnext;
	struct ListNode *p, *q;
	p = begin;

	while(p != endnext)
	{
		q = p->next;
		p->next = reshead;
		reshead = p;
		p = q;
	}

	return reshead;
	
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) 
{
	struct ListNode *reshead, *p, *q, *r;

	reshead = NULL;
	p = head;

	while(p != NULL)
	{
		q = reverseknode(p, k);

		if(reshead == NULL)	reshead = q;
		else r->next = q;

		if(p == q)	break;

		r = q;
		while(r != p)
		{
			r = r->next;
		}
		p = p->next;
	}
	return reshead;
}


struct ListNode * initlist(int *sets, int listlen)
{
	struct ListNode *head = NULL;
	struct ListNode *q = NULL;
	int i = 0;
	while(i < listlen)
	{
		struct ListNode *p = calloc(1, sizeof(struct ListNode));
		p->val = sets[i];
		if(head == NULL)
		{
			head = p;
			q = p;
		}
		else
		{
			q->next = p;
			q = p;
		}
		i++;
	}
	return head;
}
void printlist(struct ListNode *head)
{
	while(head)
	{
		printf("%d-->", head->val);
		head = head->next;
	}
	printf("\b\b\b   \n");
}

int main()
{
	int set[] = {0, 1, 2, 3, 4, 5, 6};

	struct ListNode *res = NULL;

	int k;
	for(k = 2; k <= 7; k++)
	{
		struct ListNode *list1 = initlist(set, sizeof(set)/sizeof(int));
		res = reverseKGroup(list1, k);
		printlist(res);
	}
}

