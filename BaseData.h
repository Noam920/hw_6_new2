
#ifndef HW5_BASEDATA_H
#define HW5_BASEDATA_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "../hw_6_new2/matam.h"

/*#define ALLOC(typ,size) ((typ*)checked_malloc(sizeof(typ)*(size)))*/
#define MAX_OF_STRING  1024

/* Variables and range for Client */
#define FIRST_NAME 21
#define LAST_NAME 21
#define ID 10
#define CLIENT_LICENSE_NUMBER 8
#define DATE_OF_RENT 11
#define HOUR_OF_RENT 6
#define PRICE_FOR_DAY 4
#define M 8000

/* Variables and range for Car */
#define LICENSE_NUMBER 8
#define CHASSIS_NUMBER 6
#define MAX_SIZE_MANUFACTURER 11
#define MAX_SIZE_MODEL 11
#define MAX_SIZE_COLOR 8
#define PRODUCTION_YEAR 5
#define ON_THE_ROAD_YEAR 5
#define MAX_BUYING_PRICE 7
#define MAX_CURRENT_PRICE 7
#define ENGINE_CAPACITY 5


/* Variables and range for Supplier */
#define SUPPLIER_NUMBER 11
#define SUPPLIER_NAME 6
#define SUPPLIER_PHONE 11
#define NUMBER_OF_DEAL 6
#define SUM_OF_DEAL 11





#endif
