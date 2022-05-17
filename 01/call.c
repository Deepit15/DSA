#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "stack_link.h"
#include "stack_array.h"

int main()
{
	int m_choice,choice,next=1;
	main:
	system("cls");
	printf("1. To perform stack operation using array \n2. To perform stack operation using linklist\n3. Exit \nEnter your choice:- ");
	scanf("%d",&m_choice);
	if(m_choice==1)
	{
		system("cls");
		int arr[30];
		int top=-1;
		while(next==1)
		{
			printf("---------------------------------");
			printf("\nPerforming operation using array\n");
			printf("---------------------------------");
			printf("\n1. Push \n2. Pop \n3. Display \n4. Main Menu \n5. Exit \nEnter your choice:- ");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					arr_push(&top,arr);
					break;
				case 2:
					arr_pop(&top,arr);
					break;
				case 3:
					arr_display(&top,arr);;
					break;
				case 4:
					goto main;
				case 5:
					exit(0);
				default:
					printf("Wrong input");
			}
			printf("\n\nDo you want to perform more operations?\n 1 to perform more operations\n 2 to exit\n");
			scanf("%d",&next);
			system("cls");
		}
		goto main;
	}
	else if(m_choice==2)
	{
		system("cls");
		while(next==1)
		{
			printf("---------------------------------");
			printf("\nPerforming operation using linklist\n");
			printf("---------------------------------");
			printf("\n1. Push \n2. Pop \n3. Display \n4. Main Menu \n5. Exit \nEnter your choice:- ");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					link_push();
					break;
				case 2:
					link_pop();
					break;
				case 3:
					link_display();
					break;
				case 4:
					goto main;
				case 5:
					exit(0);
				default:
					printf("Wrong input");
			}
			printf("\n\nDo you want to perform more operations?\n 1 to perform more operations\n 2 to exit\n");
			scanf("%d",&next);
			system("cls");
		}	
		goto main;	
	}
	else
	{
		exit(0);
	}
	
	
	return 0;
}

