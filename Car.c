
#include "Car.h"


bool del_car( Car * curr){
    FREE(curr->manufacturer);
    FREE(curr->model);
    FREE(curr->color);
    FREE(curr);
     /*test git 1111*/
    return true;
}

Car car_constructor() {
    bool valid =false;
    struct Car input_car, *p_input_car;
    char license_number[LICENSE_NUMBER];
    char chassis_number[CHASSIS_NUMBER];
    char manufacturer[MAX_OF_STRING];
    char model[MAX_OF_STRING];
    char color[MAX_OF_STRING];
    char production_year[PRODUCTION_YEAR];
    char on_the_road_year[ON_THE_ROAD_YEAR];
    char buying_price[MAX_BUYING_PRICE];
    char current_price[MAX_CURRENT_PRICE];
    char engine_capacity[ENGINE_CAPACITY];
    int i = 0;

    while (i <= 9) {
        switch (i) {
            case 0:
                printf("enter license_number  --N 7-- :\n");
                scanf("%s", license_number);
                i++;
                break;
            case 1:
                printf("enter chassis_number  --N 5--:\n");
                scanf("%s", chassis_number);
                i++;
                break;
            case 2:
                printf("enter manufacturer:--C MAX_S 10--\n");
                scanf("%s", manufacturer);
                i++;
                break;
            case 3:
                printf("enter model:--C MAX_S 10--\n");
                scanf("%s", model);
                i++;
                break;
            case 4:
                printf("enter color: --C MAX_S 7--\n");
                scanf("%s", color);
                i++;
                break;
            case 5:
                printf("enter production_year: --N 4--\n");
                scanf("%s", production_year);
                i++;
                break;
            case 6:
                printf("enter on_the_road_year:  --N 4--\n");
                scanf("%s", on_the_road_year);
                i++;
                break;
            case 7:
                printf("enter buying_price:--N MAX_S 7-- \n");
                scanf("%s", buying_price);
                i++;
                break;
            case 8:
                printf("enter current_price:--N MAX_S 7--\n");
                scanf("%s", current_price);
                i++;
                break;
            case 9:
                printf("enter engine_capacity:  --N 4-- \n");
                scanf("%s", engine_capacity);
                i++;
                break;
            default:
                printf("you miss data");


        }
    }


    p_input_car = &input_car;

    valid = isValid_car(license_number, chassis_number,
                        manufacturer,
                        model, color, production_year,
                        on_the_road_year,
                        buying_price, current_price,
                        engine_capacity);

    if (!valid) {
        strcpy(input_car.license_number, "empty\0");
        return input_car;
    }

    strcpy(p_input_car->license_number, license_number);
    strcpy(p_input_car->chassis_number, chassis_number);
    p_input_car->manufacturer = str_dup(manufacturer);
    p_input_car->model = str_dup(model);
    p_input_car->color = str_dup(color);
    strcpy(p_input_car->production_year, production_year);
    strcpy(p_input_car->on_the_road_year, on_the_road_year);
    strcpy(p_input_car->buying_price, buying_price);
    strcpy(p_input_car->current_price, current_price);
    strcpy(p_input_car->engine_capacity, engine_capacity);




    return input_car;
}


