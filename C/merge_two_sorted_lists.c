/*****************************************************
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the 
first two lists.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode *p, *q, *r, *res, *node;
    p = l1, q = l2;
    
    res = NULL;
    while(p != NULL && q != NULL)
    {
        if(p->val < q->val)
        {
            r = p;
            p = p->next;
        }
        else
        {
            r = q;
            q = q->next;
        }
    
        if(res == NULL){res = r; node = res;}
        else {node->next = r; node = node->next;}
    }
    
    while(p)
    {
        if(res == NULL){res = p; node = res;}
        else {node->next = p; node = node->next;}
        
        p = p->next;
    }
    
    while(q)
    {
        if(res == NULL){res = q; node = res;}
        else {node->next = q; node = node->next;}
        
        q = q->next;
    }
    
    return res;
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
	int set1[] = {2, 4, 7, 10, 39};
	int set2[] = {5, 6, 100};

	struct ListNode *l1 = initlist(set1, sizeof(set1)/sizeof(int));
	struct ListNode *l2 = initlist(set2, sizeof(set2)/sizeof(int));

	struct ListNode *res = mergeTwoLists(l1, l2);
	printlist(res);
}

