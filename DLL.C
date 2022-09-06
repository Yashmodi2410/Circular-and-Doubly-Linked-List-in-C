

#include<stdio.h>
/* Code Copyright by © Aakash Parmar*/

#include<conio.h>
#include<process.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL,*temp,*new,*temp1;

int main()
{
    int ch;
    void insert_beg();
    void insert_end();
    int insert_pos();
    void display();
    void delete_beg();
    void delete_end();
    int delete_pos();

    while(1)
    {
	printf("\n\n---- Doubly Linked List(DLL) Menu ----");
	printf("\n1.Insert\n2.Display\n3.Delete\n4.Exit\n\n");
	printf("Enter your choice(1-4):");
	scanf("%d",&ch);

	switch(ch)
	{
	    case 1:
		    printf("\n---- Insert Menu ----");
		    printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at specified position\n4.Exit");
		    printf("\n\nEnter your choice(1-4):");
		    scanf("%d",&ch);

		    switch(ch)
		    {
			case 1: insert_beg();
				break;
			case 2: insert_end();
				break;
			case 3: insert_pos();
				break;
			case 4: exit(0);
			default: printf("Wrong Choice!!");
		    }
		    break;

	    case 2: display();
		    break;

	    case 3: printf("\n---- Delete Menu ----");
		    printf("\n1.Delete from beginning\n2.Delete from end\n3.Delete from specified position\n4.Exit");
		    printf("\n\nEnter your choice(1-4):");
		    scanf("%d",&ch);

		    switch(ch)
		    {
			case 1: delete_beg();
				break;
			case 2: delete_end();
				break;
			case 3: delete_pos();
				break;
			case 4: exit(0);
			default: printf("Wrong Choice!!");
		    }
		    break;
	    case 4: exit(0);
		    default: printf("Wrong Choice!!");
	}
    }
    return 0;
}

void insert_beg()
{
    int num;
    new=(struct node*)malloc(sizeof(struct node));
    printf("sEnter data:");
    scanf("%d",&num);
    new->data=num;
    

    if(head==NULL)        //If list is empty
    {
	new->next=NULL;
    new->prev=NULL;
	head=new;
    }
    else
    {
	new->next=head;
	head->prev=new;
	new->prev=NULL;
	head=new;
	
    }
}

void insert_end()
{
    int num;
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    new->data=num;
    new->next=NULL;
    new->prev=NULL;

    if(head==NULL)        //If list is empty
    {
	head=new;
    }
    else
    {
	temp=head;
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=new;
	new->prev=temp;
    }
}

int insert_pos()
{
    int pos,i,num;
    if(head==NULL)
    {
	printf("List is empty!!");
	return 0;
    }

    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    printf("Enter position to insert:");
    scanf("%d",&pos);
    new->data=num;
    new->prev=NULL;
	new->next=NULL;

    temp=head;
    for(i=1;i<pos-1;i++)
    {
	if(temp->next==NULL)
	{
	    printf("There are less elements!!");
	    return 0;
	}

	temp=temp->next;
    }
	temp1=temp->next;
    new->next=temp1;
    temp1->prev=new;
    temp->next=new;
     new->prev=temp;
    return 0;
}

void display()
{
    if(head==NULL)
    {
	printf("List is empty!!");
    }
    else
    {
	temp=head;
	printf("The linked list is:\n");
	while(temp!=NULL)
	{
	    printf("%d->",temp->data);
	    temp=temp->next;
	}
    }
}

void delete_beg()
{
    if(head==NULL)
    {
	printf("The list is empty!!");
    }
    else
    {
	temp=head;
	head=head->next;
	head->prev=NULL;
	temp->next=NULL;
	printf("Deleted element is %d",temp->data);
	free(temp);
    }
}

void delete_end()
{
    if(head==NULL)
    {
	printf("The list is empty!!");
    }
    else
    {
	temp=head;
	while(temp->next->next!=NULL)
	temp=temp->next;

	new=temp->next;
	temp->next=NULL;
	new->prev=NULL;
	printf("Deleted element is %d",new->data);
	free(new);
    }
}

int delete_pos()
{
    int pos,i;

    if(head==NULL)
    {
	printf("List is empty!!");
	return 0;
    }

    printf("Enter position to delete:");
    scanf("%d",&pos);

    temp=head;
    for(i=1;i<pos-1;i++)
    {
	if(temp->next==NULL)
	{
	    printf("There are less elements!!");
	    return 0;
	}
	temp=temp->next;
    }

    temp=temp->next;
    
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    printf("Deleted element is %d",temp->data);
    free(temp);

    return 0;
}