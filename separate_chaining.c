//seprarate chaining
#include<stdio.h>
#include<stdlib.h>
#define size 10
struct node{
	int data;
	struct node*next;
};
struct node*head[size]={NULL},*temp;


void insert_div_method()
{
	int key,i;
	printf("\nEnter a value to insert into hash table\n");
	scanf("%d",&key);
	i=key%size;
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=key;
	newnode->next= NULL;
	if(head[i] == NULL)
	{
		head[i]=newnode;
	}
	else
	{
		temp=head[i];
		while(temp->next != NULL)
		{
		    temp=temp->next;	
		}
		temp->next=newnode;
	}
	
}
void search()
{
	int key,i;
	printf("Enter the ele to be search:");
	scanf("%d",&key);
	i=key%size;
	if(head[i] == NULL)
	{
		printf("\nSearch Element not found");
	}
	else{
		for(temp=head[i];temp != NULL;temp=temp->next)
	    {
	   	     if(temp->data == key)
	   	     {
	   	     	printf("\nSerach element is found");
	   	     	break;
			 }
	    }
	}
    if(temp == NULL)
    {
    	printf("\nSearch Element not found");
	}
}
void display()
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("\n");
		if(head[i]==NULL)
		{
			printf("%d ",i);
			continue;
		}
		else
		{
			printf("%d",i);
			for(temp=head[i];temp != NULL;temp=temp->next)
			{
				printf("-->%d",temp->data);
			}
		}
	}
}
int main()
{
	int ch,key;
	while(1)
	{
		printf("\nEnter your choice:");
		printf("\nPress\n1.Insert_div_method\n2.Display\n3.Search\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_div_method();
				break;
			case 2:
				display();
				break;
			case 3:
				search();
				break;
			case 4:
				exit(0);
		}
	}
}
