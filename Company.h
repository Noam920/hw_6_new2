
#ifndef HW5_COMPANY_H
#define HW5_COMPANY_H
#include "Client.h"


bool initCompany(struct Company* cmp);

/*Add car to car list of the company */

bool addNewCar(struct Company* cmp);

/*Add client to client list of the company */
bool addNewClient(struct Company* cmp);

/*Add supplier to supplier list of the company */
bool addNewSupplier(struct Company* cmp);


/* Deletes a car from the list by license number*/
char * deleteCar(struct Company* cmp , const char* license_number);

/* Deletes a client from the list by id*/
bool deleteClient(struct Company* cmp, const char* id);

/* Deletes a supplier from the list by name*/
bool deleteSupplier(struct Company* cmp,const char* supplier_name);

/* Deletes all cars from the list*/
char * deleteAllCars(struct Company* cmp);

char* deleteAllClients(struct Company* cmp);

char* deleteAllSuppliers(struct Company* cmp);

bool inverseCarList(struct Company * cmp );

/*Gets the number of cars in the company with the same engine capacity */
int carNumberWithGivenCapacity(struct Company *cmp ,const char * engine_capacity);

void threeGreatestSuppliers(struct Company * cmp );

int clientNumberWithGivenCarYear(struct Company *cmp, const char * r_year);

int carNumberWithGivenCapacity_Rec(struct NodeCar * nodeCar ,const char * engine_capacity);

void printClientCarsForGivenRentDate(struct Company *cmp, const char *date);

void threeGreatestSupplier_Rec(struct Company *cmp);

void printSuppliers(struct Supplier * sup );
#endif
