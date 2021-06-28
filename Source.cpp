//Write a function that counts the number of times a given int occurs in a Linked List
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Node
{
	int data;
	struct Node *next;
};
void printList(struct Node *head_ref)
{
	while (head_ref != NULL)
	{
		printf(" %d ", head_ref->data);
		head_ref = head_ref->next;
	}
}
Node* append(struct Node *head_ref, int new_data)
{
	struct Node *temp = head_ref;
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;

	if (temp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = head_ref;
		head_ref = new_node;
	}
	return head_ref;
}
int frequency_node(struct Node *head_ref, int value)
{
	int counter = 0;
	while (head_ref != NULL)
	{
		if (head_ref->data == value)
			counter++;
		head_ref = head_ref->next;
	}
	return counter;
}
void main()
{
	struct Node *head = NULL;
	head = append(head, 4);
	head = append(head, 5);
	head = append(head, 2);
	head = append(head, 8);
	head = append(head, 5);
	head = append(head, 10);
	head = append(head, 9);
	head = append(head, 1);
	head = append(head, 12);
	head = append(head, 5);
	head = append(head, 10);
	printList(head);
	int count = frequency_node(head, 10);
	printf("\nFrequency of node 10 is %d", count);
	_getch();
}