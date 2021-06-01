#include "System.h"
#define DAVIS
#include "Company.h"
int main() {
    int x;
    Company cmp;
    S_first_run(&cmp);

    while (1) {
        printf("Select operation:\n"
               "--------------------\n"
               "1.Car \n"
               "2.Client\n"
               "3.Supplier\n"
               "4.Quit\n");
        scanf("%d", &x);

        if (x == 4) {
            printf("delete all lists bye\n");
            S_deleteAllCars(&cmp);
            S_deleteAllSuppliers(&cmp);
            S_deleteAllClients(&cmp);
            return 0;
        }

        switch (x) {
            case 1:
                printf("Enter action:\n"
                       "1.Add Car\n"
                       "2.carNumberWithGivenCapacity_REC\n"
                       "3.carNumberWithGivenCapacity\n"
                       "4.delete deleteCar\n"
                       "5.inverse Car List\n");
                scanf("%d", &x);
                switch (x) {
                    case 1:;
                        S_addNewCar(&cmp);
                        break;
                    case 2:
                        S_carNumberWithGivenCapacity_Rec(&cmp);
                        break;
                    case 3:
                        S_carNumberWithGivenCapacity(&cmp);
                        break;
                    case 4:
                        S_deleteCar(&cmp);
                        break;
                    case 5:
                        S_inverseCarList(&cmp);
                        break;

                    default:
                        printf("only number between 1 to 4\n");
                        break;
                }
                break;
            case 2:
                printf("Enter action:\n"
                       "1.Add new client\n"
                       "2.clientNumberWithGivenCarYear\n"
                       "3.delete Client\n");
#ifdef DAVIS
                printf(	"4.print Client Cars For Given Rent Date \n");

#endif
                scanf("%d", &x);
                switch (x) {
                    case 1:
                        S_addNewClient(&cmp);
                        break;
                    case 2:
                        S_clientNumberWithGivenCarYear(&cmp);
                        break;
                    case 3:
                        S_deleteClient(&cmp);
                        break;

                    case 4:
#ifdef DAVIS
                        S_printClientCarsForGivenRentDate(&cmp);
                         break;

#endif

                    default:
                        printf("error, enter only number between 1 to 4\n");
                        break;
                }
                break;
            case 3:
                printf("Enter action:\n"
                       "1.add New Supplier\n"
                       "2.three Greatest Suppliers_REC\n"
                       "3. delete Supplier\n");
#ifdef DAVIS
                printf(	"4.print Suppliers \n");

#endif

                scanf("%d", &x);
                switch (x) {
                    case 1:
                        S_addNewSupplier(&cmp);
                        break;
                    case 2:
                        S_threeGreatestSuppliers(&cmp);
                        break;
                    case 3:
                        S_deleteSupplier(&cmp);
                    case 4:
#ifdef DAVIS
                        S_printClientCarsForGivenRentDate(&cmp);
                         break;

#endif

                    default:
                        printf("error, enter only number between 1 to 5\n");
                        break;
                }
                break;
            default:
                printf("error,enter only number between 1 to 4\n");
                break;
        }
    }


}


/*/int main(){
//
//    Company cmp;
//    threeGreatestSupplier_Rec(&cmp);
//
//}*/
