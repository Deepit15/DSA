#include <stdio.h>
#include <stdlib.h>

typedef  struct node {
	struct node *dlink;
	struct data *rlink;
}node;

typedef struct data{
	int data;
	struct data *link;
}data;

struct node *head;

int create()
{
	char row_choice='y',col_choice='y';
	int val;
	data *dptr,*dtemp;
	node *nptr,*ntemp;
	ntemp=head;
   	
   	
	while(col_choice=='y')
	{
    	printf("Do you want to enter more data in the current row \n(Enter 'y' for yes ) : ");
		scanf(" %c",&row_choice);
    	while(row_choice=='y')
    	{
    		dptr=(node *)malloc(sizeof(node));
    		if(dptr==NULL)
			{
				printf("\nMemory allocation failed.");
			}
    		printf("\nEnter the value : ");
			scanf("%d",&dptr->data);
			if(ntemp->rlink == NULL)
			{
				ntemp->rlink=dptr;
			}
			else
			{			
				dtemp->link=dptr;
			}
			dtemp=dptr;
			printf("Do you want to enter more data in the current row \n(Enter 'y' for yes ) : ");
			scanf(" %c",&row_choice);
		}
		nptr=(node *)malloc(sizeof(node));
		if(nptr==NULL)
		{
			printf("\nMemory allocation failed.");
		}
		nptr->dlink=NULL;
		ntemp->dlink=nptr;
		ntemp=nptr;
		printf("Do you want to enter more data in the current column \n(Enter 'y' for yes ) : ");
		scanf(" %c",&col_choice);
		
		
	}
	return 0;
}

int display()
{
	node *ntemp;
	data *dtemp;
	ntemp =head;
	if(ntemp->rlink==NULL && ntemp->dlink==NULL)
	{
		printf("\n List is empty");
	}
	else
	{
		while(ntemp!=NULL)
		{
			dtemp=ntemp->rlink;
			printf("\n");
			while(dtemp!=NULL)
			{
				printf(" %d\t",dtemp->data);
				dtemp=dtemp->link;
			}
			ntemp=ntemp->dlink;
		}
	}
	return 0;
}

int main()
{
	int choice;   
    while(choice != 5)   
    { 
    	system("cls");
        printf("\n1.create a matrix\n2.display the matrix\nEnter your choice ? : ");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:
            { 
            
            	create();
			    break; 
			}
            case 2: 
			{
				display();
				sleep(2);
	            break; 
			 } 
           default:   
            printf("\nEnter valid choice??\n");  

            
        }  
    }
	return 0;  
}  
