#include "apc.h"

static void print_signed_result(int sign, node *head)
{
    if (is_zero_list(head))
    {
        printf("0\n");
        return;
    }

    if (sign < 0)
    {
        printf("-");
    }

    print_list(head);
}

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;
    int sign1, sign2, ret, result_sign;

    // Validation
	if(cla_validation(argc,argv)==FAILURE)
		return 0;


    // Create 2 lists of operands
	create_list(argv[1],&head1,&tail1);
	create_list(argv[3],&head2,&tail2);
    remove_pre_zeros(&head1);
    remove_pre_zeros(&head2);
    sign1 = get_operand_sign(argv[1]);
    sign2 = get_operand_sign(argv[3]);


    // Remove pre zeros

    char oper = argv[2][0];
	
    switch(oper)
    {
		case '+':
                if(sign1 == sign2)
                {
                    addition(tail1, tail2,&headR, &tailR);
                    remove_pre_zeros(&headR);
                    print_signed_result(sign1, headR);
                }
                else
                {
                    ret = compare_list(head1,head2);
                    if(ret == OPERAND1)
                    {
                        subtraction(tail1,tail2,&headR,&tailR);
                        remove_pre_zeros(&headR);
                        print_signed_result(sign1, headR);
                    }
                    else if(ret == OPERAND2)
                    {
                        subtraction(tail2,tail1,&headR,&tailR);
                        remove_pre_zeros(&headR);
                        print_signed_result(sign2, headR);
                    }
                    else
                    {
                        printf("0\n");
                    }
                }
			break;

		case '-':
				{
                if(sign1 != sign2)
                {
                    addition(tail1, tail2,&headR, &tailR);
                    remove_pre_zeros(&headR);
                    print_signed_result(sign1, headR);
                }
                else
                {
				    ret=compare_list(head1,head2);
				    if(ret==OPERAND1)
				    {
					    subtraction(tail1,tail2,&headR,&tailR);
                        remove_pre_zeros(&headR);
                        print_signed_result(sign1, headR);
				    }
				    else if(ret==OPERAND2)
				    {
					    subtraction(tail2,tail1,&headR,&tailR);
                        remove_pre_zeros(&headR);
                        result_sign = (sign1 == 1) ? -1 : 1;
                        print_signed_result(result_sign, headR);
				    }
				    else if(ret==SAME)
				    {
					    printf("0\n");
				    }
                }

			break;
			}

		case '*':
		case 'x':
		case 'X':multiplication(tail1,tail2,&headR,&tailR);
                remove_pre_zeros(&headR);
                result_sign = (sign1 == sign2) ? 1 : -1;
                print_signed_result(result_sign, headR);
			break;

		case '/':division(head1,head2,tail2,&headR, &tailR);
                remove_pre_zeros(&headR);
                result_sign = (sign1 == sign2) ? 1 : -1;
                print_signed_result(result_sign, headR);
			break;

		default:
			printf("Invalid operator\n");
			break;
    }
}
