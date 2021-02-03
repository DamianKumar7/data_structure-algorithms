#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
} node;

void insertAtBegin(node **head, int data);
void insertAtEnd(node **head, int data);
void insertAtPos(node **head, int pos, int data);
void insertAfterANode(node **head, int key, int data);
void display(node *head);
void deleteNode(node **head, int data);
void deleteLastNode(node **head);
void deleteFirstNode(node **head);
void reverse(node **head);
int search(node *head, int key);

int main()
{
	int choice, data, pos, key;
	node *head = NULL;

	while(1)
	{
		printf("Enter\t(1) Insert at begin\n\t(2) Insert at end\n\t(3) Insert at any position\n\t");
		printf("(4) Insert after a node\n\t(5) Display\n\t(6) Delete a node\n\t(7) Delete first node\n\t");
		printf("(8) Delete last node\n\t(9) Search\n\t(10) Reverse the list\n\t(0) Exit\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
		case 1: 
			printf("Enter a value to insert: ");
			scanf("%d", &data);
			insertAtBegin(&head, data);
			break;
		case 2: 
			printf("Enter a value to insert: ");
			scanf("%d", &data);
			insertAtEnd(&head, data);
			break;
		case 3: 
			printf("Enter the position: ");
			scanf("%d", &pos);
			printf("Enter a value to insert: ");
			scanf("%d", &data);
			insertAtPos(&head, pos, data);
			break;
		case 4:
			printf("Enter the node data after which you want to insert: ");
			scanf("%d", &key);
			printf("Enter the value to insert: ");
			scanf("%d", &data);
			insertAfterANode(&head, key, data);
			break;		
		case 5: 
			display(head);
			break;		
		case 6:
			printf("Enter the item to delete: ");
			scanf("%d", &data);
			deleteNode(&head, data);
			break;
		case 7:
			deleteFirstNode(&head);
			break;
		case 8:
			deleteLastNode(&head);
			break;
		case 9:
			printf("Enter the item to search: ");
			scanf("%d", &data);
			pos = search(head, data);
			if(pos != -1)
				printf("Item found at %d position\n", pos);
			else
				printf("Item not found\n");
			break;
		case 10:
			reverse(&head);
			break;
		case 0: 
			exit(0);
		default:
			printf("Invalid Input\n");
		}
	}
	return 0;
}


void insertAtBegin(node **head, int data)
{
	node *temp, *newnode;

	temp = *head;
	newnode = (node *)malloc(sizeof(node));
	newnode->data = data;

	if(temp == NULL)
		newnode->next = NULL;
	else
		newnode->next = temp;
	*head = newnode;
}
void insertAtEnd(node **head, int data)
{
	node *temp, *newnode = (node*)malloc(sizeof(node));
	temp = *head;
	newnode->data = data;
	newnode->next = NULL;
	if(*head == NULL)
		*head = newnode;
	else		
	{
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}
}

void insertAtPos(node **head, int pos, int data)
{
	node *temp, *newnode = (node*)malloc(sizeof(node));
	int count = 1;
	newnode->data = data;
	temp = *head;
	if(pos == 1)
		insertAtBegin(head, data);
	else
	{
		while(count != pos-1 && temp->next != NULL)
		{
			temp = temp->next;
			count++;
		}
		if(temp->next == NULL)
			insertAtEnd(head, data);
		else
		{
			newnode->next = temp->next;
			temp->next = newnode;
		}
	}
}

void insertAfterANode(node **head, int key, int data)
{
	node *temp, *newnode = (node*)malloc(sizeof(node));
	int pos = search(*head, key) + 1;
	newnode->data = data;
	temp = *head;
	if(*head == NULL)
	{
		printf("List is Empty\n");
		return;
	}
	else
		insertAtPos(head, pos, data);
}

void deleteNode(node **head, int data)
{
	node *curr, *prev;
	prev = curr = *head;
	if(*head == NULL)
	{
		printf("List is Empty\n");
		return;
	}
	if(curr->data == data && curr->next == NULL)
	{
		*head = NULL;
		return;
	}
	else if(curr->data == data && curr->next != NULL)
	{
		*head = curr->next;
		return;
	}
	else
	{
		while((prev->next)->data != data && (prev->next)->next != NULL)
			prev = prev->next;
		while(curr->data != data && curr->next != NULL)
			curr = curr->next;
		if(curr->data == data && curr->next == NULL)
			prev->next = NULL;
		else if(curr->data == data && curr->next != NULL)
			prev->next = curr->next;
		else if(curr->data != data)
			printf("Node Not Found\n");
	}
}

void deleteFirstNode(node ** head)
{
	node *temp;
	temp = *head;
	if(*head == NULL)
		printf("List is Empty\n");
	else if(temp->next == NULL)
		*head = NULL;
	else
		*head = temp->next;
}

void deleteLastNode(node **head)
{
	node *temp;
	temp = *head;
	if(*head == NULL)
	{
		printf("List is Empty\n");
		return;
	}
	else if(temp->next == NULL)
		*head = NULL;
	else
	{
		while((temp->next)->next != NULL)
			temp = temp->next;
		temp->next = NULL;
	}
}

void reverse(node **head)
{
 	node *prev, *next, *curr; 
	prev = next = NULL;
	curr = *head; 
	while (curr != NULL) 
	{ 
		next = curr->next; 
		curr->next = prev; 
		prev = curr; 
		curr = next; 
	} 
	*head = prev;
}
			                                                                 
											 
int search(node *head, int key)
{
	node *temp;
	int c = 1;
	if(head == NULL)
		return -1;
	else
	{
		temp = head;
		while(temp->data != key && temp->next != NULL)
		{
			c++;
			temp = temp->next;
		}
		if(temp->data == key)
			return c;
		else
			return -1;
	}
}

void display(node *head)
{
	node *temp;
	if(head == NULL)
		printf("NO Node\n");
	else
	{
		temp = head;
		while (temp != NULL)
		{
			printf(" %d ", temp->data);
			temp = temp->next;
		}
	}
	printf("\n");
}