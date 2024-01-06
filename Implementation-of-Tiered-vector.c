#include<stdio.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 2
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

int listMaxSize;
int * list;
int length;


void initializeList()
{
    listMaxSize = LIST_INIT_SIZE;
    list = (int*)malloc(sizeof(int)*listMaxSize) ;
    length = 0 ;
}

int searchItem(int item)
{
    int i = 0;
    for (i = 0; i < length; i++)
    {
        if( list[i] == item )
            return i;
    }
    return NULL_VALUE;
}

int insertItem(int newitem)
{
    int * tempList ;
    if (length == listMaxSize)
    {

        listMaxSize = 2 * listMaxSize ;
        tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
        int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ;
        }
        free(list) ;
        list = tempList ;
    };

    list[length] = newitem ;
    length++ ;
    return SUCCESS_VALUE ;
}

int insertItemAt(int newitem, int position)
{

length++;

int * tempList ;
    if (length == listMaxSize)
    {

        listMaxSize = 2 * listMaxSize ;
        tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
        int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ;
        }
        free(list) ;
        list = tempList ;

    }

    /*int i=length;
    while(i>position)
    {
        list[i]=list[i-1];
        i--;
    }
    list[position]=newitem;*/

    for(int i=length;i>position;i--){

list[i]=list[i-1];

    }

    list[position]=newitem;

    //length++;
    return SUCCESS_VALUE;

}

int insertItemAtFront(int newitem)
{

    int i=length+1;
    while(i>=0)
    {
        list[i]=list[i-1];
        i--;
    }
    list[0]=newitem;
    length++;
    return SUCCESS_VALUE;
}

int deleteItemAt(int position)
{
    if ( position >= length )
        return NULL_VALUE;
 //   list[position] = list[length-1] ;
   // length-- ;

    for(int i=position;i<length;i++){

int temp=list[i];
list[i]=list[i+1];

list[i+1]=temp;

    }

    length--;

    return SUCCESS_VALUE ;
}

int editItemAt(int item, int position)
{
    if ( position >= length )
        return NULL_VALUE;
    list[position] = item;
    return SUCCESS_VALUE;
}

int deleteItem(int item)
{

    int i = searchItem(item);
    if(i!=NULL_VALUE)
    {
        deleteItemAt(i);
        return SUCCESS_VALUE;
    }
    else
    {
        return NULL_VALUE;
    }

}
void printList()
{
    int i;
    for(i=0; i<length; i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}

void sortList()
{

    int i,j,temp;
    for(i=0; i<length; i++)
    {
        for(j=i+1; j<length; j++)
        {
            if(list[j] <list[i])
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

}

int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item at. 3. Search Item 4. Delete item\n");
        printf("5. Edit item at  6. Insert new item at position  7. Insert new item at front.\n");
        printf("8. Print. 9.Sort  10. exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int pos;
            scanf("%d", &pos);
            deleteItemAt(pos);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            int r = searchItem(item);
            if(r==NULL_VALUE)
                printf("Item not present.\n");
            else
                printf("Item found at %d index\n",r);
        }
        else if(ch==4)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==5)
        {
            int item,pos;
            scanf("%d%d", &item,&pos);
            editItemAt(item,pos); //Place the item at pos
        }
        else if(ch==6)
        {
            int item,pos;
            scanf("%d%d", &item, &pos);
            insertItemAt(item,pos);
        }
        else if(ch==7)
        {
            int item;
            scanf("%d", &item);
            insertItemAtFront(item);
        }
        else if(ch==8)
        {
            printList();
        }
        else if(ch==9)
        {
            sortList();
        }
        else if(ch==10)
        {
            break;
        }
    }
}

