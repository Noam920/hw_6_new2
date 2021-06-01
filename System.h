
#ifndef HW_3_FINAL_SYSTEM_H
#define HW_3_FINAL_SYSTEM_H

#include "Company.h"

void print_suppliers (struct Company *cmp );

void S_first_run(Company* cmp);

void S_addNewSupplier(struct Company * cmp);

void S_addNewCar(struct Company * cmp);

void S_addNewClient(struct Company * cmp);

void S_carNumberWithGivenCapacity(struct Company * cmp);

void S_deleteCar(struct Company * cmp);

void S_deleteAllCars(struct Company * cmp);

void print_cars (struct Company *cmp );

void S_inverseCarList(struct Company * cmp );

void S_threeGreatestSuppliers_Rec(struct Company * cmp);

void S_threeGreatestSuppliers(struct Company * cmp);

void S_deleteClient(struct Company * cmp);

void S_deleteAllClients(struct Company * cmp);

void S_clientNumberWithGivenCarYear(struct Company * cmp);

void S_carNumberWithGivenCapacity(struct Company * cmp);

void S_carNumberWithGivenCapacity_Rec(struct Company * cmp);

void S_deleteSupplier(struct Company * cmp);

void S_deleteAllSuppliers(struct Company * cmp);

void S_printClientCarsForGivenRentDate(struct Company * cmp);


#endif
