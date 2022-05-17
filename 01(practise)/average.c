#include <conio.h>
#include<stdio.h>
#include<math.h>
#define MAX 30
int arr[MAX],n;
float avg[MAX][MAX];

void create()
{
	int i;
	printf("Enter the number of elements in the array : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter %d value of the array : ",i+1);
		scanf("%d",&arr[i]);
	}
}

int average()
{
	int i,j,x;
	float sum=0,s=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			
			if(i<=j)
			{
				for(x=i;x<=j;x++)
				{
					sum+=arr[x];
				}
				s=(j-i+1);
				avg[i][j]= (sum/s);
				sum=0;
				s=0;
				
			}
			
		}
	}
	return 0;
}

int print()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\narray[%d][%d]=%2f\n",i,j,avg[i][j]);
		}
	}
	return 0;
}

int main()
{
	create();
	average();
	print();
}
