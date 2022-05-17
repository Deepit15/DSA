#include <stdio.h>
#include <stdlib.h>
int steps;

int random(int arr[])
{
	int i,a;
	for(i=0;i<100;i++)
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


void swap(int *m,int *i)
{
	int temp = *m;
	*m = *i;
	*i = temp;
}

void display(int arr[],int success,int no_Search)
{
	int i,avg;
	float per;
	for(i=0;i<100;i++)
	{
		printf("\nthe value at %d is %d",i,arr[i]);
	}
	avg=(int)(steps/no_Search);
	per = ((float)(success)/no_Search)*100;
//	printf("\n%d",steps);
	printf("\nThe number of searches completes: %d",no_Search);
	printf("\nThe number of successful searches: %d",success);
	printf("\nThe Percentage of successful searches: %.2f %%",per);
	printf("\nThe average number of tests per search: %d",avg);
}

void sequential(int arr[],int success,int no_Search)
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
	display(arr,success,no_Search);
}


void selection_sort(int arr[],int count)
{
	
	int i,j,min_indx,counter;
	for(i=0;i<count-1;i++)
	{
		min_indx=i;
		for(j=i+1;j<count;j++)
		{
			if(arr[min_indx]>arr[j])
			{
				min_indx=j;
			}
		}
		swap(&arr[min_indx],&arr[i]);
	}
	
}


void search(int arr[],int success,int no_Search)
{
	int i,j,a,n;
	n=100;
	for(i=0;i<99;i++)
	{
		
		repeat:
		a=rand()%1000;
		if(a>200)
		{
			goto repeat;
			}
			no_Search++;	
		if(binarySearch(arr,0,n,a)!=-1)
		{
			success++;
		}
	}
	display(arr,success,no_Search);
}

int binarySearch(int arr[], int l, int r, int x)
{
 steps++;
	
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        if (arr[mid] == x)
            return mid;
 
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        return binarySearch(arr, mid + 1, r, x);
    }
 
    return -1;
}

int main()
{
	int arr[100],success,no_Search,steps;
	random(arr);
	selection_sort(arr,100);
	search(arr,success,no_Search);
	return 0;
}

