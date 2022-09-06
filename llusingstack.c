#include<stdio.h>
#include<stdlib.h>

void display();

struct node{

    int data;
    struct node *next;

}*top=NULL,*temp,*new;

int main(){

    int n,i;

    printf("--Program to Print Natural Number using Linked List");

    printf("\nEnter a Natural Number: ");
    scanf("%d",&n);



    for(i=1;i<=n;i++){

        new = (struct node *)malloc(sizeof(struct node));

        new->data=i;
        new->next=NULL;

        printf("%d ",i);

        if(top==NULL)
        {
            top=new;

        }
        else
        {
            temp=top;
            while(temp->next!=NULL)
                temp=temp->next;
                temp->next = new;
        }
    }

    display();

    return 0;
}
void display(){

        temp=top;

        printf("\nThe linked list is:\n");

        while(temp!=NULL){
            printf("%d->",temp->data);
            temp = temp->next;
    }
}
