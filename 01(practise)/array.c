#include <conio.h>
#include <stdio.h>
#define MAX 30	
int a[MAX],n,i;

int swap(int x,int y)
{
	a[x-1]+=a[y-1];
	a[y-1]=a[x-1]-a[y-1];
	a[x-1]=a[x-1]-a[y-1];
	return 0;
}

void print()
{
	for(i=0;i<n;i++)
	{
		printf("\nEnter %d value of the array is %d \n",i+1,a[i]);
	}
}

void create()
{
	printf("Enter the number of elements in the array : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter %d value of the array : ",i+1);
		scanf("%d",&a[i]);
	}
}

void main()
{
	int x,y;
	create();
	printf("Enter the first index that you want to swap : ");
	scanf("%d",&x);
	printf("Enter the second index that you want to swap : ");
	scanf("%d",&y);
	swap(x,y);
	print();
	
}
