#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct Node {
    int val;
    struct Node *next;
};
typedef struct Node N;
N *start = NULL, *tmp;

void CreateNode();
void InsertFirst();
void LastInsert();
void DeleteLast();
void Insert2ndlast();
void Delete2ndlast();
void InsertAfter();
void InsertBefore();
void DeleteAfter();
void DeleteBefore();
void DeletePrime();
void DeleteArmstrong();
void CountNode();
void UpdateNode();
void PrintReverse(N *ptr);
void PrintNode();

int Prime(int);
int Armstrong(int);

void CreateNode()
{
    N *ptr;
    ptr = (N *)malloc(sizeof(N));
    printf("Enter a value in the value part of the node: ");
    scanf("%d", &ptr->val);
    ptr->next = NULL;
    if (start == NULL)
    {
        start = ptr;
        tmp=ptr;
    }
    else
    {
       tmp->next=ptr;
       tmp=ptr;
    }
}
void InsertFirst()
{
    N *ptr; int ch;
    ptr = (N *)malloc(sizeof(N));
    if (start == NULL)
    {
        printf(" There is no node in the list");
        printf("\n If you want to create a new node then press 1\n Or else you want to quit then press anything..");
        printf("\n Enter your choice : ");
        scanf("%d", &ch);
        if(ch==1)
        {
            CreateNode();
            return;
        }
        else
            return;
    }
    printf("Enter a value in the value part of the new node: ");
    scanf("%d", &ptr->val);
    ptr->next = start;
    start=ptr;
}
void LastInsert()
{
    N *ptr;
    ptr = (N *)malloc(sizeof(N));
    printf("Enter a value in the value part of the new node: ");
    scanf("%d", &ptr->val);
    ptr->next = NULL;
    if (start == NULL)
    {
        start=ptr;
    }
    else
    {
        N *tmp;
        tmp=start;
        while (tmp->next != NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=ptr;
    }
}
void DeleteLast()
{
    if(start == NULL)
    {
        printf("List Is Already Empty!\n");
        return;
    }
    if(start -> next == NULL)
    {
        free(start);
        start = NULL;
        return;
    }
    N *tmp;
    tmp = start;
    N* ptr;
    while (tmp->next != NULL)
    {
        ptr=tmp;
        tmp = tmp->next;
    }
    free(tmp);
    ptr->next = NULL;
}
void Insert2ndlast()
{
    N *ptr = (N *)malloc(sizeof(N));
    printf("Enter value in the vale part of the new node:");
    scanf("%d", &ptr->val);
    if(start == NULL)
    {
        printf("The list is empty...");
        return;
    }
    if(start -> next == NULL)
    {
        ptr -> next = start;
        start = ptr;
        return;
    }
    N *last = start;
    N *tmp;
    while (last->next != NULL)
    {
        tmp=last;
        last = last->next;
    }
    tmp->next=ptr;
    ptr->next=last;
}
void Delete2ndlast()
{
    if(start==NULL)
    {
        printf("The list is empty...");
        return;
    }
    if(start->next==NULL)
    {
        free(start);
        start=NULL;
        printf("Now the list is empty");
        return;
    }
    N *tmp=start; N *ptr;
    if(tmp->next->next == NULL)
    {
        ptr=tmp;
        tmp=tmp->next;
        free(ptr);
        start=tmp;
        return;
    }
    N *last=start;
    while (last->next->next != NULL)
    {
        tmp=last;
        last=last->next;
    }
    tmp->next=last->next;
    free(last);
}
void InsertAfter()
{
    int value;
    N *ptr= (N *) malloc(sizeof(N));
    printf("Enter the value of the new node at the value part: ");
    scanf("%d",&ptr->val);
    printf("Enter the value of a node in list after which you want to insert the new one :");
    scanf("%d",&value);
    if(start==NULL) {printf("The List is empty.."); return;} 
    N *tmp=start;
    while(tmp != NULL)
    {
        if(tmp -> val == value)
        {
            ptr -> next = tmp -> next;
            tmp -> next = ptr;
            return;
        }
        tmp = tmp -> next;
    }
    printf("Node does not exist");
}
void InsertBefore()
{
    int value; N* Ad;
    N* ptr= (N *) malloc(sizeof(N));
    printf("Enter the value of the new node in the value part :");
    scanf("%d",&ptr->val);
    printf("Enter the value of a node in list before which you want to insert the new one :");
    scanf("%d",&value);
    if(start==NULL) { printf("The List is empty.."); return;}
    N *tmp=start;
    while (tmp->val != value)
    {
        Ad=tmp;
        tmp=tmp->next;
    }
    ptr->next=tmp;
    Ad->next=ptr;
}
void DeleteAfter()
{
    int value; N* ptr;
    if(start==NULL)
        printf("The list is already empty");
    printf("Enter a value of a node in the list : ");
    scanf("%d",&value);
    tmp=start;
    while (tmp->val != value)
    {
        tmp=tmp->next;
    }
    if(tmp->next==NULL) { printf("There is no node after that node which you choose."); return; }
    ptr=tmp->next->next;
    free(tmp->next);
    tmp->next=ptr;
}
void DeleteBefore()
{
    int value; N* ptr;
    if(start==NULL) {printf("The list is already empty"); return; }
    printf("Enter a value of a node in the list : ");
    scanf("%d",&value);
    if(start->val == value){
        printf("There is no node before it."); 
        return;
    }
    N* tmp1=start;
    while(tmp1->val != value)
    {
        ptr=tmp1;
        tmp1=tmp1->next;
    }
    if(ptr==start)
    {
        free(ptr);
        start=tmp1;
        return;
    }
    N* tmp2 = start->next; tmp1 = start;
    while (tmp2->val != value)
    {
        ptr=tmp1;
        tmp1=tmp1->next;
        tmp2=tmp2->next;
    }
    free(tmp1);
    ptr->next=tmp2;
}

void DeletePrime()
{
    N* ptr;
    tmp=start;
    if(Prime(tmp->val)== 2)
    {
        ptr=start;
        start=ptr->next;
        free(ptr);
        return;
    }
    tmp=start;
    while(tmp != NULL)
    {
        if(Prime(tmp->val) == 2)
        {
            ptr->next=tmp->next;
            printf("The node which contain %d is deleted ", tmp->val);
            free(tmp);
            return;
        }
        ptr=tmp;
        tmp=tmp->next;
    }
    printf("\n There is no node which conatin prime number.");
}
void DeleteArmstrong()
{
    N *ptr;
    tmp=start;
    while(tmp != NULL)
    {
        int sum=Armstrong(tmp->val);
        if( sum == tmp->val)
        {
            ptr->next=tmp->next;
            printf("The node which contain %d is deleted", tmp->val);
            free(tmp);
            return ;
        }
        ptr=tmp;
        tmp=tmp->next;
    }
    printf("\n There is no node which contain armstrong number.");
}

void CountNode()
{
    int count=0;
    if(start==NULL)
        printf("There is no node in the list.");
    N *tmp=start;
    while (tmp->next != NULL)
    {
        count++;
        tmp=tmp->next;
    }
    printf("Number of Node is = %d",count+1);
}
void UpdateNode()
{
    int value,pos;
    printf("Enter the new value");
    scanf("%d",&value);
    printf("Enter the node value in the list which you want to update: ");
    scanf("%d",&pos);
    N *tmp=start;
    while (tmp->val != pos)
    {
        tmp=tmp->next;
    }
    tmp->val=value;
}
void PrintReverse(N *ptr)
{
    if(ptr == NULL) return;
    if(ptr -> next != NULL) PrintReverse(ptr -> next);

    printf("%d >", ptr->val);
}
void PrintNode()
{
    N *ptr = start;
    while (ptr != NULL)
    {
        printf("%d-> ", ptr->val);
        ptr = ptr->next;
    }
}
void main()
{
    int ch;
    int ctr;
    do
    {
        ctr=1;
        printf("\n -: M E N U :-\n  -----------------------");
        printf("\n %d.... Create Node.", ctr++);
        printf("\n %d.... Insert a new node at first.", ctr++);
        printf("\n %d.... Insert a new node at the last position.", ctr++);
        printf("\n %d.... Delete the last node. ", ctr++);
        printf("\n %d.... Insert a new node at the 2nd last position", ctr++);
        printf("\n %d.... Delete the 2nd last Node. ", ctr++);
        printf("\n %d.... Insert a new node after a given node which is taken by user.", ctr++);
        printf("\n %d.... Insert a new node before a given node which is taken by user.", ctr++);
        printf("\n %d.... Delete a node from the list after a given node.", ctr++);
        printf("\n %d.... Delete a node from the list before a given node.", ctr++);
        printf("\n %d.... Delete a node from the list which value is prime.", ctr++);
        printf("\n %d.... Delete a node from the list which value is Armstrong.", ctr++);
        printf("\n %d.... Count how many node there in the list.", ctr++);
        printf("\n %d.... Update the value of a node in the list which the user want.", ctr++);
        printf("\n %d.... Print the numbers in clockwise way.");
        printf("\n %d.... Print Reverse Node.", ctr++);
        printf("\n %d.... Print Node.", ctr++);
        printf("\n 0.... Exiting the program......");
        printf("\nEnter A Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:CreateNode();
            break;
        case 2:InsertFirst();
            break;
        case 3:LastInsert();
            break;
        case 4:DeleteLast();
            break;
        case 5:Insert2ndlast();
            break;
        case 6:Delete2ndlast();
            break;
        case 7:InsertAfter();
            break;
        case 8:InsertBefore();
            break;
        case 9:DeleteAfter();
            break;
        case 10:DeleteBefore();
            break;
        case 11:DeletePrime();
            break;
        case 12:DeleteArmstrong();
            break;
        case 13:CountNode();
            break;
        case 14:UpdateNode();
            break;
        // case 15:Printclockwise();
        //     break;
        case 16:PrintReverse(start);
            break;
        case 17:PrintNode();
            break;
        }
    } while (ch != 0);
}

int Armstrong(int n)
{
    int i,r, sum=0, count=0;
    for(i=n; i>0; i/=10)
    {
        count++;
    }
    for(i=n; i>0; i/=10)
    {
        r=i%10;
        sum=sum+(int)pow(r,count);
    }
    return sum;
}
int Prime(int n)
{
    int i,count=0;
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
            count++;
    }
    return count;
}

