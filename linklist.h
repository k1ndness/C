struct node
{
    /* data */
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *createList (int *, int );
void printfList(NODE *);
void freeList(NODE *);
void insertNode(NODE * ,  int );
NODE *searchNode(NODE *, int);
NODE *deleteNode(NODE *, NODE *);
/**
NODE *createList (int *arr, int len)
{
    int i ;
    NODE *first,*current,*previous;
    current = (NODE *) malloc(sizeof(NODE));
    //printf("Data for node %d :",i+1);
    //scanf("%d",&(current->data));
    current->data = arr[i];
    if(i==0)
        first = current;
    else
        previous->next = current;
    current->next = NULL;
    previous = current ;
    
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
**/