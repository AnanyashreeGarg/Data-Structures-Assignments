#include "linkedlist.h"
#include<stdio.h>
#include<stdlib.h>
void insertFirst(struct linkedList * head, int ele){
struct node *link = (struct node*) malloc (sizeof(struct node));
link->element = ele;
link->next = head->first;
head -> first = link;
head -> count ++;
}

struct node* deleteFirst(struct linkedList * head){
struct node *ptr=head->first;
head->first=ptr->next;
head->count--;
return head->first;
}

void printList(struct linkedList * head){
struct node *ptr = head->first; 
printf("\n[ ");
while(ptr != NULL){
      printf("%d, ", ptr->element);
      ptr = ptr->next;
   }
	printf(" ]\n");
}
 
int search(struct linkedList *head,int ele)
{
struct node* temp=head->first;
int found=0;
while(temp!=NULL)
{
	if(temp->element==ele)
	{
		found=1;
		return found;
	}
	temp=temp->next;
}
if(!found)
return found;
else 
return 1;
}

struct node* delete(struct linkedList* head,int ele)
{
struct node* curr=head->first;
struct node* prev=head->first;
if(curr->element==ele)
{
	head->first=deleteFirst(head);
	head->count--;
	return head->first;
}
while(curr->next!=NULL)
{
	curr=curr->next;
	if(curr->element==ele)
	{
		prev->next=curr->next;
		head->count--;
		return head->first;
	}
	prev=prev->next;
}
return head->first;
}
