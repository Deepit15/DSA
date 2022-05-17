#include <stdio.h>
#include <stdlib.h>

int random(int arr[])
{
	int i,a;
	for(i=0;i<200;i++)
	{
		a=rand()%1000;
		if(a<=200)
		{
			arr[i]=a;
		}
		else{
			i--;
		}
	}

}



void display(int arr[],int success,int no_Search, int steps)
{
	int i,avg;
	float per;
	for(i=0;i<100;i++)
	{
		printf("\nthe value at %d is %d",i,arr[i]);
	}
	avg=(int)(steps/no_Search);
	per = ((float)(success)/no_Search)*100;
	printf("\nThe number of searches completes: %d",no_Search);
	printf("\nThe number of successful searches: %d",success);
	printf("\nThe Percentage of successful searches: %.2f %%",per);
	printf("\nThe average number of tests per search: %d",avg);
}

void sequential(int arr[],int success,int no_Search, int steps)
{
	int i,j,a;
	for(i=0;i<99;i++)
	{
		
		repeat:
		a=rand()%1000;
		if(a>200)
		{
			goto repeat;
			}
			no_Search++;	
		for(j=0;j<100;j++)
		{
			steps++;
			if(arr[j]==a)
			{
			
				success++;
				break;
			}
		}
	}
	display(arr,success,no_Search,steps);
}


int main()
{
	int arr[100],success,no_Search,steps;
	random(arr);
	sequential(arr,success,no_Search,steps);
//	display(arr,success,no_search,steps);
	return 0;
}
