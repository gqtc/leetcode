/*****************************************************
Given a linked list, swap every two adjacent nodes and return 
its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not 
modify the values in the list, only nodes itself can be changed.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) 
{
    struct ListNode *p, *q, *r;

    int i = 0;

	if(head == NULL)	return NULL;
    p = head->next;
    q = head;
	r = NULL;

	while(p != NULL)
	{	
		i++;
		if(r == NULL)	head = p;
		else	r->next = p;
	    q->next = p->next;
	    p->next = q;

		r = q;
	    q = q->next;
	    if(q != NULL)	    p = q->next;
	    else 	break;
    }

    return head;
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

	struct ListNode *list1 = initlist(set, sizeof(set)/sizeof(int));
	printlist(list1);

	struct ListNode *res = swapPairs(list1);
	printlist(res);
}	

