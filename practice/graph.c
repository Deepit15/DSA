#include <stdio.h>
#include <conio.h>


#define MAX 100
#define SUCCESS 1
#define FAILURE 0

void displaygraph(int graph[][MAX],int size)
{
	int i,j;
	for(i=0;i<size;i+=1)
	{
		printf("\n");
		for(j=0;j<size;j+=1)
		{
			printf("%d\t",graph[i][j]);
		}
	}
	printf("\n");
}


int creategraph(int graph[][MAX])
{
	int i,j,size;
	printf("\nEnter the no. of vertices:");
	scanf("%d",&size);
	
	for(i=0;i<size/2;i+=1)
	{
		for(j=0;j<size/2;j+=1)
		{
//			printf("\nGraph[%d][%d]:",i,j);
//			scanf("%d",&graph[i][j]);
			graph[i][j] = 1;
		}
	}
	
	for(i=size/2;i<size;i+=1)
	{
		for(j=size/2;j<size;j+=1)
		{
//			printf("\nGraph[%d][%d]:",i,j);
//			scanf("%d",&graph[i][j]);
			graph[i][j] = 1;
		}
	}
	return size;
}

void friend(int graph[][MAX])
{
	int a=0,b=0;
	printf("Enter first friend number : ");
	scanf("%d",&a);
	printf("Enter second friend number : ");
	scanf("%d",&b);
	graph[a-1][b-1] = 1;
	graph[b-1][a-1] = 1;
	
}


void main()
{
	int choice,graph[MAX][MAX],size;
	while(1)
	{
		
		printf("\n1.Create graph\n2.Display graph\n3.Friend\n5.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				size=creategraph(graph);
				break;
			case 2:
				displaygraph(graph,size);
				break;
			case 3:
				friend(graph);
				break;
			case 5:
				exit(0);
			default:
				printf("\nInvalid Input !!\nTry Again !!");
		}
	}
	return 0;
	
}
