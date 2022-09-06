#include<stdio.h>
#include<stdlib.h>

void display();

struct node{

    int data;

    struct node *next;

}*head = NULL,*temp = NULL,*new;;

int main(){

    int i,n;

    printf("--Program to print Natural number using Linked list--");

    printf("\nEnter a Natural Number: ");
    scanf("%d",&n);

    while(n>=1){
        head = (struct node*)malloc(sizeof(struct node));
        head->data = n;
        head->next = temp;
        temp = head;
        n--;
    }

    display();

    return 0;
}

void display()
    {
            temp = head;

            printf("\nThe linked list is:\n");
            while(temp!=NULL)
            {
                printf("%d->",temp->data);
                temp=temp->next;
            }
    }
