#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node *prev, *next;
};
typedef struct Node N;
N* start = NULL, *last = NULL ;

void PushNode();
void PushFirst();
void PopNode();
void PopFirst();
void PushAfter();
void PushBefore();
void PopAfter();
void PopBefore();
void PrintClockwise();
void PrintAntiClockwise();
void PrintForward();
void PrintBackward();

void PushNode()
{
    N* ptr;
    ptr= (N *) malloc(sizeof(N));
    printf("Enter a new value in the value part of the new node : ");
    scanf("%d",&ptr->val);
    ptr->next=NULL;
    if(start == NULL)
    {
        ptr->prev=NULL;
        start=ptr;
        last=ptr;
    }
    else
    {
        last->next=ptr;
        ptr->prev=last;
        last=ptr;
    }
}
void PushFirst()
{
    N *ptr; int ch;
    ptr= (N *)malloc(sizeof(N));
    if(start == NULL)
    {
        printf("\n There is no node in the list....");
        printf("\n If user want to create a new node then press 1\n Or else user want to quit then press anything..");
        printf("\n Enter your choice : ");
        scanf("%d", &ch);
        if(ch==1)
        {
            PushNode();
            return;
        }
        else
            return;
    }
    printf("Enter a new value in the value part of the new node : ");
    scanf("%d",&ptr->val);
    ptr->prev=NULL;
    ptr->next=start;
    start->prev=ptr;
    start=ptr;
}
void PopNode()
{
    if(start == NULL)
    {
        printf("List Is Already Empty!\n");
        return;
    }
    if(start->next== NULL)
    {
        int ch;
        printf("\n There is no node in the list....");
        printf("\n If you want to pop this only node then press 1\n Or else you want to quit then press anything..");
        printf("\n Enter your choice : ");
        scanf("%d", &ch);
        if(ch==1)
        {
            free(start);
            start==NULL;
            last=NULL;
            return;
        }
        else
            return;
    }
    N *tmp=last->prev;
    free(last);
    tmp->next=NULL;
    last=tmp;
}
void PopFirst()
{
    if(start == NULL)
    {
        printf("List Is Already Empty!\n");
        return;
    }
    if(start->next== NULL)
    {
        free(start);
        start==NULL;
        last=NULL;
        return;
    }
    N *tmp=start, *ptr;
    tmp=tmp->next;
    free(start);
    start=tmp;
}
void PushAfter() 
{
    int ch;
    N *ptr=(N *)malloc(sizeof(N));
    printf("Enter a value in the new node : ");
    scanf("%d",&ptr->val);
    printf("Enter a value : ");
    scanf("%d", &ch);
    if(last->val == ch) {
        last->next=ptr;
        ptr->prev=last;
        ptr->next=NULL;
        last=ptr;
        return;
    }
    N *tmp=start, *tmp2;
    while(tmp->val != ch ) {
        tmp=tmp->next;
    }
    tmp2=tmp->next;
    tmp->next=ptr;
    ptr->prev=tmp;
    ptr->next=tmp2;
}
void PushBefore()
{
    int ch;
    N *ptr=(N *)malloc(sizeof(N));
    printf("Enter a value from the list before which you want to insert node : ");
    scanf("%d", &ch);
    if(start==NULL) {
        printf("List is empty..");
        return;
    }
    if(start->val == ch) {
        PushFirst();
        return;
    }
    else {
        printf("Enter a value in the new node : ");
        scanf("%d",&ptr->val);
        N *tmp =start, *tmp2;
        while (tmp->val != ch)
        {
            tmp=tmp->next;
        }
        tmp2=tmp->prev;
        tmp2->next=ptr;
        ptr->prev=tmp2;
        ptr->next=tmp;
    }
}
void PopAfter() 
{
    int ch,c;
    if(start==NULL) {
        printf("List is empty..");
        return;
    }
    printf("Enter a value from the list After which you want to pop node : ");
    scanf("%d", &ch);
    if(start->val == ch && start->next==NULL) {
        printf("\nThere is no node after that you choose ");
        printf("\nIf you want pop only this node then press 1.");
        scanf("%d", &c);
        if(c==1){
            PopFirst();
            return;
        }
        return;
    }
    if(last->val ==ch){
        printf("There is no node after that."); return;
    }   
    if(last->prev->val == ch) {
        N*tmp=last;
        last=tmp->prev;
        free(tmp);
        return;
    }
    N *tmp1= start, *ptr;
    while(tmp1->val != ch)
    {
        tmp1=tmp1->next;
    }
    ptr=tmp1->next;
    tmp1->next=ptr->next;
    N *tmp2= ptr->next;
    tmp2->prev=tmp1;
    free(ptr);
}
void PopBefore()
{
    int ch;
    if(start==NULL) {
        printf("List is empty..");
        return;
    }  
    printf("Enter a value from the list before which you want to pop node : ");
    scanf("%d", &ch);
    if (start->next->val == ch) {
        N *tmp=start;
        start=tmp->next;
        free(tmp);
        return;
    } 
    N *tmp=start;
    while(tmp->val != ch) {
        tmp=tmp->next;
    }

}
void PrintClockwise()
{
    if(start == NULL && last == NULL)
    {
        printf("The list is totally empty...\nThere is nothing to print");
        return;
    }
    int choice;
    int i;
    printf("Enter how many time you want to print the list. ");
    scanf("%d", &choice);
    start->prev=last;
    last->next=start;
    N *tmp=start;
    for(i=0 ; i<choice ; i++)
    {
        printf("%d-> ", tmp->val);
        tmp=tmp->next;
    }
    start->prev= NULL;
    last->next= NULL;
}
void PrintAntiClockwise()
{
    if(start == NULL && last == NULL)
    {
        printf("The list is totally empty...\nThere is nothing to print");
        return;
    }
    int choice,i;
    printf("Enter how many time you want to print the list. ");
    scanf("%d", &choice);
    start->prev=last;
    last->next=start;
    N *tmp=last;
    for(i=0 ; i<choice ; i++)
    {
        printf("%d-> ", tmp->val);
        tmp=tmp->prev;
    }
    start->prev= NULL;
    last->next= NULL;
}
void PrintForward()
{
    if(start == NULL && last == NULL)
    {
        printf("The list is totally empty...\nThere is nothing to print");
        return;
    }
    N* ptr=start;
    while (ptr != NULL)
    {
        printf("%d-> ",ptr->val);
        ptr=ptr->next;
    }
}
void PrintBackward()
{
    if(start == NULL && last == NULL)
    {
        printf("The list is totally empty...\nThere is nothing to print");
        return;
    }
    N* tmp=last;
    while (tmp != NULL)
    {
        printf("%d-> ",tmp->val);
        tmp=tmp->prev;
    }
}

int main()
{
    int choice;
    int ctr;
    do
    {
        ctr=1;
        printf("\n -: M E N U :-\n  -----------------------");
        printf("\n %d.... Push a new node.", ctr++);
        printf("\n %d.... Push a new node at first.", ctr++);
        printf("\n %d.... Pop a node.", ctr++);
        printf("\n %d.... Pop a new node at first.", ctr++);
        printf("\n %d.... Push a node after a given node.", ctr++);
        printf("\n %d.... Push a node before a given node.", ctr++);
        printf("\n %d.... Pop a node after a given node ", ctr++);
        printf("\n %d.... Pop a node before a given node ", ctr++);
        printf("\n %d.... Print the list clockwise according to the user", ctr++);
        printf("\n %d.... Print the list Anti clockwise according to the user", ctr++);
        printf("\n %d.... Print the list Forward.", ctr++);
        printf("\n %d.... print the list backward", ctr++);
        printf("\n 0.... Exiting the program.......");
        printf("\n Enter a choice you want : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:PushNode();
            break;
        case 2:PushFirst();
            break;
        case 3:PopNode();
            break;
        case 4:PopFirst();
            break;
        case 5:PushAfter();
            break;
        case 6:PopBefore();
            break;
        case 7:PushBefore();
            break;
        case 8:PopAfter();
            break;
        case 9:PrintClockwise();
            break;
        case 10:PrintAntiClockwise();
            break;
        case 11:PrintForward();
            break;
        case 12:PrintBackward();
            break;
        }
    } while (choice != 0);
}