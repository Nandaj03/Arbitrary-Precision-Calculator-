#include "apc.h"

/*multiplication function*/
void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *temp1=tail1,*temp2=tail2;
    node *headR2=NULL,*tailR2=NULL,*head_AR=NULL,*tail_AR=NULL;
    int carry=0,flag=0,zero_flag=0;
    while(temp2)
    {
        headR2=NULL;
        tailR2=NULL;
        for(int i=0;i<zero_flag;i++)
            insert_first(&headR2,&tailR2,0);
        carry=0;

        while(temp1)
        {
            int res;
            res=temp1->data * temp2->data + carry;
            carry=res/10;
            if(!flag)
                insert_first(headR,tailR,res%10);
            else
            {
                insert_first(&headR2,&tailR2,res%10);
            }
            temp1=temp1->prev;
            
        }
        if(carry)
        {
            if(!flag)
                insert_first(headR,tailR,carry);
            else
                insert_first(&headR2,&tailR2,carry);
        }
        if(flag)
        {
        head_AR=NULL;
        tail_AR=NULL;
        addition(*tailR,tailR2,&head_AR,&tail_AR);
        delete_list(headR,tailR);
        delete_list(&headR2,&tailR2);
        *headR=head_AR;
        *tailR=tail_AR;
        head_AR=NULL;
        tail_AR=NULL;
        }
        temp2=temp2->prev;
        zero_flag++;
        temp1=tail1;
        flag=1;
    }
}
