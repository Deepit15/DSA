#include<stdio.h>   
#include<stdlib.h> 
 
struct node   
{  
    int data;   
    struct node *link;  
};

int n;

struct node *front;  
struct node *rear;  
 
void insert();  
void delete();  
void display(); 
void operations();

void main ()  
{  
    int choice,d,i,num;
	char temp;   
    while(choice != 5)   
    { 
    	system("cls");
        printf("\n1.insert new elements\n2.Delete negative elements\n3.Display the queue\n4.Perform Operation\n5. Exit\nEnter your choice ? : ");  
        scanf("%d",& choice);  
        switch(choice)  
        {  
            case 1:
            {
            	printf("Enter the number of values you want to input : ");
            	scanf("%d",&num);
            	n+=num;
            	for(i=0;i<num;i++)
            	{
            		printf("\nEnter value?\n");  
		        	scanf("%d",&d);
		            insert(d);	
				}  
				sleep(2);
			    break; 
			}
            case 2: 
			{
				delete(); 
				sleep(2); 
	            break; 
			 } 
             
            case 3:
			{
				display();
				sleep(2); 
            	break;
			 } 
              
            case 4:
			{
				operations(); 
				display();
				sleep(2);
            	break;
			 } 
            
            case 5:  
            exit(0);  
            break;  
            default:   
            printf("\nEnter valid choice??\n");  
        }  
    }  
}  

void insert(int d)  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
         
        ptr -> data = d;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> link = NULL;  
            rear -> link = NULL;  
        }  
        else   
        {  
            rear -> link = ptr;  
            rear = ptr;  
            rear->link = NULL;  
        }  
    }  
}    
 
void delete ()  
{  
    struct node *ptr;
    int i;
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
    	for(i=0;i<=n;i++)
    	{
    		if(front->data<0)
			{
				ptr = front;
				front = front -> link;  
	        	free(ptr);
	        	n-=1;
			 }
			else
			{
				ptr = front;
				insert(ptr->data);
				front = front -> link;  
				free(ptr);
			}
		}
		printf("\Negative Vlues Deleted\n"); 
          
    }  
}  

void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nUnderflow\n");  
    }  
    else  
    {   printf("\nprinting values .....\n");  
        while(ptr != NULL)   
        {  
            printf(" %d ",ptr -> data);  
            ptr = ptr -> link;  
        }  
    }  
}  


void operation()  
{  
    struct node *ptr; 
	int sum,n=0; 
	float average;
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nUnderflow\n");  
    }  
    else  
    {   
        while(ptr != NULL)   
        {  
            sum+=ptr -> data;
            n+=1;
            ptr = ptr -> link;  
        }
        average = (float)sum/n;
		printf("\nThe sum of the values are %d \n",sum);
		printf("\nThe average of the values are %2f \n",average);
    }
}  

void operations()
{
	struct node *ptr;
    int i,sum=0,num=0;
    float average;
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;
    }  
    else   
    {  
    	for(i=0;i<n;i++)
    	{
			ptr = front;
			sum = sum + (ptr->data);
            num = num + 1;
			insert(ptr->data);
			front = front -> link;  
			free(ptr);
		}
		average = (float)sum/n;
		printf("\nThe sum of the values are %d \n",sum);
		printf("\nThe average of the values are %2f \n",average);		
	}
}
