#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class node{
public:
	int data;
	node* next;
};

node* insertLL(node* head,int data)
{
	node* temp = NULL;
	temp =new node();
	temp->data = data;
	temp->next = NULL;

	if(head == NULL)
		return temp;
	node* curr = head;
	while(curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	return head;
}

int findMiddle(node* head)
{
	cout<< head->data;
	node* slowHead = head;
	node* fastHead = head;
	while(fastHead != NULL && fastHead->next != NULL)
	{
		slowHead = slowHead->next;
		fastHead = fastHead->next;
		fastHead = fastHead->next;
	}
	return slowHead->data;
}
void printLL(node* head)
{
	node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
}

int getRank(node* head, int attempt)
{
	if(attempt>head->data)
	{
		node* temp = new node();
		temp->data = attempt;
		temp->next = head;
		head = temp;
		return 1;
	}


	int count = 0;
	node* prev = head;
	node* curr = head;
	while(curr != NULL)
	{
		count ++;
		if(attempt>curr->data)
		{
			node* temp = new node();
			temp->data = attempt;
			temp->next = NULL;
			prev->next = temp;
			temp->next = curr;
			return count;

		}
		else if(attempt == curr->data)
			return count;
		prev = curr;
		curr = curr->next;
	}
	node* temp = new node();
	temp->data = attempt;
	temp->next = NULL;
	prev->next = temp;
	return count+1;
}

int main()
{
	node* head = new node();
	head = NULL;

	int players,tries;

	cin>> players;

	for(int i =0;i<players;i++)
	{
		int data;
		cin >> data;
		head = insertLL(head,data);
	}

	cin>> tries;

	for(int i =0;i<tries;i++)
	{
		int attempt;
		cin >> attempt;
		cout << getRank(head,attempt)<<" ";

	}
	//printLL(head);

	//int midVal = findMiddle(head);
	//cout<< "The middle term is "<< midVal << endl;
	return 0;

	
}