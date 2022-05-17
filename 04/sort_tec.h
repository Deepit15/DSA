
void swap(int *m,int *i)
{
	int temp = *m;
	*m = *i;
	*i = temp;
}

void display(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nenter the value at %d",arr[i]);
	}
}

void selection_sort(int arr[],int count)
{
	clock_t t;
	t = clock();
	int i,j,min_indx,counter;
	for(i=0;i<count-1;i++)
	{
		counter++;
		min_indx=i;
		counter++;
		for(j=i+1;j<count;j++)
		{
			counter++;
			if(arr[min_indx]>arr[j])
			{
				counter++;
				min_indx=j;
				counter++;
			}
		}
		counter++;
		counter++;
		swap(&arr[min_indx],&arr[i]);
	}
	counter++;
	printf("\n%f",clock());
	t=t-clock();
	
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\nTime taken by selection sort is %f",time_taken);
	printf("\nTime taken by selection sort is %d",count);
}

void insertion(int arr[],int n)
{
		clock_t t;
	t = clock();
	int i,j,temp,count;
	for(i=0;i<n;i++)
	{
		count++;
		temp=arr[i];
		count++;
		j=i-1;
		count++;
		while(j>=0 && temp <=arr[j])
		{
			count++;
			arr[j+1]=arr[j];
			count++;
			j--;
		}
		count++;
		arr[j+1]=temp;
	}
	t=t-clock();
//	printf("Time taken by selection sort is %f",t);
		printf("Time taken by insertion sort is %d",count);
}

void bubblesort(int arr[],int n)
{
		clock_t t;
	t = clock();
	int i,j,count=0;
	for(i=0;i<n-1;i++)
	{
		count++;
		for(j=0;j<n-i-1;j++)
		{
			count++;
			if(arr[j]>arr[j+1])
			{
				count++;
				swap(&arr[j],&arr[j+1]);
				count++;
			}
		}
		count++;
	}
	count++;
		t=t-clock();
//	printf("Time taken by selection sort is %f",t);
		printf("Time taken by bubble sort is %d",count);
}

