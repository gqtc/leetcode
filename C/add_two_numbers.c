/*****************************************************
You are given two linked lists representing two non-negative 
numbers. The digits are stored in reverse order and each of their 
nodes contain a single digit. Add the two numbers and return it as 
a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode *p = NULL;
    struct ListNode *q = NULL;
    struct ListNode *reshead = NULL;
    struct ListNode *curnode = NULL;
    struct ListNode *lastnode = NULL;
    int tmp = 0;
    int a1 = 0;
    int a2 = 0;
    
    p = l1, q = l2;
    while(p != NULL || q != NULL || tmp != 0)
    {
        a1 = p?(p->val):0;
        a2 = q?(q->val):0;
        curnode = calloc(1, sizeof(struct ListNode));
        curnode->val = (a1+a2+tmp)%10;
        tmp = (a1+a2+tmp)/10;
        if(reshead == NULL)
        {
            reshead = curnode;
        }
        else
        {
            lastnode->next = curnode;
        }
        lastnode = curnode;
        if(p)p = p->next;
        if(q)q = q->next;
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
	int set1[] = {2, 4, 3};
	int set2[] = {5, 6, 4};

	struct ListNode *l1 = initlist(set1, sizeof(set1)/sizeof(int));
	struct ListNode *l2 = initlist(set2, sizeof(set2)/sizeof(int));

	struct ListNode *res = addTwoNumbers(l1, l2);
	printlist(res);
}
