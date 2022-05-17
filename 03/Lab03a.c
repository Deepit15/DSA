#include<stdio.h>
#include<stdlib.h>

typedef struct snode
{
	int data;
	struct snode *link;
}snode;

snode *head;

void creates()
{
	snode *temp,*ptr;
	char ch='y';
	if(ptr==NULL)
	{
		printf("\nMemory allocation for single linked list failed.");
	}
	while(ch=='y' || ch=='Y')
	{
		ptr = (snode *)malloc(sizeof(snode));
		system("cls");
		printf("\nEnter the data:");
		scanf("%d",&ptr->data);
		temp=head;
		if(head==NULL)
		{
			ptr->link=NULL;
			head=ptr;
		}
		else
		{
			while(temp->link!=NULL)
			{
				temp=temp->link;
			}
			temp->link=ptr;
			ptr->link=NULL;
		}
		printf("\nDo you want to enter more elements:");
		scanf(" %c",&ch);
	}
}

void deletes()
{
	snode *temp,*ptr;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data<0)
		{
			ptr=temp->link;
			temp->link=ptr->link;
			free(ptr);
		}
		temp=temp->link;
	}
	printf("Next items deleted");
}

void displays()
{
	snode *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("\t%d",temp->data);
		temp=temp->link;
	}
}


int main()
{
	int choice;
	while(1)
	{
		system("cls");
		printf("\n 1.Add/Create\n 2.Delete after negative\n 3.Display list\n 4.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				creates();
				break;
			case 2:
				deletes();
				sleep(1);
				break;
			case 3:
				displays();
				sleep(2);
				break;
			case 4:
				exit(0);
			default:
				printf("\nInvalid Input !!\n Try Again !!");
		}
	}
	return 0;
}
