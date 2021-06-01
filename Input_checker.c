

#include "Input_checker.h"
char* str_dup(const char * str){
    return strcpy(ALLOC(char ,strlen(str)+1),str);
}


/*Checks if the input consists of numbers*/
bool contains_only_digits(const char * str){
    int i=0;
    while (str[i]!='\0'){
        if(str[i] < 48 || str[i] > 57){
            return false;
        }
        i++;
    }
    return true;
}
/*Checks len of string*/
int stringSize(const char * str){
        int size=0;
        while(str[size]!='\0'){
            size++;
        }
        return size;
}

bool is_valid_date(const char * str){
    int i=0;
    while (str[i]!='\0'){
        if((str[i] < 48 || str[i] > 57)&&str[i]!='/'){
            return false;
        }
        i++;
    }
    return true;
}

bool is_valid_hour(const char* str){
    int i=0;
    while (str[i]!='\0'){
        if((str[i] < 48 || str[i] > 57)&&str[i]!=':'){
            return false;
        }
        i++;
    }
    return true;

}

/*Checks if the input consists of letters*/
bool contains_only_letters(const char * str){
    int i=0;
    while (str[i]!='\0'){
        if ((str[i] < 65 || str[i] > 90)&&(str[i] < 97 || str[i] > 122) ){
            return false;
        }
        i++;
    }
    return true;
}
/*
 char * pormalstr(char * str){
    int i=0;
    char  new_srt[strlen(str)];
    while (str[i]!='\0'){
        new_srt[i]=str[i];
        i++;
    }
    return new_srt;
}
 */

int trans_to_int(char * str){
        int x =atoi(str);
        return x;
}


bool isValid_car(const char*  license_number , char* chassis_number,char* manufacturer,
                 char* model,char* color,char* production_year, char* on_the_road_year,
                 char* buying_price,char* current_price,char* engine_capacity)
{
    int i;
    for (i=0; i <=9; ++i) {
        switch (i) {
            case 0:
                if (stringSize(license_number)!= LICENSE_NUMBER-1 || !contains_only_digits(license_number)){
                    printf( "license_number Exceeding the normal input size\n Or the input does not contain only digits\n");
                    return false;
                }
                break;
            case 1:
                if (stringSize(chassis_number)!= CHASSIS_NUMBER-1 || !contains_only_digits(chassis_number)) {
                    printf("chassis_number Exceeding the normal input size\n Or the input does not contain only digits\n");
                    return false;
                }
                break;
            case 2:
                if (stringSize(manufacturer)> MAX_OF_STRING-1 || !contains_only_letters(manufacturer)){
                    printf( "manufacturer Exceeding the normal input size\n Or the input does not contain only letters");
                    return false;
                }
                break;
            case 3:
                if (stringSize(model)> MAX_OF_STRING-1 ){
                    printf( "model Exceeding the normal input size");
                    return false;
                }
                break;
            case 4:
                if (stringSize(color)> MAX_OF_STRING-1 || !contains_only_letters(color)){
                    printf( "color Exceeding the normal input size\n Or the input does not contain only letters\n");
                    return false;
                }
                break;
            case 5:
                if (stringSize(production_year)!=PRODUCTION_YEAR-1 || !contains_only_digits(production_year)){
                    printf( "production_year Exceeding the normal input size\n Or the input does not contain only letters\n");
                    return false;
                }
                break;
            case 6:
                if (stringSize(on_the_road_year)!= ON_THE_ROAD_YEAR-1 || !contains_only_digits(on_the_road_year)){
                    printf( "on_the_road_year Exceeding the normal input size\n Or the input does not contain only letters\n");
                    return false;
                }
                break;
            case 7:
                if (stringSize(buying_price)>MAX_BUYING_PRICE-1  || !contains_only_digits(buying_price)){
                    printf( "buying_price Exceeding the normal input size \n Or the input does not contain only letters\n");
                    return false;
                }
                break;
            case 8:
                if (stringSize(current_price)> MAX_SIZE_MANUFACTURER-1 || !contains_only_digits(current_price)){
                    printf( "current_price Exceeding the normal input size \n Or the input does not contain only letters\n");
                    return false;
                }
                break;

            case 9:
                if (stringSize(engine_capacity)!= ENGINE_CAPACITY-1 || !contains_only_digits(engine_capacity)){
                    printf( "engine_capacity Exceeding the normal input size\n Or the input does not contain only digits\n");
                    return false;
                }
                break;
        }
    }
    return true;
}

bool isValid_client( char* first_name ,char* last_name ,char* id ,char* client_license_number ,char* date_of_rent ,char* hour_of_rent ,char* price_for_day){
    int i;
    for (i=0; i <=6; ++i) {
        switch (i) {
            case 0:
                if (stringSize(first_name)> MAX_OF_STRING-1 || !contains_only_letters(first_name)){
                    printf( "first name Exceeding the normal input size\n Or the input does not contain only letters\n");
                    return false;
                }
                break;
            case 1:
                if (stringSize(last_name)> MAX_OF_STRING-1 || !contains_only_letters(last_name)) {
                    printf("last name Exceeding the normal input size\n Or the input does not contain only letters\n");
                    return false;
                }
                break;
            case 2:
                if (stringSize(id)!= ID-1 || !contains_only_digits(id)){
                    printf( "id Exceeding the normal input size\n Or the input does not contain only digits");
                    return false;
                }
                break;
            case 3:
                if (stringSize(client_license_number)!= CLIENT_LICENSE_NUMBER-1|| !contains_only_digits(client_license_number)){
                    printf( "client_license_number Exceeding the normal input size \n Or the input does not contain only digits");
                    return false;
                }
                break;
            case 4:
                if (stringSize(date_of_rent)!= DATE_OF_RENT -1 || !is_valid_date(date_of_rent)){
                    printf( "date_of_rent Exceeding the normal input size\n Or is not valid date\n");
                    return false;
                }
                break;
            case 5:
                if (stringSize(hour_of_rent)!= HOUR_OF_RENT-1 || !is_valid_hour(hour_of_rent)){
                    printf( "hour_of_rent Exceeding the normal input size\n Or is not valid hour\n");
                    return false;
                }
                break;
            case 6:
                if (stringSize(price_for_day)> PRICE_FOR_DAY-1 || !contains_only_digits(price_for_day)){
                    printf( "price_for_day Exceeding the normal input size\n Or the input does not contain only digits\n");
                    return false;
                }
                break;
        }
    }
    return true;
}
bool isValid_supplier(char* supplier_number ,char* supplier_name ,char* supplier_phone, char* num_of_deal ,char* sum_of_deal){
    int i;
    for (i=0; i <=4; ++i) {
        switch (i) {
            case 0:
                if (stringSize(supplier_number)> SUPPLIER_NUMBER-1 || !contains_only_digits(supplier_number)){
                    printf( "supplier_number Exceeding the normal input size\n Or the input does not contain only digits\n");
                    return false;
                }
                break;
            case 1:
                if (!contains_only_letters(supplier_name)|| stringSize(supplier_name)>MAX_OF_STRING-1) {
                    printf(" the input does not contain only letters\n");
                    return false;
                }
                break;
            case 2:
                if (stringSize(supplier_phone)> SUPPLIER_PHONE-1 || !contains_only_digits(supplier_phone)){
                    printf( "supplier_phone Exceeding the normal input size\n Or the input does not contain only digits");
                    return false;
                }
                break;
            case 3:
                if (stringSize(num_of_deal)> NUMBER_OF_DEAL-1|| !contains_only_digits(num_of_deal)){
                    printf( "num_of_deal Exceeding the normal input size \n Or the input does not contain only digits");
                    return false;
                }
                break;
            case 4:
                if (stringSize(sum_of_deal)> SUM_OF_DEAL -1 || !contains_only_digits(sum_of_deal)){
                    printf( "date_of_rent Exceeding the normal input size\n Or is not valid date\n");
                    return false;
                }
                break;
        }
    }
    return true;
}