#include<stdio.h>
#include<stdlib.h>
struct Node {
    int val;
    struct Node *next;
};
typedef struct Node N;
N *start1=NULL,*start2=NULL, *end, *tmp,*ptr,*tmp1,*ptr1;

void CreateList(int);
void Display();
void Mergetwo();

void CreateList(int n) {
    ptr = (N *)malloc(sizeof(N));
    printf("Enter a value in the value part of the node: ");
    scanf("%d", &ptr->val);
    ptr->next = NULL;
    if(n==1){
        if (start1 == NULL) {
            start1 = ptr;
            tmp=ptr;
        }
        else {
            tmp->next=ptr;
            tmp=ptr;
        }
    }
    if(n==2){
        if (start2 == NULL) {
            start2 = ptr1;
            tmp1=ptr1;
            end=ptr1;
        }
        else {
            tmp1->next=ptr1;
            tmp1=ptr1;
            end=ptr1;
        }
    }
}

void Display() {
    printf("The 1st list is following :-\n");
    ptr = start1;
    while (ptr != NULL) {
        printf("%d-> ", ptr->val);
        ptr = ptr->next;
    }
    printf("\nThe 2nd list is following :-\n");
    ptr1 = start2;
    while (ptr1 != NULL) {
        printf("%d-> ", ptr1->val);
        ptr1 = ptr1->next;
    }
}

void Mergetwo() {
    int pos,c=1;
    printf("Enter position : ");
    scanf("%d",&pos);
    N *tmp2=start1;
    while(c<pos-1) {
        tmp2=tmp2->next;
        c++;
    }
    N *tmp3=tmp2->next;
    tmp2->next=start2;
    end->next=tmp3;
}

void main() {
    int ch;
    int ctr;
    do {
        ctr=1;
        printf("\n -: M E N U :-\n  -----------------------");
        printf("\n %d.... Create 1st List.", ctr++);
        printf("\n %d.... Create 2nd List.", ctr++);
        printf("\n %d.... Merge two list", ctr++);
        printf("\n %d.... Diplay two list.", ctr++);
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch (ch) {
        case 1: CreateList(1);
            break;
        case 2: CreateList(2);
            break;
        case 3: Mergetwo();
            break;
        case 4: Display();
            break;
        }
    } while (ch != 0);
}
    

