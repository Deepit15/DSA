#include<stdio.h>
#include<stdlib.h>

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
	for(i=0;i<size;i+=1)
	{
		graph[i+1][0]=i;
		graph[0][i+1]=i;
	}
	for(i=0;i<size;i+=1)
	{
		for(j=0;j<size;j+=1)
		{
			printf("\nGraph[%d][%d]:",i,j);
			scanf("%d",&graph[i][j]);
			if(graph[i][j]>1 || graph[i][j]<0)
			{
				j-=1;
			}
		}
	}
	return size;
}

void enqueue(int arr[],int data,int *rear)
{
	arr[*rear]=data;
	*rear+=1;
}

int dequeue(int arr[],int *front)
{
	int temp;
	temp=arr[*front];
	arr[*front]=0;
	*front+=1;
	return temp;
}

int check(int arr[],int data,int size)
{
	int i=0,flag=FAILURE;
	for(i=0;i<size;i+=1)
	{
		if(arr[i]==data)
		{
			flag=SUCCESS;
			break;
		}
	}
	return flag;
}

void displayarr(int arr[],int size)
{
	int i;
	printf("\n");
	for(i=0;i<size;i+=1)
	{
		printf("%d\t",arr[i]);
	}
}

void bfs(int graph[][MAX],int size)
{
	int queue[MAX],visited[MAX],i,j,k,front,rear,explore,visize=0,flag=0,ret;
	front=rear=0;
	for(i=0;i<size;i+=1)
	{
		visited[i]=0;
	}
	queue[0]=0;
	rear+=1;
	visited[0]=0;
	visize+=1;
//	printf("\nbefore while loop");
	while(front!=rear)
	{
//		printf("\nstarting while front=%d rear=%d loop",front,rear);
		explore=dequeue(queue,&front);
//		printf("\nexplore:%d",explore);
//		printf("front=%d rear=%d",front,rear);
		for(j=0;j<size;j+=1)
		{
//			printf("\nstarting j=%d loop",j);
			if(graph[explore][j]==SUCCESS)
			{
				ret=check(visited,j,visize);
//				printf("ret=%d",ret);
				if(ret==FAILURE)
				{
					visited[visize]=j;
					visize+=1;
//					enqueue(queue,j,&rear);
					queue[rear]=j;
					rear+=1;
//					printf("\nfront=%d rear=%d",front,rear);
				}
			}
//			printf("\nending j=%d loop",j);
		}
//		printf("\nending while front=%d rear=%d loop",front,rear);
	}
//	printf("\nafter while loop");
	displayarr(visited,visize);
}



int main()
{
	int choice,graph[MAX][MAX],size;
	while(1)
	{
		printf("\n1.Create graph\n2.Display graph\n3.BFS\n5.Exit\nEnter your choice:");
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
				bfs(graph,size);
				break;
			case 5:
				exit(0);
			default:
				printf("\nInvalid Input !!\nTry Again !!");
		}
	}
	return 0;
}
