
#include "System.h"

#include <stdio.h>

void S_first_run(Company* cmp) {
    if (initCompany(cmp)) {
        printf("All the list created successfully\n");
        printf("\n");
    }
}

void S_addNewSupplier(struct Company * cmp){
    printf(" add New Supplier:\n");
    printf("Enter data according to the instructions:\n");

    addNewSupplier(cmp );
}

void S_deleteSupplier(struct Company * cmp){
    char sup_name[SUPPLIER_NAME];
    printf("delete Supplier\n");
    printf("Enter the  Name  of the Supplier that you want to delete \n");
    printf("supplier name: 5 letters \n");

    scanf("%s",sup_name);

    if(deleteSupplier(cmp,sup_name )){
        printf("supplier delete Successfully from the list");
    } else{
        printf("Supplier name %s not found ",sup_name);
    }
}
void print_suppliers (struct Company *cmp ) {
    struct Supplier *temp2 = cmp->supplier_head;
    while (temp2 != NULL) {
        printf("%s\n", temp2->supplier_name);
        printf("%s\n", temp2->supplier_number);
        temp2 = temp2->next;
    }
}

void print_cars (struct Company *cmp ) {
    struct Car *temp2 = cmp->car_head;
    while (temp2 != NULL) {
        printf("%s\n", temp2->production_year);
        temp2 = temp2->next;
    }
}
void S_deleteAllSuppliers(struct Company * cmp){
    printf("delete all Suppliers from the list: \n");
    deleteAllSuppliers(cmp);
    printf("\n");
}
void S_addNewCar(struct Company * cmp){
    printf(" add New Car:\n");
    printf("Enter data according to the instructions:\n");
    addNewCar(cmp);
}

void S_deleteCar(struct Company * cmp){
    char license_number[LICENSE_NUMBER];
    printf("\n car for delete");
    printf("Enter the license number of the car that you want to delete: \n");
    printf("\n license number: 7 digits \n");
    scanf("%s",license_number);

    if (stringSize(license_number)!= LICENSE_NUMBER-1 || !contains_only_letters(license_number)) {
        printf("supplier name Exceeding the normal input size\n Or the input does not contain only letters\n");
    }
    printf("%s", deleteCar(cmp,license_number ));
    printf("\n");

}


void S_addNewClient(struct Company * cmp){
    printf(" add New Client:\n");
    printf("Enter data according to the instructions:\n");

    addNewClient( cmp);
}
void S_deleteClient(struct Company * cmp){
    char id[ID];
    printf("delete Client\n");
    printf("Enter the the ID of the Client that you want to delete \n");
    printf("Client Id: 10 digits \n");

    scanf("%s", id);
    if (stringSize(id) != ID - 1 || !contains_only_digits(id)) {
        printf("id number Exceeding the normal input size\n Or the input does not contain only digits");
    } else {
        if (deleteClient(cmp,id)) {
            printf("Client delete Successfully from the list");
        }
        else
        {
            printf("Client ID %s not found ",id);
        }
    }
    printf("\n");
}
void S_deleteAllCars(struct Company * cmp){
    printf("delete all cars from the list: \n");
    deleteAllCars(cmp);
    printf("\n");

}
void S_deleteAllClients(struct Company * cmp){
    printf("delete all clients from the list: \n");
    deleteAllClients(cmp);
    printf("\n");

}

void S_inverseCarList(struct Company * cmp ){
    if(!inverseCarList(cmp)){
        printf("car list is empty");
    }
    printf("car list was inverse");
}

void S_carNumberWithGivenCapacity(struct Company * cmp){
    char engine_capacity[ENGINE_CAPACITY];
    int num2return;
    int flag = 0;
    printf("enter a engine_capacity and get the number of cars that have this capacity: \n ");
    while (flag==0) {
        scanf("%s", engine_capacity);
        if (stringSize(engine_capacity) != ENGINE_CAPACITY - 1 || !contains_only_digits(engine_capacity)) {
            printf("engine_capacity Exceeding the normal input size\n Or the input does not contain only digits\ntry again:\n");
        } else { flag++; }
    }
    num2return = carNumberWithGivenCapacity(cmp,engine_capacity);
    printf("the number of cars with engine capacity of %s: %d \n\n\n\n", engine_capacity, num2return);
}


void S_carNumberWithGivenCapacity_Rec(struct Company * cmp){
    char engine_capacity[ENGINE_CAPACITY];
    int num2return;
    int flag = 0;
    printf("enter a engine_capacity and get the number of cars that have this capacity: \n ");
    while (flag==0) {
        scanf("%s", engine_capacity);
        if (stringSize(engine_capacity) != ENGINE_CAPACITY - 1 || !contains_only_digits(engine_capacity)) {
            printf("engine_capacity Exceeding the normal input size\n Or the input does not contain only digits\ntry again:\n");
        } else { flag++; }
    }

    num2return = carNumberWithGivenCapacity_Rec(cmp->car_tree,engine_capacity);
    printf("the number of cars with engine capacity of %s: %d \n\n\n\n", engine_capacity, num2return);
}
void S_printClientCarsForGivenRentDate(struct Company * cmp){
    char date[DATE_OF_RENT];
    int flag = 0;
    printf("enter a date in format dd/mm/yyyy and get all the clients that rent a car at this date: \n");
    while (flag==0){
        scanf("%s", date);
        if (stringSize(date)!= DATE_OF_RENT -1 || !is_valid_date(date)) {
            printf("date_of_rent Exceeding the normal input size\n Or is not valid date\nplease try again:\n ");
        }
        else{flag++;}
    }
    printClientCarsForGivenRentDate(cmp,date);
}

void S_threeGreatestSuppliers_Rec(struct Company * cmp){
    if(cmp->supplier_head!=NULL) {
        threeGreatestSupplier_Rec(cmp);
    }
    else{
        printf("the supplier list of that company is empty.\n");
    }
}

void S_clientNumberWithGivenCarYear(struct Company * cmp){
    char prod_year[PRODUCTION_YEAR];
    int num2return = 0;
    int flag = 0;
    printf("enter a production year and get the number of clint with car from that year: \n ");
    while(flag==0) {
        scanf("%s", prod_year);
        if (stringSize(prod_year) != PRODUCTION_YEAR - 1 || !contains_only_digits(prod_year)) {
            printf("production_year Exceeding the normal input size\n Or the input does not contain only letters\nplease try again:\n");
        } else { flag++; }
    }
    num2return += clientNumberWithGivenCarYear(cmp,prod_year);
    printf("the number of clients with a car that product at %s: %d \n\n",prod_year,num2return);
}

void S_threeGreatestSuppliers(struct Company * cmp){
    if(cmp->supplier_counter < 3){
        printf("the supplier list contain less then 3 suppliers.\n\n");
        return;
    }
    else {
        threeGreatestSuppliers(cmp);
    }
}
/*






void S_carNumberWithGivenCapacity(struct Company * cmp){
    char capacity[ENGINE_CAPACITY];
    printf("get how many cars in the list with the engine capacity: \n");
    printf("\n enter car Capacity: 4 digits \n");
    scanf("%s",capacity);
    if (stringSize(capacity)!= ENGINE_CAPACITY-1 || !contains_only_digits(capacity)) {
        printf("engine_capacity Exceeding the normal input size\n Or the input does not contain only letters\n");
    }
    else{
        printf("\n number of cars with the engine Capacity = ");
        printf("%d", carNumberWithGivenCapacity(cmp, capacity));
    }
    printf("\n");

}





void S_threeGreatestSuppliers(struct Company * cmp){
    threeGreatestSuppliers(cmp);
    }








void S_deleteAllClients(struct Company * cmp){
    printf("delete all Clients from the list: \n");
    deleteAllClients(cmp);
    printf("\n");

}

void S_clientNumberWithGivenCarYear(struct Company * cmp){
    char on_the_r[ON_THE_ROAD_YEAR];
    int on_rl;
    printf("get how many client Number With Given Car Year prodaction: \n");
    printf("enter Car Year prodaction: 4 digits\n");
    scanf("%s",on_the_r);
    if (stringSize(on_the_r)!= ON_THE_ROAD_YEAR-1 || !contains_only_digits(on_the_r)){
        printf( "on_the_road_year Exceeding the normal input size\n Or the input does not contain only letters\n");
    }
    else{
        on_rl=atoi(on_the_r);
        printf("\n number of client with the same car given year ");
        printf("%d", clientNumberWithGivenCarYear(cmp,on_rl));
    }
    printf("\n");

}



*/






