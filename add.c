#include "apc.h"

/*Addition function*/
void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *temp1=tail1,*temp2=tail2;
    int carry=0,res=0;
    while(temp1 && temp2)
    {
        res=temp1->data + temp2->data + carry;
        insert_first(headR,tailR,res%10);
        carry=res/10;

        temp1=temp1->prev;
        temp2=temp2->prev;
    }

    while(temp1)
    {
        res=temp1->data+ carry;
        insert_first(headR,tailR,res%10);
        carry=res/10;

        temp1=temp1->prev;
    }
    while(temp2)
    {
        res=temp2->data + carry;
        insert_first(headR,tailR,res%10);
        carry=res/10;

        temp2=temp2->prev;
    }
    if(carry)
    {
        insert_first(headR,tailR,carry);
    }
    
}
