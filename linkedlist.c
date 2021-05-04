#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  


void begininginsert();
void endinsert();
void randominsert();
void beginingdelete();
void enddelete();
void randomdelete();
void display();
void search();

void main()
{
    int selector=0;
    int choice=0;
    while(selector!=4)
    {
        printf("\n*************************Main Menu**********************\n");
        printf("\nChoose an option\n\n\n");
        printf("\n1.Insert\n");
        printf("\n2.Delete\n");
        printf("\n3.Display\n");
        printf("\n4.Exit\n");
        scanf("%d",&selector);

        switch(selector)
        {
            case 1:
                printf("\nYou have chose to insert element\n");
                printf("\n1.Insert at beginning\n");
                printf("\n2.Insert at the end\n");
                printf("\n3.Insert at random location\n");
                printf("\n4.Back\n\n");
                scanf("%d",&choice);

                switch (choice)
                {
                    case 1:
                        begininginsert();
                        break;
                    case 2:
                        endinsert();
                        break;
                    case 3:
                        randominsert();
                        break;
                    default:
                        continue;
                }
                break;

            case 2:
                printf("\nYou have chose to delete an element\n");
                printf("\n1.Delete from beginning\n");
                printf("\n2.Delete from the end\n");
                printf("\n3.Delete from random location\n");
                printf("\n4.Back\n\n");
                scanf("%d",&choice);

                switch (choice)
                {
                    case 1:
                        beginingdelete();
                        break;
                    case 2:
                        enddelete();
                        break;
                    case 3:
                        randomdelete();
                        break;
                    default:
                        continue;
                }
                break;

            case 3:
                printf("\nYou have chose to display an element\n");
                printf("\n1.Display full list\n");
                printf("\n2.Search element\n");
                printf("\n3.Back\n\n");
                scanf("%d",&choice);

                switch (choice)
                {
                    case 1:
                        display();
                        break;
                    case 2:
                        search();
                        break;
                    default:
                        continue;
                }
                break;

            case 4:
                return;

            default:
                printf("\nplease enter a valid choice\n");
        
        }
    choice=0;
    selector=0;
    }
}

void begininginsert()
{
    struct node *ptr;
    int i;
    ptr= (struct node *) malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("Overflow");
    }
    else
    {
        printf("\nEnter Value\n");
        scanf("%d",&i);
        ptr->data=i;
        ptr->next=head;
        head=ptr;
        printf("\nElement inserted\n");
    }
}

void endinsert()
{
    struct node *ptr,*temp;
    int i;
    ptr= (struct node *) malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("Overflow");
    }
    else
    {
        printf("\nEnter Value\n");
        scanf("%d",&i);
        ptr->data=i;
        if(head == NULL)
        {
            ptr->next = NULL;
            head=ptr;
            printf("\nNode inserted\n");
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
            printf("\nElement inserted\n");
        }
    }
}
void randominsert()
{
    int i,loc,item;   
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter element value");  
        scanf("%d",&item);  
        ptr->data = item;  
        printf("\nEnter the location after which you want to insert ");  
        scanf("\n%d",&loc);  
        temp=head;  
        for(i=0;i<loc;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("\ncan't insert\n");  
                return;  
            }  
          
        }  
        ptr ->next = temp ->next;   
        temp ->next = ptr;   
        printf("\nNode inserted");  
    }  
}
void beginingdelete()
{
     struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        ptr = head;  
        head = ptr->next;  
        free(ptr);  
        printf("\nNode deleted from the begining ...\n");  
    }  
}

void enddelete()
{
     struct node *ptr,*ptr1;  
    if(head == NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nOnly node of the list deleted ...\n");  
    }  
          
    else  
    {  
        ptr = head;   
        while(ptr->next != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
        printf("\nDeleted Node from the last ...\n");  
    }     
}

void randomdelete()
{
    struct node *ptr,*ptr1;  
    int loc,i;    
    printf("\n Enter the location of the node after which you want to perform deletion \n");  
    scanf("%d",&loc);  
    ptr=head;  
    for(i=0;i<loc;i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->next;  
              
        if(ptr == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    ptr1 ->next = ptr ->next;  
    free(ptr);  
    printf("\nDeleted node %d ",loc+1);  
}  
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("item found at location %d ",i+1);  
                flag=0;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("Item not found\n");  
        }  
    }     
}

void display()
{
     struct node *ptr;  
    ptr = head;  
    printf("\nValue        Present Address       Next Address\n");
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {    
        while (ptr!=NULL)  
        {     
    printf("\n%d           %d              %d\n",ptr->data,ptr,ptr-> next);
            ptr = ptr -> next; 
        }  
    }  
}

