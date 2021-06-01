

#ifndef HW5_STRUCTURES_H
#define HW5_STRUCTURES_H

#include "BaseData.h"

/*Client struct fields */

typedef struct Client {
    char *first_name;
    char *last_name;
    char id[ID];
    char client_license_number[CLIENT_LICENSE_NUMBER];
    char date_of_rent[DATE_OF_RENT];
    char hour_of_rent[HOUR_OF_RENT];
    char price_for_day[PRICE_FOR_DAY];
    struct Client * next;
} Client;

typedef struct NodeClient {
    Client * client_root;
    struct NodeClient * right;
    struct NodeClient * left;
} NodeClient;


/*Car struct fields */
typedef struct Car {
    char license_number[LICENSE_NUMBER];
    char chassis_number[CHASSIS_NUMBER];
    char *manufacturer;
    char *model;
    char *color;
    char production_year[PRODUCTION_YEAR];
    char on_the_road_year[ON_THE_ROAD_YEAR];
    char buying_price[MAX_BUYING_PRICE];
    char current_price[MAX_CURRENT_PRICE];
    char engine_capacity[ENGINE_CAPACITY];
} Car;


typedef struct NodeCar {
    struct Car * car_root;
    struct NodeCar * right;
    struct NodeCar *left;
} NodeCar;


typedef struct Supplier {
    char supplier_number[SUPPLIER_NUMBER];
    char *supplier_name;
    char supplier_phone[SUPPLIER_PHONE];
    char number_of_deal[NUMBER_OF_DEAL];
    char sum_of_deal[SUM_OF_DEAL];
} Supplier;

typedef struct NodeSupplier {
    struct Supplier * supplier_root;
    struct NodeSupplier *right;
    struct NodeSupplier *left;
} NodeSupplier;
typedef struct Test {
    char name[5];
    char *number ;

} Test;

typedef struct NodeTest {
    struct Test * supplier_root;
    struct NodeTest *right;
    struct NodeTest *left;
} NodeTest;



typedef struct Company {
    struct NodeCar * car_tree;
    struct NodeClient * client_tree;
    struct NodeSupplier * supplier_tree;
    struct NodeTest * test_root;
    int test_counter;
    int client_counter;
    int car_counter;
    int supplier_counter;

} Company;

#endif
