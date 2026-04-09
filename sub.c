#include "apc.h"

/*Substrcation function */
void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *temp1=tail1,*temp2=tail2;
    int res=0,borrow=0;
    while(temp2)
    {
        res = temp1->data - borrow;
        if(res < temp2->data)
        {
            res += 10;
            borrow=1;
        }
        else
        {
            borrow=0;
        }
        res = res - temp2->data;
        insert_first(headR,tailR,res);
        temp1=temp1->prev;
        temp2=temp2->prev;
    }
    while(temp1)
    {
        res = temp1->data - borrow;
        if(res < 0)
        {
            res += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        insert_first(headR,tailR,res);
       temp1=temp1->prev;
    }

}

/*Function to compare two lists using its head*/
int compare_list(node *head1, node *head2)
{
    int list1_len=list_len(head1);
    int list2_len=list_len(head2);
    if(list1_len>list2_len)
        return OPERAND1;
    else if(list1_len<list2_len)
        return OPERAND2;
    else
    {
        while(list1_len)
        {
            if(head1->data>head2->data)
                return OPERAND1;
            else if(head1->data<head2->data)
                return OPERAND2;
            head1=head1->next;
            head2=head2->next;
            list1_len--;
        }
        return SAME;
    }
}

/*to get the length of the list*/
int list_len(node *head)
{
    int len=0;
    while(head)
    {
        len++;
        head=head->next;
    }
    return len;
}
