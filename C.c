#include <stdio.h> 
#include <stdlib.h>
#include "linklist.h"
int B = 2;
void address(int *p1)
{
    printf("address %p  is %d \n",p1,*p1); 
}

void func(int *p){p = &B;}
void func2(int **p){ *p = &B; }
/**
struct node 
{
    int data ;
    struct node *next;
};
typedef struct node NODE;
**/

void main(){

    printf("hello 12 \n");
    //int *ptr,num=20;
    //ptr=&num;
    //printf("num = %d ,&num = %p \n",num,&num);
    //printf("*ptr = %d ,ptr = %p &ptr = %p \n",*ptr,ptr,&ptr);    
    //address(&num);
    //address(ptr);
    // int A = 1, C = 3;
    // int *ptrA = &A;
    // func(ptrA);
    // printf("%d\n", *ptrA);
    // func2(&ptrA);
    // printf("%d\n", *ptrA);

    /**
    a.next = &b;
    b.data = 10;
    b.next = &c;
    c.data = 26;
    c.next = NULL;    
    while (ptrz!=NULL)
    {
        printf("address = %p ,",ptrz);
        printf("data = %d ",ptrz->data);
        printf("next = %p \n ",ptrz->next);
        ptrz=ptrz->next;
    }
    **/

   /**
    int i,val,num;
    NODE *first,*current,*previous;
    printf("Number of nodes :");
    scanf("%d",&num);

    for(i = 0;i < num;i++)
    {
        current = (NODE *) malloc(sizeof(NODE));
        printf("Data for node %d :",i+1);
        scanf("%d",&(current->data));
        if(i==0)
            first = current;
        else
            previous->next = current;
        current->next = NULL;
        previous = current ;
    }
    current = first;
     while (current!=NULL)
    {
        printf("address = %p ,",current);
        printf("data = %d ",current->data);
        printf("next = %p \n ",current->next);
        current=current->next;
    }
**/
NODE *first, *node;
int arr[] = {1,2,3,8,10};
first = createList(arr,sizeof(arr)/sizeof(int));
printfList(first);


node = searchNode(first,3);
insertNode(node,6);
node = searchNode(first,6);
insertNode(node,9);

first = deleteNode(first,first);
printfList(first);
first = deleteNode(first,first);
printfList(first);


freeList(first);

int a=0;
printf("%d",++a);

}

NODE *createList (int *arr, int len)
{
    int i ;
    NODE *first,*current,*previous;
    for ( i = 0; i < len; i++)
    {
    current = (NODE *) malloc(sizeof(NODE));
    current->data = arr[i];
    if(i==0)
        first = current;
    else
        previous->next = current;

    current->next = NULL;
    previous = current ;

    }
    
    return first;


}

void printfList(NODE* first)
{
    NODE* node = first;
    if(first == NULL)
        printf("list is empty \n");
    else
    {
        while(node != NULL)
        {
            printf("%3d",node->data);
            node = node->next;
        }
        printf("\n");
    }
}

void freeList(NODE* first)
{
    NODE *current ,*tmp;
    current = first;
    while(current != NULL)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }
}
NODE* searchNode (NODE* first ,int item)
{
    NODE *node = first;
    while(node != NULL)
    {
        if(node->data == item)
            return node;
        else 
            node = node->next;
    }
    return NULL;
}

void insertNode(NODE *node,  int item)
{
    NODE *newnode;
    newnode = (NODE *) malloc(sizeof(NODE));
    newnode->data = item;
    newnode->next = node->next;
    node->next = newnode;
}

NODE* deleteNode (NODE *first, NODE *node)
{
    NODE *ptr = first;
    if(first == NULL)
    {
        printf("Nothing to delete");
        return NULL;
    }
    if(node == first)
        first = first->next;
    else
    {
        while(ptr->next != node)
            ptr = ptr->next;
        ptr->next = node->next;
    }
    free(node);
    return first;
}
