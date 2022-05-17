#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 30

typedef struct mobile{
	char Model[MAX],Brand[MAX];
	int Memory;
	float Price;
	struct mobile *link;
}mobile;

struct mobile *head=NULL;

void create()
{
	mobile *ptr,*temp;
	ptr= (mobile *)malloc(sizeof(mobile));
	printf("Enter the mobile name:");
	scanf(" %s",&ptr->Model);
	fflush(stdin);
	printf("Enter the brand name:");
	scanf("%s",&ptr->Brand);
	fflush(stdin);
	printf("Enter the memory capacity:");
	scanf("%d",&ptr->Memory);
	fflush(stdin);
	printf("Enter the mobile price:");
	scanf("%f",&ptr->Price);
	ptr->link=NULL;
	if(head==NULL)
	{
//		head=NULL;
		head=ptr;
//		ptr->link=NULL;
	}
	else{
		temp=head;
		while(temp->link!=NULL)
		{
			temp = temp->link; 
		}
		temp->link = ptr;
		
	}
//	temp=ptr;
//	free(ptr);
}

void display()
{
	mobile *ptr;
	ptr = head;
	if(ptr==NULL)
	{
		printf("Empty list");
	}
	else{
		while(ptr!=NULL)
		{
			printf("%s\t%s\t%d\t%f",ptr->Model,ptr->Brand,ptr->Memory,ptr->Price);
			ptr=ptr->link;
		}
		
	}
}

void sort_brand()
{
	int i,j,count,swapflag;
	count=size();
	mobile *otemp,*itemp1,*itemp2,temp;
	for(i=0;i<=count;i+=1)
	{
		otemp=head;
		swapflag=0;
		for(j=0;j<count-i-1;j+=1)
		{
			itemp1=otemp;
			itemp2=otemp->link;
			if(strcmp(itemp1->Brand,itemp2->Brand)>0)
			{
				strcpy(temp.Brand,itemp1->Brand);
				strcpy(temp.Model,itemp1->Model);
				temp.Memory=itemp1->Memory;
				temp.Price=itemp1->Price;
				
				strcpy(itemp1->Brand,itemp2->Brand);
				strcpy(itemp1->Model,itemp2->Model);
				itemp1->Memory=itemp2->Memory;
				itemp1->Price=itemp2->Price;
				
				strcpy(itemp2->Brand,temp.Brand);
				strcpy(itemp2->Model,temp.Model);
				itemp2->Memory=temp.Memory;
				itemp2->Price=temp.Price;
			}
			otemp=otemp->link;
		}
	}
}

int size()
{
	mobile *temp;
	int size=0;
	temp=head;
	while(temp!=NULL)
	{
		temp=temp->link;
		size+=1;
	}
	return size;
}
	
void sort_price()
{
	int i,j,count;
	count=size();
	mobile *otemp,*itemp1,*itemp2,temp;
	for(i=0;i<=count;i+=1)
	{
		otemp=head;
		for(j=0;j<count-i-1;j+=1)
		{
			itemp1=otemp;
			itemp2=otemp->link;
			if(itemp1->Price > itemp2->Price)
			{
				strcpy(temp.Brand,itemp1->Brand);
				strcpy(temp.Model,itemp1->Model);
				temp.Memory=itemp1->Memory;
				temp.Price=itemp1->Price;
				
				strcpy(itemp1->Brand,itemp2->Brand);
				strcpy(itemp1->Model,itemp2->Model);
				itemp1->Memory=itemp2->Memory;
				itemp1->Price=itemp2->Price;
				
				strcpy(itemp2->Brand,temp.Brand);
				strcpy(itemp2->Model,temp.Model);
				itemp2->Memory=temp.Memory;
				itemp2->Price=temp.Price;
			}
			otemp=otemp->link;
		}
	}
}


int main()
{
	int choice;
	while(1)
	{
		printf("\n 1.Add mobile\n 2.Display\n 3.Sort by brand\n4. Sort by price\n5. Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				sort_brand();
				break;
			case 4:
				sort_price();
				break;
//			case 5:
//				Exit(0);
			default:
				printf("\nInvalid Input !!\n Try Again !!");
		}
	}
	return 0;
}
