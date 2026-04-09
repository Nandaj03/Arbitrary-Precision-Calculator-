#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SUCCESS		1
#define FAILURE		0

#define SAME		0
#define OPERAND1	1
#define OPERAND2	2

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}node;

/*addition funtion*/
void addition(node *tail1, node *tail2, node **headR, node **tailR);
/*substraction function*/
void subtraction(node *tail1, node *tail2, node **headR, node **tailR);
/*multiplication function*/
void multiplication(node *tail1, node *tail2, node **headR, node **tailR);
/*division function*/
void division(node *head1, node *head2,node *tail2, node **headR, node **tailR);

/*validation function*/
int cla_validation(int argc, char *argv[]);
/*list creation function*/
void create_list(char *opr, node **head, node **tail);
/*Function to get the sign of the operand*/
int get_operand_sign(const char *opr);
/*to check the list is zero*/
int is_zero_list(node *head);

/*Insert the node in first position*/
int insert_first(node **head, node **tail, int data);
/*insert the node in last position*/
int insert_last(node **head, node **tail, int data);
/*to delete the list*/
int delete_list(node **head, node **tail);
/*to print the list*/
void print_list(node *head);

/*to compare two lists*/
int compare_list(node *head1, node *head2);
/*to get the lenght of the list*/
int list_len(node *head);
/*to remove prezeros in the list*/
void remove_pre_zeros(node **head);
/*To print the sign along with the result*/
void print_signed_result(int sign, node *head);



#endif
