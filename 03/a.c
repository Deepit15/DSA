#include<stdio.h>
#include<stdlib.h>

typedef struct snode
{
	int data;
	struct snode *link;
}snode;

typedef struct dnode
{
	snode *rlink;
	struct dnode *dlink;
}dnode;

struct dnode *dhead;


void createdll()
{
	int i=0,j=0;
	char choice='y';
	dnode *dtemp,*dptr;
	snode *stemp,*sptr;
	dtemp=dhead;
	while(choice=='y' || choice=='Y')
	{
		j=0;
		while(choice=='y' || choice=='Y')
		{
			sptr=(snode *)malloc(sizeof(snode));
			if(sptr==NULL)
			{
				printf("\nMemory allocation failed.");
			}
			printf("\nEnter the data:");
			scanf("%d",&sptr->data);
			sptr->link=NULL;
			if(dtemp->rlink==NULL)
			{
				printf("\n[%d][%d] :",i,j);
				dtemp->rlink=sptr;
			}
			else
			{
				printf("\n[%d][%d] :",i,j);
				stemp->link=sptr;
			}
			stemp=sptr;
			printf("\nDo you want to add any more columns(y/n): ");
			fflush(stdin);
			scanf(" %c",&choice);
			j+=1;
		}
		dptr=(dnode *)malloc(sizeof(dnode));
		if(dptr==NULL)
		{
			printf("\nMemory allocation failed.");
		}
		dptr->dlink=NULL;
		dtemp->dlink=dptr;
		dtemp=dptr;
		printf("\nDo you want to add any more rows(y/n): ");
		fflush(stdin);
		scanf(" %c",&choice);
		i+=1;
	}
}


void display()
{
	int i,j;
	dnode *dtemp;
	snode *stemp;
	dtemp=dhead;
	if(dtemp->rlink==NULL && dtemp->dlink==NULL)
	{
		printf("\nList is Empty.");
	}
	else
	{
		while(dtemp!=NULL)
		{
			stemp=dtemp->rlink;
			printf("\n");
			while(stemp!=NULL)
			{
				printf(" %d\t",stemp->data);
				stemp=stemp->link;
			}
			dtemp=dtemp->dlink;
		}
	}
}

int main()
{
	int choice;
	dhead=(dnode *)malloc(sizeof(dnode));
	dhead->dlink=NULL;
	dhead->rlink=NULL;
	while(1)
	{
		printf("\n 1.Create 2-D matrix\n 2.Display Matrix\n 3.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				createdll();
				break;
			case 2:
				display();
				break;
			case 3:
				exit(0);
			default:
				printf("\nInvalid Input !!\n Try Again !!");
		}
	}
	return 0;
}

