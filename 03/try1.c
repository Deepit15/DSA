#include <stdio.h>
#include <conio.h>

struct node {
	struct node *dlink;
	struct data *rlink;
};

struct data{
	int data;
	struct data *link;
};
struct node *head;

void create()
{
	char row_choice='y',col_choice='y';
	int val;
	struct data *ptr1;
	struct node *ptr;
	struct data *temp;
	while(col_choice=='y')
	{
		ptr = (struct node *) malloc (sizeof(struct node));
    	row_choice='y';
    	while(row_choice=='y')
    	{
//    		temp = (struct data *) malloc (sizeof(struct data));
   			ptr1 = (struct data *) malloc (sizeof(struct data));
    		printf("\nEnter the value : ");
			scanf("%d",&val);
			if(head == NULL)
			{
				ptr1->data = val;
				ptr->dlink = NULL;
				ptr->rlink = ptr1;
				head= ptr;
			}
			else
			{			
				temp = ptr->rlink;
				while(temp!= NULL)
				{
					temp = temp->link;
				}
				ptr1->data = val;
				temp->link = ptr1;
			}
			printf("Do you want to enter more data in the current row \n(Enter 'y' for yes ) : ");
			scanf(" %c",&row_choice);
		}
		printf("Do you want to enter more data in the current column \n(Enter 'y' for yes ) : ");
		scanf(" %c",&col_choice);
		
		
	}
	return 0;
}

