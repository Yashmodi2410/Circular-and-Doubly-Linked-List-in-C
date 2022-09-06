#include<stdio.h>
#include<stdlib.h>

void insert(int a);
void display();

struct node{

    int data;

    struct node *next;

}*head=NULL,*tail=NULL,*temp,*new;

void insert(int a){

       new=(struct node*)malloc(sizeof(struct node));

        new->data=a;
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


int main(){

    int n,*a,i;


    a = (int *)malloc(n * sizeof(int));

    printf("--Program to Print Natural Numbers using array");

    printf("\nEnter a Number: ");
    scanf("%d: ",&n);

    printf("Elements in array are: ");
    for(i=1;i<=n;i++){

        a[i] = i;
        printf("%d ",a[i]);
        insert(a[i]);
    }
    display();

    return 0;
}

