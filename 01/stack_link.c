#include <stdio.h>
#include <conio.h>

struct node{
	int data;
	struct node *link;
};

struct node *head;

int link_push()
{
	int val;
	struct node *ptr = (struct node*)malloc(sizeof(struct node));  
	if(ptr==NULL)
	{
		printf("Error!! while pushing the value");
	}
	else
	{
		printf("Enter the value : ");
		scanf("%d",&val);
		if(head==NULL)
		{
			ptr->data = val;
			ptr->link = NULL;
			head = ptr;
		}
		else
		{
			ptr->data = val;
			ptr->link = head;
			head = ptr;
		}
		printf("Value pushed");
	}
	return 0;
}

int link_pop()
{
	int val;
	struct node *ptr;
	if (head == NULL)
	{
		printf("Underflow");
	}
	else
	{
		printf("%d is the value\n",head->data);
		ptr = head;
		head=head->link;
		free(ptr);
		printf("Item popped");
	}
	return 0;
}

int link_display()
{
	struct node *ptr;
	ptr=head;
	printf("Values of array are:-\n");
	if(head==NULL)
	{
		printf("Stack is empty");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr = ptr->link;
		}
	}
	return 0;
}

int main()
{
	int choice,next;
	while(next==1)
	{
		printf("Enter your choice:- \n1. Pop \n2. Push \n3. Display \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				pop();
				break;
			case 2:
				push();
				break;
			case 3:
				display();
				break;
			default:
				printf("Wrong input");
		}
		printf("\n\nDo you want to perform more operations?\n 1 to perform more operations\n 2 to exit\n");
		scanf("%d",&next);
		system("cls");
	}
	
	return 0;
}
