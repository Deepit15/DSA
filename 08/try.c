#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input(char *str)
{
	char tmp;
	int x;
	printf("\nEnter the string : ");
	restring:
	scanf("%s",str);
	for (x = 0; x < strlen(str); x++)
	{
		tmp = str[x];
		if (((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z')) == 0)
		{
			printf("\nRe-enter the string (String can only contain alphabets) : ");
			goto restring;
		}
	}	
	return 0;	
}

int pattern(char *ptr)
{
	char tmp;
	int x;
	printf("\nEnter the pattern : ");
	repattern:
	scanf("%s",ptr);
	for (x = 0; x < strlen(ptr); x++)
	{
		tmp = ptr[x];
		if (((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z')) == 0)
		{
			printf("\nRe-enter the pattern (Pattern can only contain alphabets) : ");
			goto repattern;
		}
	}		
	return 0;	
}

int compare(char str[30],char ptr[30],int *a)
{
	int i,j,success=0,temp;
	for(i=0;i<strlen(str);i++)
	{
		temp=i;
		for(j=0;j<strlen(ptr);j++)
		{
			(*a)++;
			if(str[i]==ptr[j])
			{
				i++;
				if(j==strlen(ptr)-1)
				{
					success=1;
					break;
				}
			}
			else
			{
				break;
			}
			
		}
		if(success==1)
		{
			break;
		}
		i=temp;
	}
	return success;
}


int main()
{
	int ch,a=0,count;
	char str[30],ptr[30];
	while(1)
	{
		printf("\n1. Enter string\n2.Enter pattern\n3. Display pattern and string\n4. Compare\n5. Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					input(str);
					break;	
				}
				
			case 2:
				{
					pattern(ptr);
					break;
				}
				
			case 3:
				{
				printf("\n String is : %s\n Patetrn is  : %s",str,ptr);
				break;	
			}
			case 4:
				{
					count=0;
					a=compare(str,ptr,&count);
					printf("\nNumber of comparison is : %d",count);
					if(a==1)
						printf("\nFound");
					else
						printf("\nNot found");
					break;
					
				}
			default:
				{
				printf("\nWrong choice");
				break;
			}
		}
	}
	return 0;
}
