
int random(int arr[])
{
	int n,i;
	printf("Enter the total numbers of elements you want to enter : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		arr[i]=rand()%100;
	}
	display(arr,n);
	return n;
}

int random_acc(int arr[])
{
	int n,i,temp;
	printf("Enter the total numbers of elements you want to enter : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		temp=rand()%100;
		if(temp >= arr[i-1])
		{
			arr[i]= temp;
		}
		else
		{
			i--;
		}
	}
	return n;
}


int random_desc(int arr[])
{
	int n,i,temp;
	printf("Enter the total numbers of elements you want to enter : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		temp=rand()%1000;
//		printf("%d",temp);
		if(i==0)
		{
			arr[i]= temp;
		}
		else if(temp <= arr[i-1])
		{
			arr[i]= temp;
		}
		else
		{
			i--;
		}
	}
	return n;
}


