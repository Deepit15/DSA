#include <stdio.h>
#include <conio.h>
#define MAX 30
int c=1,n;
int create(int *arr)
{
	int i;
	printf("Enter the number of elements in the array : ");
	c++;
	scanf("%d",&n);
	c++;
	printf("Enter the value of the array : ");
	c++;
	for(i=0;i<n;i++)
	{
		c++;
		scanf("%d",&arr[i]);
		c++;
	}
	c++;
}

void replace(int *arr,int n,int *new)
{
	int i,j,count=0,temp=0;
	c++;
	c++;
	for(i=0;i<n;i++)
	{
		c++;
		count=0;
		c++;
		for(j=0;j<n;j++)
		{
			c++;
			if((arr[i]==arr[j]) && (i!=j))
			{
				c++;
				c++;
				count=1;
				break;
			}
		}
		c++;
		if(count==0)
		{
			c++;
			c++;
			new[temp]=arr[i];
			c++;
			temp+=1;
		}
	}
	c++;
	for(i=(temp);i<(n);i++)
	{
		c++;
		c++;
		new[i]=0;
	}
	c++;
}

void display(int *new)
{
	int i;
	for(i=0;i<n;i++)
	{
		c++;
		c++;
		printf("%d ",new[i]);
	}
	c++;
}

void main()
{
	int arr[MAX],new[MAX];
	create(arr);
	c++;
	replace(arr,n,new);
	c++;
	display(new);
	c++;
	c++;
	printf("\nThe time complexity is %d",c);
}
