#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort_tec.h"
#include "rand.h"

#define MAX 30


int input(int arr[])
{
	int n,i;
	printf("\nEnter the total numbers of elements you want to enter : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nenter the value at %d",i);
		scanf("%d",&arr[i]);
	}
	return n;
}

int main()
{
	int arr[MAX],n,choice,arr1[MAX],arr2[MAX],arr3[MAX];
	main:
	system("cls");
	printf("\n1. Enter the array\n2. Get random array\n3. Get random sorted array(asc)\n4. Get random sorted array(desc)\n\n5. Exit\nEnter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{
				n=input(arr);
				break;	
			}	
		case 2:
			{
				n=random(arr);
				break;
			}
			
		case 3:
			{
				n=random_acc(arr);
				break;
			}
		case 4:
			{
				n=random_desc(arr);
			break;	
			}	
		case 5:
			{
				exit(0);	
			}	
		default:
			printf("Wrong input!!");
	}
	while(1)
	{
	system("cls");
	printf("\n1. Insertion Sort \n2. Selection Sort\n3. Bubble Sort\n4. Main Menu\nEnter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{
				int i;
				for(i=0;i<n;i++)
				{
					arr1[i]=arr[i];
				}
				insertion(arr1,n);
				display(arr1,n);
				sleep(2);
				break;	
			}	
		case 2:
			{
				int i;
				for(i=0;i<n;i++)
				{
					arr2[i]=arr[i];
				}
				selection_sort(arr2,n);
				display(arr2,n);
				sleep(2);
				break;
			}
			
		case 3:
			{
				int i;
				for(i=0;i<n;i++)
				{
					arr3[i]=arr[i];
				}
				bubblesort(arr3,n);
				display(arr3,n);
				sleep(2);
				break;
			}
			case 4:
			{
				goto main;				
					}
			default:
			printf("Wrong input!!");
	}
}
	return 0;
}
