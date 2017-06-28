#include "linkedlist.h"
#include<stdio.h>
#include<stdlib.h>
void insertFirst(struct linkedList * head, int ele){
	struct node *link = (struct node*) malloc (sizeof(struct node));
	link->element = ele;
	link->next = head->first;
	head -> first = link;
	head -> count ++;
	printList(head);
}

void insertEnd (struct linkedList * head, int ele){
	struct node* temp=(struct node*) malloc (sizeof(struct node));
	temp->element=ele;
	temp->next=NULL;
	struct node* curr=head->first;
	if(curr==NULL)
	{insertFirst(head,ele);
	//return;
	}
	else{
	while(curr->next!=NULL)
		curr=curr->next;
	curr->next=temp;
	head->count++;
	printList(head);
	}
}



void deleteFirst(struct linkedList * head){
	struct node *ptr=head->first;
	if(ptr==NULL)
	{	
		printf("\n-2");
		return;
	}
	printf("\n%d",ptr->element);
	head->first=ptr->next;
	head->count--;
	
}

void deleteEnd(struct linkedList* head)
{
	struct node* curr=head->first;
	struct node* prev=head->first;
	if(curr==NULL)
	{	
		printf("\n-2");
		return;
	}
	curr=curr->next;
	if(curr==NULL)
	deleteFirst(head);
	else
	{
	while(curr->next!=NULL)
	{
		prev=prev->next;
		curr=curr->next;
	}
	prev->next=NULL;
	head->count--;
	printf("\n%d",curr->element);
	}
}

void printList(struct linkedList * head){
	struct node *ptr = head->first; 
	printf("\n");
	while(ptr != NULL){
     		printf("%d\t", ptr->element);
      		ptr = ptr->next;
   }
}
 




