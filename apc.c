#include "apc.h"
#include<ctype.h>
/*To validate the command line arguments*/
int cla_validation(int argc, char *argv[])
{
    if(argc!=4)
    {
        printf("INVALID INPUT\n");
        printf("./a.out <operand1><operator><operand2>\n");
        return FAILURE;
    }
    for(int i=1;i<=3;i+=2)
    {
        int j=0;
        if(argv[i][0]=='-' || argv[i][0]=='+')
        {
            if(argv[i][1]=='\0')
            {
                printf("INVALID INPUT\n");
                return FAILURE;
            }
            j=1;
        }

        for(;argv[i][j];j++)
        {
            if(!isdigit(argv[i][j]))
            {
                printf("INVALID INPUT\n");
                return FAILURE;
            }
        }
    }
    
    if(argv[2][1]!='\0')
    {
        printf("operator invalid\n");
        return FAILURE;
    }

    char ch=argv[2][0];
    if(ch!='+' && ch!='-' && ch!='x' && ch!='X' && ch!='*' && ch!='/')
        {
            printf("INVALID OPERATOR\n");
            return FAILURE;
        }
    return SUCCESS;
}
/*function to create list*/
void create_list(char *opr, node **head, node **tail)
{
    int i=0;
    if(opr[i] == '+' || opr[i] == '-')
    {
        i = 1;
    }
    while(opr[i])
    {
        char ch=opr[i]-'0';
        insert_last(head,tail,ch);
        i++;
    }    
}
/*to get the sign of the operand*/
int get_operand_sign(const char *opr)
{
    if(opr[0] == '-')
    {
        return -1;
    }
    return 1;
}

/*the insert the node in the first*/
int insert_first(node **head, node **tail, int data)
{
    node *new=malloc(sizeof(node));
    if(new==NULL)
    {
        return FAILURE;
    }
    new->prev=NULL;
    new->data=data;
    new->next=NULL;
    if(*head==NULL)
    {
        *head=new;
        *tail=new;
        return SUCCESS;
    }
    else
    {
        new->next=*head;
        (*head)->prev=new;
        *head=new;
        return SUCCESS;
    }

}
/*to insert the node in the last*/
int insert_last(node **head, node **tail, int data)
{
    node *new=malloc(sizeof(node));
    if(new==NULL)
    {
        return FAILURE;
    }
    new->prev=NULL;
    new->data=data;
    new->next=NULL;
    
    if(*head==NULL)
    {
        *head=new;
        *tail=new;
        return SUCCESS;
    }
    else
    {
        (*tail)->next=new;
        new->prev=*tail;
        *tail=new;
        return SUCCESS;
    }
}

/*to print the list*/
void print_list(node *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
		    // if (head)
		    //     printf("> ");
	    }
    }
    printf("\n");
}
/*to check if the list is zero*/
int is_zero_list(node *head)
{
    if(head == NULL)
    {
        return 1;
    }

    while(head)
    {
        if(head->data != 0)
        {
            return 0;
        }
        head = head->next;
    }
    return 1;
}

/*to delete the list*/
int delete_list(node **head, node **tail)
{
    if(*head==NULL)
    {
        printf("List is empty\n");
        return FAILURE;
    }
    node *temp1=*head;
    node *temp2=NULL;
    
    temp2=temp1->next;
    *head=NULL;
    *tail=NULL;
    while(temp2)
    {
        temp1->next=NULL;
        free(temp1);
        temp1=temp2;
        temp2=temp2->next;
    }
    free(temp1);
    temp1=NULL;
    return SUCCESS;
}
