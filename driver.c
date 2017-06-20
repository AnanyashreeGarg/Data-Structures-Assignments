#include <stdio.h>
#include "linkedlist.h"
#include<stdlib.h>
#include<time.h>
int main(int argc, char *argv[]) 
{
int SIZE=0;
FILE * fileptr = fopen(argv[1], "r");
struct linkedList * head = (struct linkedList *) malloc (sizeof(struct linkedList));
head->first=NULL;
while (!feof(fileptr))
{
	int temp;
	fscanf(fileptr, "%d", &temp);
	printf("%d ",temp);
	clock_t start=clock();
	insertFirst(head,temp);
	clock_t endt=clock();
	clock_t diff=endt-start;
	printf("insert time=%ld\n",diff);
	SIZE+=sizeof(struct node*); 
}
printf("total size=%d\n",SIZE);
fclose(fileptr);
printList(head);
head->first=deleteFirst(head);
printList(head);
int found=search(head,231);
printf("found=%d\n",found);
head->first=delete(head,1);
printList(head);
return 0;
}
