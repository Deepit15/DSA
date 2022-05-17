#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define SUCCESS 1
#define FAILURE 0

int len(char str[])
{
	int length=0,i=0;
	while(str[i]!='\0')
	{
		length+=1;
		i+=1;
	}
	return length;
}

void createlps(char a[],char lps[])
{
	int j=0,i=0;
	lps[j]=0;
	while(i<len(a))
	{
		if(a[j]==a[i])
		{
			lps[i]=j+1;
			j+=1;
			i+=1;
		}
		else
		{
			j=lps[j-1];
			if(0==j)
			{
				lps[i]=0;
				i+=1;
			}
		}
	}
}







int checkpat(char str[],char pattern[],char lps[],int *com)
{
	int strle,patlen,flag=FAILURE,i=0,j=0;
	strle=len(str);
	patlen=len(pattern);
	createlps(pattern,lps);
		while(j<patlen)
		{
			*com=*com+1;
			if(str[i]==pattern[j+1])
			{
				i+=1;
				j+=1;
			}
			else
			{
				if(j==0)
				{
					i+=1;
				}
				j=lps[j];
			}
			if(j==patlen)
			{
				flag=SUCCESS;
				break;
			}
			if(i==strle)
			{
				if(j!=patlen)
				{
					flag=FAILURE;
				}
				break;
			}
		}
		return flag;
}

void display(char str[],char pattern[])
{
	int ret=0,compa=0;
	char lps[MAX];
	fputs(str,stdout);
	fputs(pattern,stdout);
	ret=checkpat(str,pattern,lps,&compa);
	fputs(lps,stdout);
	if(ret==SUCCESS)
	{
		printf("\nPattern matches.");
		printf("\nNo. of comparisons:%d",compa);
	}
	else
	{
		printf("\nPattern dosen't match.");
		printf("\nNo. of comparisons:%d",compa);
	}
}

int main()
{
	int choice;
	char str[MAX],pattern[MAX];
	while(1)
	{
		printf("\n1.Enter the string\n2.Enter the pattern\n3.Display pattern and string\n4.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("\nEnter the string:");
				fflush(stdin);
				scanf("%s",str);
				break;
			case 2:
				printf("\nEnter the pattern:");
				fflush(stdin);
				scanf("%s",pattern);
				break;
			case 3:
				display(str,pattern);
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\nInvalid input !!\nTry Again !!");
		}
	}
	return 0;
}
