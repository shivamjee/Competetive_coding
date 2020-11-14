#include<stdlib.h>
#include<stdio.h>


typedef struct node
{
	int data;
	struct node *next;
}*NODE;

NODE insertLL(NODE head, int data)
{
	NODE temp = (NODE) malloc(sizeof(struct node));	
	temp->next = NULL;
	temp->data = data;
	if(head == NULL)
		return temp;
	NODE tempHead = head;
	while(tempHead->next != NULL)
		tempHead = tempHead->next;
	tempHead->next = temp;
	return head;

}
void printLL(NODE head)
{
	NODE tempHead = head;
	while(tempHead!= NULL)
	{
		printf("%d->",tempHead->data);
		tempHead = tempHead->next;
	}

}
int findMid(NODE head)
{
	NODE headSlow = head;
	NODE headFast = head;
	while(headFast != NULL && headFast->next != NULL)
	{
		headSlow = headSlow->next;
		headFast = headFast->next;
		headFast = headFast->next;
	}
	return headSlow->data;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		NODE head = (NODE) malloc(sizeof(struct node));
		head = NULL;
		int n,i,data;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&data);
			head = insertLL(head,data);
		}
		printf("%d\n",findMid(head));
		//printLL(head);
	}
}