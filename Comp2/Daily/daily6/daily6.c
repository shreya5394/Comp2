/**********************************************************************
Program: Day 6 starter
Author: Shreya Mishra
Date: Feb. 4th, 2023
Time spent: 3 hours
Purpose: The purpose of this program is to reverse a link list.
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

//declare your function here.
void reverse_list(Node** next);

int main(int argc, char* argv[])
{
	Node* head = NULL;
	int i;
	Node* temp;

//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}

//call your function to reverse the list (should work for any list given the head node pointer).
reverse_list(&head);

//print the reversed list.
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	return 0;
}

//Define your function here
void reverse_list(Node** head){
	Node* c=NULL;
	Node* p=NULL;
	Node* n=NULL;

	c = *head;
	while (c != NULL) {
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	*head = p;
}