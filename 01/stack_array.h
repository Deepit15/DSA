int arr_push(int *top,int *arr)
{
	int val;
	printf("Enter the value : ");
	scanf("%d",&val);
	if(*top==29)
	{
		printf("Stack overflow!!");
	}
	else
	{
		*top+=1;
		arr[*top]=val;
		
	}
		printf("Value pushed");
	
	return 0;
}

int arr_pop(int *top,int *arr)
{
	if (*top == -1)
	{
		printf("Underflow");
	}
	else
	{
		printf("%d is the value\n",arr[*top]);
		*top-=1;
		printf("Item popped");
	}
	return 0;
}

int arr_display(int *top,int *arr)
{
	printf("Values of array are:-\n");
	if(*top==-1)
	{
		printf("Stack is empty");
	}
	else
	{
		while(*top>-1)
		{
			printf("%d\n",arr[*top]);
			*top-=1;
		}
	}
	return 0;
}

