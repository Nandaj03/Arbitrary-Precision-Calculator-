#include "apc.h"

void division(node *head_L1, node *head_op2,node *tail_op2, node **headR, node **tailR)
{
    node *head_op1=NULL,*tail_op1=NULL,*L1_temp=head_L1,*head_SR=NULL,*tail_SR=NULL;
    int sub_count=0;
    if (head_op2 == NULL || (head_op2->data == 0 && head_op2->next == NULL))
    {
        printf("ERROR: Division by zero\n");
        return;
    }
    if(compare_list(head_L1,head_op2)==OPERAND2)
        {
            insert_first(headR,tailR,0);
            return;
        }
    insert_last(&head_op1,&tail_op1,L1_temp->data);
        L1_temp=L1_temp->next;
    while(head_op1)
    {
    while(compare_list(head_op1,head_op2)==OPERAND2)
    {
        if(L1_temp==NULL)
            break;
        insert_last(&head_op1,&tail_op1,L1_temp->data);
        L1_temp=L1_temp->next;

    }
    sub_count=0;
    while(compare_list(head_op1,head_op2)==OPERAND1 || compare_list(head_op1,head_op2)==SAME )
    {
        subtraction(tail_op1,tail_op2,&head_SR,&tail_SR);
        sub_count++;
        delete_list(&head_op1,&tail_op1);
        head_op1=head_SR;
        tail_op1=tail_SR;
        head_SR= NULL;
        tail_SR=NULL;
        remove_pre_zeros(&head_op1);
    }
    insert_last(headR,tailR,sub_count);
    if(L1_temp==NULL)
        break;
    }

    printf("remainder=");
    if(head_op1)
    {
    print_list(head_op1);
    }
    else    printf("0\n");


    
}
void remove_pre_zeros(node **head)
{
    node *temp=*head;
    if(*head==NULL)
        return;
    while(temp && temp->data==0 && temp->next)
    {
        *head=temp->next;
        (*head)->prev=NULL;
        free(temp);
        temp=*head;

    }

}

