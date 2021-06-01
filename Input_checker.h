
#ifndef HW_3_FINAL_INPUT_CHECKER_H
#define HW_3_FINAL_INPUT_CHECKER_H

#include "Structures.h"
char* str_dup(const char * str);

bool contains_only_digits(const char* str);

bool is_valid_date(const char* str);

bool is_valid_hour(const char* str);

int stringSize(const char* str);

bool contains_only_letters(const char * str);

int trans_to_int(char * str);

bool isValid_car(const char*  license_number , char* chassis_number,char* manufacturer,
                 char* model,char* color,char* production_year, char* on_the_road_year,
                 char* buying_price,char* current_price,char* engine_capacity);

bool isValid_client(char* first_name ,char* last_name ,char* id ,char* client_license_number ,char* date_of_rent ,char* hour_of_rent ,char* price_for_day);                

bool isValid_supplier(char* supplier_number ,char* supplier_name ,char* supplier_phone, char* num_of_deal ,char* sum_of_deal);



#endif
