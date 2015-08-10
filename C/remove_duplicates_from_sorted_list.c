/*****************************************************
Given a sorted linked list, delete all duplicates such that each 
element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.


*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
};


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

struct ListNode* deleteDuplicates(struct ListNode* head) 
{
	struct ListNode *p, *q;
	int lastval;

	if(head == NULL)
	{
		return NULL;
	}

	p = head;

	q = p;
	lastval = p->val;

	while(p != NULL)
	{
		if(p != head && p->val != lastval)
		{
			q->next = p;
			q = p;
			lastval = p->val;
		}
		p = p->next;
	}

	q->next = NULL;
	return head;
}


int main()
{
	int sets[] = {0, 0, 0, 1, 4, 4, 6, 7, 7};

	struct ListNode *beforerm = initlist(sets, sizeof(sets)/sizeof(int));
	printf("before remove, list is :\n");
	printlist(beforerm);

	struct ListNode *afterrm = deleteDuplicates(beforerm);
	printf("\nafter remove, list is :\n");
	printlist(afterrm);
}

