#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node * next;
};


void print_linked_list(struct node *head)
{
	struct node *ptr = head;
	while (ptr != NULL)
	{
		printf("%d ", ptr->value);
		ptr=ptr->next;
	}

}

void delete(struct node ** head_ptr, int element)
{	struct node *ptr = *head_ptr, *q;

	while(ptr!=NULL)
	{
		if(ptr->value == element)
		{
			if(q == NULL)
				*head_ptr = (*head_ptr)->next;
			
			else
				q->next = ptr->next;

			return ;
		}
	
		q = ptr;
		ptr= ptr->next;
	}
	printf("\n not found \n");
}

void reverse(struct node ** head)
{
	struct node *ptr = *head, *q , *r =NULL;

	while(ptr!=NULL)
	{
		q = ptr->next;
		ptr->next = r;
		r = ptr;
		ptr = q; 
	}

	*head = r;
}

struct node * find_max(struct node ** head)
{
	struct node * find_max = *head, *max = NULL;

	while(find_max!=NULL)
	{
		if(max == NULL)
			max = find_max;
		else
			if (max->value < find_max->value)
				max = find_max;

		find_max = find_max->next;
	}

	//printf("%d   ", max->value); 
	return (max);
}

struct node * split_list(struct node * head, struct node * r)
{
	struct node * ptr = head;
	r = head;
	
	while(ptr !=NULL)
	{
		
		ptr = ptr->next;
		if(ptr == NULL)
			break;
		ptr = ptr->next;
		if(ptr ==NULL)
			break;
		r = r->next;
	}
	
	ptr = r;
	r = r->next;
	ptr->next = NULL;
	return r;
}

struct node * sort_n_merge (struct node *a,struct node *b)
{
	struct node *val, *main_ptr, *head = NULL;

	while ((a!=NULL) && (b!=NULL))
	{
		if( a->value < b->value)
		{	val = a;
			a=a->next;
		}
		else
		{	val = b;
			b=b->next;		
		}
		if (head == NULL)
		{	head = val;
			main_ptr = head;
		}		
		else
			main_ptr->next =val;

		main_ptr->next = NULL;
	}
	
	while (a->next !=NULL)
	{	main_ptr->next =a;
		a=a->next;
		main_ptr = main_ptr->next;
		main_ptr->next = NULL;
	}
	while (b !=NULL)
	{	main_ptr->next = b;
		b = b->next;
		main_ptr = main_ptr->next;
		main_ptr->next = NULL;
	}		
	print_linked_list(head);
	return head;
}

struct node * merge_sort(struct node * head)
{
	if (head->next == NULL || head->next == NULL)
		return head;
	
	struct node *r;
	r = split_list(head, r);

	merge_sort(head);
	merge_sort(r);

	head = sort_n_merge(head,r);
	return head;

}	



int main()
{
	int n;
	printf("Write the number of data:");
	scanf("%d", &n);


	struct node *ptr = NULL ,*head = NULL, *q;

	for(int i = 0; i<n;i++)
	{	ptr = (struct node *) malloc(sizeof(struct node *));
		ptr->value = i;
		ptr->next = NULL;
		
		if(head==NULL)
			head = ptr;

		else
			q->next = ptr;

		q = ptr;
	}
	
	//print_linked_list(head);
	//delete(&head,2);
	//reverse(&head);
	//printf("qertyuio");
	head = merge_sort(head);
	//find_max(head);
	print_linked_list(head);
}	

