/*****************************************************
Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
};

typedef struct
{
    int val;
    int index;
}HeapNode;

void swap(HeapNode *a, HeapNode *b)
{
    HeapNode temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

void minheapify(HeapNode *heap, int heapsize, int index)
{
    int left, right;
    int key;
    
    int smallest;
    while(index < heapsize)
    {
        left = 2*index+1;
        right = 2*index+2;
        smallest = index;
        if(left < heapsize && heap[index].val > heap[left].val)
        {
            smallest = left;
        }
        if(right < heapsize && heap[smallest].val > heap[right].val)
        {
            smallest = right;
        }
        
        if(smallest == index)   return;
        swap(heap+smallest, heap+index);
        index = smallest;
    }
}

void buildminheap(HeapNode *heap, int heapsize)
{
    int start = (heapsize-2)/2;
    
    while(start >= 0)
    {
        minheapify(heap, heapsize, start);
        start--;
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) 
{
    int i ,j;
    int heapsize = listsSize;
    int minindex = -1;
    struct ListNode *head = NULL;
    struct ListNode *node = NULL;
    
    if(listsSize == 0)  return head;
    HeapNode *heap = calloc(heapsize, sizeof(HeapNode));
    for(i = 0, j = 0; i < heapsize; i++)
    {
        if(lists[i] == NULL)
        {
            continue;
        }
        heap[j].val = lists[i]->val;
        heap[j].index = i;
        j++;
    }
    heapsize = j;
    if(heapsize == 0)   return head;
    
    buildminheap(heap, heapsize);
    minindex = heap[0].index;
    head = lists[minindex];
    node = head;
    lists[minindex] = lists[minindex]->next;
    while(1)
    {
        if(lists[minindex] == NULL)
        {
            heapsize -= 1;
            if(heapsize == 0)   return head;
            swap(heap, heap+heapsize);
            minheapify(heap, heapsize, 0);
        }
        else
        {
            heap[0].val = lists[minindex]->val;
            minheapify(heap, heapsize, 0);
        }
        minindex = heap[0].index;
        node->next = lists[minindex];
        node = node->next;
        lists[minindex] = lists[minindex]->next;
    }
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
	int set3[] = {1, 4, 29, 39, 45, 101};
	int set4[] = {100, 101, 200, 400};

	struct ListNode **listsets = calloc(4, sizeof(struct ListNode *));
	listsets[0] = initlist(set1, sizeof(set1)/sizeof(int));
	listsets[1] = initlist(set2, sizeof(set2)/sizeof(int));
	listsets[2] = initlist(set3, sizeof(set2)/sizeof(int));
	listsets[3] = initlist(set4, sizeof(set2)/sizeof(int));

	int i = 0;
	for(i = 0; i < 4; i++)
	{
		printf("list %d: ", i);
		printlist(listsets[i]);
	}

	struct ListNode *res = mergeKLists(listsets, 4);
	printf("after merge list: ");
	printlist(res);
}	
