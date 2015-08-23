/*****************************************************
Given a list, rotate the list to the right by k places, 
where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ListNode 
{
	int val;
	struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) 
{
    struct ListNode *p, *q;
    int listlen = 0;
    p = head;
    while(p != NULL)
    {
        p = p->next;
        listlen++;
    }

    if(listlen == 0)    return NULL;
    
    k = k % listlen;
    if(k == 0)  return head;
    
    int i = 0;
    p = head;
    q = head;
    while(p->next != NULL)
    {
        if(i < k)
        {
            i++;
            p = p->next;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
        
    }
    p->next = head;
    head = q->next;
    q->next = NULL; 
    
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
	int sets[] = {1, 2, 3, 4, 5};

	struct ListNode *head = initlist(sets, sizeof(sets)/sizeof(int));

	struct ListNode *res = rotateRight(head, 2);
	printlist(res);
}

