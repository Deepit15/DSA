#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int arr_push(int *top,int *arr)
{
	int val;
	printf("Enter the value : ");
	scanf("%d",&val);
	if(*top==29)
	{
		printf("Stack overflow!!");
	}
	else
	{
		*top+=1;
		arr[*top]=val;
		
	}
		printf("Value pushed");
	
	return 0;
}

int arr_pop(int *top,int *arr)
{
	if (*top == -1)
	{
		printf("Underflow");
	}
	else
	{
		printf("%d is the value\n",arr[*top]);
		*top-=1;
		printf("Item popped");
	}
	return 0;
}

int arr_display(int *top,int *arr)
{
	printf("Values of array are:-\n");
	if(*top==-1)
	{
		printf("Stack is empty");
	}
	else
	{
		while(*top>-1)
		{
			printf("%d\n",arr[*top]);
			*top-=1;
		}
	}
	return 0;
}

int main()
{
	int choice,arr[30],next=1;
	int top=-1;
	while(next==1)
	{
		printf("Enter your choice:- \n1. Pop \n2. Push \n3. Display \n4. Exit \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				arr_pop(&top,arr);
				break;
			case 2:
				arr_push(&top,arr);
				break;
			case 3:
				arr_display(&top,arr);;
				break;
			case 4:
				exit(0);
			default:
				printf("Wrong input");
		}
		printf("\n\nDo you want to perform more operations?\n 1 to perform more operations\n 2 to exit\n");
		scanf("%d",&next);
		system("cls");
	}
	
	return 0;
}
