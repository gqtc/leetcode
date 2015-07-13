/*****************************************************
Given a linked list, remove the nth node from the end of list and return 
its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 
1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ListNode 
{
	int val;
	struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    struct ListNode *p, *q, *r;
    
    p = head;
    while(n-- > 0)  p = p->next;
    
    r = q;
    q = head;
    while(p != NULL)
    {
        p = p->next;
        r = q;
        q = q->next;
    }
    
    if(q == head)   return head->next;
    r->next = q->next;
    
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
	int sets[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

	struct ListNode *beforerm = initlist(sets, sizeof(sets)/sizeof(int));
	printf("before remove, list is :\n");
	printlist(beforerm);

	struct ListNode *afterrm = removeNthFromEnd(beforerm, 2);
	printf("\nafter remove, list is :\n");
	printlist(afterrm);
}

