#include <stdio.h>
#include <conio.h>

struct inv
{
	int part_no;
	int qnty;
}qnty[100];


int modulo(int p,int q,int col)
{
	int result=1,rem;
	rem=p%100;
	while(result!=0)
	{
		if(qnty[rem].part_no==0)
		{
			qnty[rem].part_no=p;
			qnty[rem].qnty=q;
			result=0;
		}
		else if(rem==99)
		{
			rem=0;
		}
		else
		{
			col++;
			rem++;
		}
	}
	return col;
	
}

int search(int n)
{
	int i,max,count=0,a;
	max=100;
	for(i=n%100;i<max;i++)
	{
		if(qnty[i].part_no==n)
		{
			printf("\nPart no : %d",qnty[i].part_no);
			printf("\nThe quantity sold is %d",qnty[i].qnty);
			return 1;
		}
		if(i==99 && count==0)
		{
			i=-1;
			count=1;
			max=n%100;
		}
	}
	printf("\nItem not found");
	return 0;
}

int display(int col)
{
	int i;
	printf("\n-----------------------------------");
	printf("\nS_no\tPArt Number\tQuantity");
	printf("\n-----------------------------------");
	for(i=0;i<100;i++)
	{
		printf("\n%d\t%d\t\t%d",i,qnty[i].part_no,qnty[i].qnty);
	}
	printf("\nTotal number of collision : %d",col);
	return 0;
}

void main()
{
	int ch,qnty,p_no,col,ret;
	while(1)
	{
		system("cls");
		printf("1. Add Data\n2. Display\n3. Search\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					printf("\nEnter the item part number");
					repart:
					scanf("%d",&p_no);	
					if(p_no<0)
					{
						printf("\nRe-Enter the item part number");
						goto repart;
						}	
					printf("\nEnter the item quantity");
					scanf("%d",&qnty);
					col = modulo(p_no,qnty,col);
					break;
				}
			case 2:
				{
					display(col);
					sleep(5);
					break;	
				}
			case 3:
				{
					printf("\nEnter the item part number you want to search");
					scanf("%d",&p_no);
					search(p_no);
					sleep(3);
					break;
					
				}
			default:
				printf("Wrong input");
		}
	}
}
