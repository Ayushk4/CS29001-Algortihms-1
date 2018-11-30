#include <stdio.h>
#include <stdlib.h>
struct node {
	int value;
	struct node * xor;
	//struct node *prev;
};


void print_linked_list(struct node * head)
{	
	unsigned int z = ((unsigned int) head) ^ ((unsigned int) NULL);
	struct node *ptr = (struct node *) z;
	int i=0;
	do
	{
		printf(" %d ",(unsigned int ) ptr->xor);
		//ptr=ptr->xor;
		unsigned int z = ((unsigned int) ptr->xor) ^ ((unsigned int) ptr);
		printf(" %d ", z);
		ptr = (struct node *) z;
		
		i++;
	}while(i<3);
}




int main()
{
	int n;
	printf("Enter the length of list : ");
	scanf("%d",&n);
	
	struct node *head = NULL,*ptr,*q;
	
	ptr = (struct node *) malloc (sizeof(struct node *));
	ptr->value = rand() % 101;
	q = ptr;
	ptr->xor = NULL;
	
	
	for (int i=0;i<n;i++)
	{	
		unsigned int z;	
		ptr = (struct node *) malloc (sizeof(struct node *));
		ptr->value = rand() % 101;
		//printf(" %d ",(unsigned int ) q->xor);
		z = ((unsigned int) q->xor) ^ ((unsigned int) ptr);
		q-> xor = (struct node *) z;
		//printf(" %d ",(unsigned int ) ptr);
		z = ((unsigned int) NULL) ^ ((unsigned int) q) ;
		//printf(" %d \n", z);
		ptr->xor = (struct node *) z;
		q = ptr;

		//printf("%d ",ptr->value);
		if(head == NULL)
			head = ptr;
	}
	
	print_linked_list(head);
	
}
