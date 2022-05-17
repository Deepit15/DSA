#include <conio.h>
#include <stdio.h>
int arr[30],n;
int len[10];

int ascent()
{
	int temp=1,t=0,count=0,i;
	for(i=0;i<=n;i++)
	{
		if(arr[i]<=arr[i+1])
		{
			
			temp++;
		}
		else
		{
			if(t<temp)
			{
				t=temp;
			}
			temp=1;
		}
	}
	return t;
}

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


int main()
{
	int a;
	create();
	a=ascent();
	printf("%d",a);
}
