/**********************************************************************
Program: Daily 6B
Author: Shreya Mishra
Date: Feb. 11th, 2023
Time spent: 4 hours
Purpose: The purpose of this program is to sum the numbers in 2 link lists.
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
void head_insert(Node** head, int val);
Node* list_sum(Node* head1, Node* head2);
void print_list(Node* head);
void destroy_list(Node* head);

int main(int argc, char* argv[])
{
	//add up 189 + 11
	Node* head1 = NULL;
	Node* head2 = NULL;
	Node* head_sum = NULL;

	//create a list for the number 189
	head_insert(&head1, 9);
	head_insert(&head1, 8);
	head_insert(&head1, 1);

	//create a list for the number 11
	head_insert(&head2, 1);
	head_insert(&head2, 1);
    
	head_sum = list_sum(head1, head2);
	
	printf("The sum of ");
	print_list(head1);
	printf(" + ");
	print_list(head2);
	printf("\n");
	printf(" = ");
	print_list(head_sum);
	printf("\n");

	//clean up three lists
	destroy_list(head1); head1 = NULL;
	destroy_list(head2); head2 = NULL;
	destroy_list(head_sum); head_sum = NULL;
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

void head_insert(Node** head, int val){
	Node* temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = val;
		temp->next = *head;
		*head = temp;
}

Node* list_sum(Node* head1, Node* head2){
    
	Node* temp1= head1;
	reverse_list(&temp1);
	Node* t1=temp1;


	Node* temp2 = head2;
	reverse_list(&temp2);
	Node* t2=temp2;

	Node* result = NULL;
	int carry=0, sum=0, val=0;

	while (temp1 || temp2 ){
		sum = carry;
		if (temp1)
			sum += temp1->data;
		if (temp2)
			sum += temp2->data;

		val = sum % 10;
		carry = sum /10;

		head_insert(&result, val);
		
		if (temp1)
		    temp1= temp1->next;
		if (temp2)
		    temp2 = temp2->next;
	};
	if (carry > 0) {
	    head_insert(&result, carry);
	}
    reverse_list(&t1);
    reverse_list(&t2);
	return result;

}

void print_list(Node* head){
	Node* temp = head;
	while (temp != NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
}

void destroy_list(Node* head){
	Node* temp = head;
	while (temp != NULL)
	{ 
		head = temp->next;
		free(temp);
		temp=head;
	}
}
