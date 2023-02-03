//         Singly Circular Linked List in C         (HomeWork)

// Create Class and Functions.
// Create returns of main functions.
// Insert First & Last.
// Delete First & Last.
// InsertAtPosition & DeleteAtPosition.

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First, PPNODE Last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL))
    {
        *First = *Last = newn;
        (*Last)->next = *First;
    }
    else
    {
        newn->next = *First;
        *First = newn;
        (*Last)->next = *First;
    }
}

void InsertLast(PPNODE First, PPNODE Last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL))
    {
        *First = *Last = newn;
        (*Last)->next = *First;
    }
    else
    {
        (*Last)->next = newn;
        *Last = newn;
        (*Last)->next = *First;
    }
}

void DeleteFirst(PPNODE First, PPNODE Last)
{
    PNODE temp = *First;

    if((*First == NULL) && (*Last == NULL))
    {
        return;
    }
    else if((*First)->next == *Last)
    {
        (*First)->next = NULL;
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        *First = (*First)->next;
        (*Last)->next = *First;
    }
}

void DeleteLast(PPNODE First, PPNODE Last)
{
    PNODE temp = *First;

    if((*First == NULL) && (*Last == NULL))
    {
        return;
    }
    else if((*First)->next == *Last)
    {
        (*First)->next = NULL;
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        while(temp->next != *Last)
        {
            temp = temp->next;
        }
        temp->next = (*Last)->next;
        *Last = temp;
        (*Last)->next = *First;
    }
}

void Display(PNODE First, PNODE Last)
{
    printf("Elements of Linked List are : \n");

    do
    {
        printf(" | %d | -> ",First->data);
        First = First->next;
    } while (First != Last->next);
    printf(" NULL \n");
    
}

int Count(PNODE First, PNODE Last)
{
    int iCnt = 0;

    do
    {
        iCnt++;
        First = First->next;
    } while (First != Last->next);
    return iCnt;
}

void InsertAtPosition(PPNODE First, PPNODE Last, int no, int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    NodeCnt = Count(*First,*Last);

    if((ipos < 1) || (ipos > NodeCnt+1))
    {
        printf("Invalid Position \n");
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(First, Last, no);
    }
    else if(ipos == NodeCnt)
    {
        InsertLast(First, Last, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        (*Last)->next = *First;
    }
}

void DeleteAtPosition(PPNODE First, PPNODE Last, int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    NodeCnt = Count(*First, *Last);

    if((ipos < 1) || (ipos > NodeCnt+1))
    {
        printf("Invalid Position \n");
    }

    if(ipos == 1)
    {
        DeleteFirst(First, Last);
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast(First, Last);
    }
    else
    {
        temp1 = *First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
        (*Last)->next = *First;
    }
}

int main()
{
    PNODE Head = NULL;
    PNODE Tail = NULL;
    int iRet = 0;

    InsertFirst(&Head, &Tail, 40);
    Display(Head, Tail);
    InsertFirst(&Head, &Tail, 30);
    Display(Head, Tail);
    InsertFirst(&Head, &Tail, 20);
    Display(Head, Tail);
    InsertFirst(&Head, &Tail, 10);
    Display(Head, Tail);

    iRet = Count(Head, Tail);
    printf("Number of InsertFirst Elements are : %d\n\n",iRet);

    InsertLast(&Head, &Tail, 50);
    Display(Head, Tail);
    InsertLast(&Head, &Tail, 60);
    Display(Head, Tail);
    InsertLast(&Head, &Tail, 70);
    Display(Head, Tail);
    InsertLast(&Head, &Tail, 80);
    Display(Head, Tail);

    iRet = Count(Head, Tail);
    printf("Number of InsertLast Elements are : %d\n\n",iRet);

    InsertAtPosition(&Head, &Tail, 55, 6);
    Display(Head, Tail);
    
    iRet = Count(Head, Tail);
    printf("Number of InsertAtPosition Elements are : %d\n\n",iRet);

    DeleteFirst(&Head, &Tail);
    Display(Head, Tail);
    
    iRet = Count(Head, Tail);
    printf("Number of DeleteFirst Elements are : %d\n\n",iRet);

    DeleteLast(&Head, &Tail);
    Display(Head, Tail);

    iRet = Count(Head, Tail);
    printf("Number of DeleteLast Elements are : %d\n\n",iRet);

    DeleteAtPosition(&Head, &Tail, 5);
    Display(Head, Tail);

    iRet = Count(Head, Tail);
    printf("Number of DeleteAtPosition Elements are : %d\n\n",iRet);

    return 0;
}