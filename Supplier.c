
#include "Supplier.h"

bool del_Supplier( Supplier * curr){
    FREE(curr->supplier_name);
    FREE(curr);
    return true;
}

Supplier * supplier_constructor() {
    bool flag = true;
    char supplier_number[SUPPLIER_NUMBER];
    char supplier_name[MAX_OF_STRING];
    char supplier_phone[SUPPLIER_PHONE];
    char number_of_deal[NUMBER_OF_DEAL];
    char sum_of_deal[SUM_OF_DEAL];
    int i = 0;
    Supplier * p_input_supplier = NULL;

    printf("number=N , char=C:\n");
    printf("If the sign is -M_SIZE- you can enter up to number!\n");
    printf("If the mark is N or C- enter the -exact- number:\n");


    while (i <= 4) {
        switch (i) {
            case 0:
                while (flag == true) {
                    printf("enter supplier_number --N 10-- :\n");
                    scanf("%s", supplier_number);
                    if (stringSize(supplier_number) > SUPPLIER_NUMBER - 1 || !contains_only_digits(supplier_number)) {
                        printf("supplier_number Exceeding the normal input size\n Or the input does not contain only digits\n");
                        flag = true;
                    } else {
                        flag = false;
                    }
                }
                i++;
                break;
            case 1:
                flag = true;
                while (flag == true) {
                    printf("enter supplier_name No more than 1024 ch \n");
                    scanf("%s", supplier_name);
                    if (!contains_only_letters(supplier_name) || stringSize(supplier_name) > MAX_OF_STRING - 1) {
                        printf(" the input does not contain only letters\n");
                        flag = true;
                    } else {
                        flag = false;
                    }
                }
                i++;
                break;
            case 2:
                flag = true;
                while (flag == true) {
                    printf("enter  supplier_phone :--N  10--\n");
                    scanf("%s", supplier_phone);
                    if (stringSize(supplier_phone) > SUPPLIER_PHONE - 1 || !contains_only_digits(supplier_phone)) {
                        printf("supplier_phone Exceeding the normal input size\n Or the input does not contain only digits");
                        flag = true;
                    } else {
                        flag = false;
                    }
                }
                i++;
                break;
            case 3:
                flag = true;
                while (flag == true) {
                    printf("enter number_of_deal : --N 5--\n");
                    scanf("%s", number_of_deal);
                    if (stringSize(number_of_deal) > NUMBER_OF_DEAL - 1 || !contains_only_digits(number_of_deal)) {
                        printf("num_of_deal Exceeding the normal input size \n Or the input does not contain only digits");
                        flag = true;
                    } else {
                        flag = false;
                    }
                }
                i++;
                break;
            case 4:
                flag = true;
                while (flag == true) {
                    printf("enter sum of deal : --N 10--: \n");
                    scanf("%s", sum_of_deal);
                    if (stringSize(sum_of_deal) > SUM_OF_DEAL - 1 || !contains_only_digits(sum_of_deal)) {
                        printf("date_of_rent Exceeding the normal input size\n Or is not valid date\n");
                        flag = true;
                    } else {
                        flag = false;
                    }
                }
                i++;
                break;
            default:
                printf("you miss data");
        }
    }



    strcpy(p_input_supplier->supplier_number, supplier_number);
    p_input_supplier->supplier_name = str_dup(supplier_name);
    strcpy(p_input_supplier->supplier_phone, supplier_phone);
    strcpy(p_input_supplier->sum_of_deal, sum_of_deal);
    strcpy(p_input_supplier->number_of_deal, number_of_deal);

    return p_input_supplier;
}


