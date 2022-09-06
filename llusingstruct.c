#include<stdio.h>
#include<stdlib.h>

void display();

struct node{

    int data;
    struct node *next;
}*head = NULL,*new,*temp;


int main(){

    int n,i;
    printf("--Program to Print Natural Number using Linked List--");
    printf("\n Enter a Natural Number: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        new=(struct node*)malloc(sizeof(struct node));

        printf("%d ",i);

        new->data=i;
        new->next=NULL;

        if(head==NULL)
        {
            head=new;
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            temp=temp->next;
            temp->next=new;
        }
    }
        display();

        return 0;
}
 void display()
    {
            temp=head;
            printf("\nThe linked list is:\n");
            while(temp!=NULL)
            {
                printf("%d->",temp->data);
                temp=temp->next;
            }
    }
