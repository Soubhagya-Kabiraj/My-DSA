#include<stdio.h>
#include<stdlib.h>
struct Node {
    int co,ex;
    struct Node *next;
};
typedef struct Node N;
N *start1=NULL,*start2=NULL,*start3=NULL,*start4=NULL,*ptr,*tmp,*tmp0,*tmp1,*tmp2;

N *Create(int,int);
void Createpoly(int);
void Displaytwopoly(int);
void Addpoly();
void DisplayAddresult();
void Multiplypoly();
void DisplayMultiplyresult();

N *Create(int coff,int expo) {
    ptr=(N *)malloc(sizeof(N));
    ptr->co=coff;
    ptr->ex=expo;
    ptr->next=NULL;
    return ptr;
}

void Createpoly(int n) {
    int co,ex;
    printf(" Enter the value of the coefficient : ");
    scanf("%d",&co);
    printf(" Enter the value of the exponent :");
    scanf("%d",&ex);
    Create(co,ex);
    if(n==1) {
        if(start1==NULL) {
            start1=ptr;
            tmp1=ptr;
        }
        else {
            tmp1->next=ptr;
            tmp1=ptr;
        }
    }
    if(n==2) {
        if(start2==NULL) {
            start2=ptr;
            tmp2=ptr;
        }
        else {
            tmp2->next=ptr;
            tmp2=ptr;
        }
    }
}

void Displaytwopoly(int n) {
    if(n==1){
        printf(" The 1st polynomial expression is :-\n");
        tmp1=start1;
        while(tmp1!= NULL) {
            printf(" %dx^%d + ",tmp1->co,tmp1->ex);
            tmp1=tmp1->next;
            if(tmp1->next==NULL){
                printf(" %dx^%d ",tmp1->co,tmp1->ex);
                break;
            }
        }
        printf("\n The 2nd polynomial expression is :-\n");
        tmp2=start2;
        while(tmp2!= NULL) {
            printf(" %dx^%d + ",tmp2->co,tmp2->ex);
            tmp2=tmp2->next;
            if(tmp2->next==NULL){
                printf(" %dx^%d ",tmp2->co,tmp2->ex);
                return;
            }
        }
    }
    if(n==2){
        printf(" The 1st polynomial expression is :-\n");
        tmp1=start1;
        while(tmp1!= NULL) {
            printf(" %dx^%d * ",tmp1->co,tmp1->ex);
            tmp1=tmp1->next;
            if(tmp1->next==NULL){
                printf(" %dx^%d ",tmp1->co,tmp1->ex);
                break;
            }
        }
        printf("\n The 2nd polynomial expression is :-\n");
        tmp2=start2;
        while(tmp2!= NULL) {
            printf(" %dx^%d * ",tmp2->co,tmp2->ex);
            tmp2=tmp2->next;
            if(tmp2->next==NULL){
                printf(" %dx^%d ",tmp2->co,tmp2->ex);
                return;
            }
        }
    }
}

void Addpoly() {
    N *temp1=start1,*temp2=start2;
    int temp3;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->ex==temp2->ex){
            temp3=temp1->co+temp2->co;
            ptr=Create(temp3,temp1->ex);
            if(start3==NULL){                            
                start3=ptr;
                tmp=ptr;
            }
            else{
                tmp->next=ptr;
                tmp=ptr;
            }
        }
        else if(temp1->ex > temp2->ex || temp1->ex < temp2->ex) {
            while (temp2!=NULL && temp1->ex != temp2->ex){
                temp2=temp2->next;
                if(temp2==NULL){
                    temp3=temp1->co;
                    ptr=Create(temp3,temp1->ex);
                    if(start3==NULL) {
                        start3=ptr; 
                        tmp=ptr;
                    }
                    else {
                        tmp->next=ptr;
                        tmp=ptr;
                    }
                    break;
                }
            }
            if(temp2!=NULL) {
                temp3=temp1->co+temp2->co;
                ptr=Create(temp3,temp1->ex);
                if(start3==NULL) { 
                    start3=ptr; 
                    tmp=ptr;
                }
                else {
                    tmp->next=ptr;
                    tmp=ptr;
                }
            }
        }
        temp2=start2;
        temp1=temp1->next;
    }
}
       
void DisplayAddresult() {
    printf("\nThe addition result is following :-\n");
    ptr=start3;
    while (ptr!=NULL) {
        printf("%dx^%d + ",ptr->co,ptr->ex);
        ptr=ptr->next;
        if(ptr->next==NULL){
            printf("%dx^%d ",ptr->co,ptr->ex);
            return;
        }
    } 
}

void Multiplypoly() {
    N *temp1=start1,*temp2=start2;
    int temp3,temp4;
    while (temp1 != NULL){
        while (temp2 != NULL){
            temp3=temp1->co * temp2->co;
            temp4=temp1->ex + temp2->ex;
            ptr=Create(temp3,temp4);
            if(start4 == NULL){
                start4=ptr;
                tmp0=ptr;
            }
            else{
                tmp0->next=ptr;
                tmp0=ptr;
            }
            temp2=temp2->next;
        }
        temp2=start2;
        temp1=temp1->next;
    }   
}

void DisplayMultiplyresult(){
    N*ptr1=start4,*ptr2=start4->next;
    while(ptr1 != NULL){
        if(ptr1->ex == ptr2->ex){
            ptr1->co=ptr1->co+ptr2->co; 
            ptr1->next=ptr2->next;
            free(ptr2);
            break;
            ptr2=ptr1->next; 
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    printf("\nThe multiplication result is following :-\n");
    ptr=start4;
    while (ptr!=NULL) {
        printf("%dx^%d * ",ptr->co,ptr->ex);
        ptr=ptr->next;
        if(ptr->next==NULL){
            printf("%dx^%d ",ptr->co,ptr->ex);
            return;
        }
    } 

}

void main() {
    int ch,x,y;
    do {
        printf("\n -: M E N U :-\n ______________________");
        printf("\n 1.... Create 1st polynomial expression nodes. ");
        printf("\n 2.... Create 2nd Polynomial expression nodes. ");
        printf("\n 3.... Display two polynomial expression for addition. ");
        printf("\n 4.... Display two polynomial expression for multiplication. ");
        printf("\n 5.... Add two expression.");
        printf("\n 6.... Multiply two expression.");
        printf("\n 7.... Display the addition result. ");
        printf("\n 8.... Display the multiplication result. ");
        printf("\n 0.... Exiting the program. ");
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch) {
            case 1:Createpoly(1);
                break;                                                                                          
            case 2:Createpoly(2);
                break;
            case 3:Displaytwopoly(1);
                break;
            case 4:Displaytwopoly(2);
                break;
            case 5:Addpoly();
                break;
            case 6:Multiplypoly();
                break;
            case 7:DisplayAddresult();
                break;
            case 8:DisplayMultiplyresult();
                break;
            default: printf(" EXIT ");
        }
    }while(ch!=0);
}
       