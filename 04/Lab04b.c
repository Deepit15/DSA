#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

typedef struct mobile
{
	char model[MAX],brand[MAX];
	int memcap;
	float price;
	struct mobile *link;
}mobile;

mobile *head;


void add()
{
	mobile *temp,*ptr;
	char choice='y';
	while(choice=='y' || choice=='Y')
	{
		system("cls");
		ptr=(mobile *)malloc(sizeof(mobile));
		if(ptr==NULL)
		{
			printf("\nMemory Allocation Failed.");
		}
		printf("\nEnter Model:");
		scanf("%s",ptr->model);
		printf("\nEnter Brand Name:");
		scanf("%s",ptr->brand);
		printf("\nEnter Memeory:");
		scanf("%d",&ptr->memcap);
		printf("\nEnter Price:");
		scanf("%f",&ptr->price);
		ptr->link=NULL;
		if(head==NULL)
		{
			head=ptr;
		}
		else
		{
			temp=head;
			while(temp->link!=NULL)
			{
				temp=temp->link;
			}
			temp->link=ptr;
		}
		printf("\nDo you want to add more(y/n):");
		scanf(" %c",&choice);
	}
}

void display()
{
	mobile *temp;
	int i=1;
	temp=head;
	if(head==NULL)
	{
		printf("\nEmpty List.");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("\n\n%d.Model:%s",i,temp->model);
			printf("\n%d.Brand:%s",i,temp->brand);
			printf("\n%d.Memory Capacity:%d",i,temp->memcap);
			printf("\n%d.Price:%2f",i,temp->price);
			temp=temp->link;
			i+=1;
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


void brandsort()
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
			if(strcmp(itemp1->brand,itemp2->brand)>0)
			{
				strcpy(temp.brand,itemp1->brand);
				strcpy(temp.model,itemp1->model);
				temp.memcap=itemp1->memcap;
				temp.price=itemp1->price;
				
				strcpy(itemp1->brand,itemp2->brand);
				strcpy(itemp1->model,itemp2->model);
				itemp1->memcap=itemp2->memcap;
				itemp1->price=itemp2->price;
				
				strcpy(itemp2->brand,temp.brand);
				strcpy(itemp2->model,temp.model);
				itemp2->memcap=temp.memcap;
				itemp2->price=temp.price;
			}
			otemp=otemp->link;
		}
	}
//	display();
}


void pricesort(struct mobile** start, int count)
{
	struct mobile** h,*itemp1,*itemp2,temp;
    int i, j;
    for (i = 0; i <= count; i++)
    {
        h = start;
//        swapped = 0;
        for (j = 0; j < count - i - 1; j++) 
        {
            itemp1 = *h;
            itemp2 = itemp1->link;
            if (itemp1->price > itemp2->price )
            {
                strcpy(temp.brand,itemp1->brand);
				strcpy(temp.model,itemp1->model);
				temp.memcap=itemp1->memcap;
				temp.price=itemp1->price;
				
				strcpy(itemp1->brand,itemp2->brand);
				strcpy(itemp1->model,itemp2->model);
				itemp1->memcap=itemp2->memcap;
				itemp1->price=itemp2->price;
				
				strcpy(itemp2->brand,temp.brand);
				strcpy(itemp2->model,temp.model);
				itemp2->memcap=temp.memcap;
				itemp2->price=temp.price;
            }
            h = &(*h)->link;
        }
    }
//	display();
}

void brandprice()
{
	int count;
	mobile *temp=NULL,*start=NULL;
	brandsort();
	temp=head;
	while(temp->link!=NULL)
	{
		printf("\nin 1 while\n");
		start=temp;
		count=1;
		if(strcmp(temp->brand,temp->link->brand)==0)
		{
			while(temp->link!=NULL && strcmp(temp->brand,temp->link->brand)==0)
			{
				printf("\nin 2 while\n");
				count++;
				printf("\nCount = %d \n",count);
				temp=temp->link;	
			}
		}
		if(count>1)
		{
			printf("\nin if\n");
			pricesort(&start,count);
			display();
			printf("\nend of if\n");
		}
		else
		{
			temp=temp->link;
		}
	}
	display();
}



int main()
{
	int choice,count;
	while(1)
	{
		printf("\n\n 1.ADD mobile details\n 2.Sort based on brand\n 3.Sort based on price\n 4.Sort based on price and brand\n 5.Display list\n 6.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				add();
				break;
			case 2:
				brandsort();
				break;
			case 3:
				count=size();
				pricesort(&head,count);
				break;
			case 4:
				brandprice();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
			default:
				printf("\nInvalid Input !!\nTry Again !!");
		}
	}
	return 0;
}
