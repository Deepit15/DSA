#include <conio.h>
#include <stdio.h>

int n;
struct state
{
	char name[30];
	float population;
	char language[20];
	float literacy;
};


void create(struct state **ptr)
{
	
	/*struct state *t = malloc(sizeof(struct state));*/
	int i;
	
	for(i=0;i<n;i++)
	{
		printf("Enter the name of the %d state : ",i+1);
		scanf("%s",(*ptr)[i].name);
		printf("Enter the population of the %d state : ",i+1);
		scanf("%f",&(*ptr)[i].population);
		printf("Enter the language of the %d state : ",i+1);
		scanf("%s",&(*ptr)[i].language);
		printf("Enter the literacy percentage of the %d state : ",i+1);
		scanf("%f",&(*ptr)[i].literacy);
//		*(ptr)[i]=*t;
	}
//	literacy(&ptr);
}

void display(struct state **ptr)
{
//	struct state *ptr;
	int i;
	for(i=0;i<n;i++)
	{
		printf("%s\t%2f\t%s\t%2f\n",(*ptr)[i].name,(*ptr)[i].population,(*ptr)[i].language,(*ptr)[i].literacy);
	}
}


int literacy(struct state **ptr)
{
//	struct state *ptr;
//	struct state *t = malloc(sizeof(struct state));
	struct state t;
//	t = (struct state *)malloc(1* sizeof(struct state));
	int i,j;
	for(j=1;j<n;j++)
	{
		for(i=0;i<n-j;i++)
		{
			if((*ptr)[i].literacy<(*ptr)[i+1].literacy)
			{
				t= (*ptr)[i];
				(*ptr)[i] = (*ptr)[i+1];
				(*ptr)[i+1]=t;
			}
		}
		
	}
	
//	display();
	return 0;
}

int main()
{
	struct state *ptr;
	printf("Enter the number of entries : ");
	scanf("%d",&n);
	ptr = (struct state *)malloc(n* sizeof(struct state));
	create(&ptr);
	literacy(&ptr);
	display(&ptr);
	return 0;
}
