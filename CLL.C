
/* Code Copyright by © Aakash Parmar*/

#include<stdio.h>
#include<conio.h>
#include<process.h>

struct node
{
    int data;
    struct node *next;
}*head=NULL,*temp,*new,*temp1;



    int ch;
    void insert_beg();
    void insert_end();
    int insert_pos();
    void display();
    void delete_beg();
    void delete_end();
    int delete_pos();
    int cont=1;
int main()
{
	clrscr();
    do
    {
	printf("\n\n---- Circular Linked List(CLL) Menu ----");
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
	printf("\n do you want to  continue(1/0):");
	scanf("%d",&cont);
    }while(cont==1);
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

	head=new;
	new->next=head;
    }
    else
    {
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;

	}
	temp->next=new;
	new->next=head;
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


    if(head==NULL)        //If list is empty
    {
	head=new;
	new->next=head;
    }
    else
    {
	temp=head;
	while(temp->next!=head)
	{
	temp=temp->next;
	}
	temp->next=new;
	new->next=head;
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

    temp=head;
    for(i=1;i<pos-1;i++)
    {
	if(temp->next==head)
	{
	    printf("There are less elements!!");
	    return 0;
	}

	temp=temp->next;
    }

    new->next=temp->next;
    temp->next=new;
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
	while(temp->next!=head)
	{
	    printf("%d->",temp->data);
	    temp=temp->next;
	}
	printf("%d->",temp->data);
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
	while(temp->next!=head)
	{
	temp=temp->next;
	}
	temp->next=head->next;
	temp1=head;
	head=head->next;
	printf("Deleted element is %d",temp1->data);
	free(temp1);
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
	while(temp->next->next!=head)
	{
	temp=temp->next;
	 }
	new=temp->next;
	temp->next=head;
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
	if(temp->next==head)
	{
	    printf("There are less elements!!");
	    return 0;
	}
	temp=temp->next;
    }

    new=temp->next;
    temp->next=new->next;
    printf("Deleted element is %d",new->data);
    free(new);

    return 0;
}