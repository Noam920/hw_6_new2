
#include "Client.h"


bool del_Client( Client * curr){
    checked_free(curr->first_name);
    checked_free(curr->last_name);
    checked_free(curr);
    return true;
}

Client client_constructor(){
    bool valid=false;
    Client input_client,*p_input_client;

    char first_name[MAX_OF_STRING] ;
    char last_name[MAX_OF_STRING];
    char id[ID];
    char client_license_number[CLIENT_LICENSE_NUMBER];
    char date_of_rent[DATE_OF_RENT];
    char hour_of_rent[HOUR_OF_RENT];
    char price_for_day[PRICE_FOR_DAY];
    int i=0;
/* separated the input by space*/

    p_input_client=&input_client;

    printf("number=N , char=C:\n");
    printf("If the sign is -M_SIZE- you can enter up to number!\n");
    printf( "If the mark is N or C- enter the -exact- number:\n");

    while (i <= 6) {
        switch (i) {
            case 0:
                printf("enter first_name:\n");
                scanf("%s",first_name);
                i++;
                break;
            case 1:
                printf("enter last_name :\n");
                scanf("%s",last_name);
                i++;
                break;
            case 2:
                printf("enter  id:--N  9--\n");
                scanf("%s", id);
                i++;
                break;
            case 3:
                printf("enter client_license_number: --N 7--\n");
                scanf("%s",client_license_number);
                i++;
                break;
            case 4:
                printf("enter date_of_rent in format: --mm/dd/yyyy--: \n");
                scanf("%s",date_of_rent);
                i++;
                break;
            case 5:
                printf("enter hour_of_rent in format: --hh:mm--\n");
                scanf("%s",hour_of_rent);
                i++;
                break;
            case 6:
                printf("enter  price_for_day:  --N 3--\n");
                scanf("%s",price_for_day);
                i++;
                break;
            default:
                printf("you miss data");

        }
    }


    valid = isValid_client(first_name ,last_name ,id ,client_license_number ,date_of_rent ,hour_of_rent ,price_for_day);

    if (!valid) {
        strcpy( p_input_client->id, "empty\0");
        return input_client;
    }

    p_input_client->first_name=str_dup(first_name);
    p_input_client->last_name=str_dup(last_name);
    strcpy( p_input_client->id, id);
    strcpy( p_input_client->client_license_number, client_license_number);
    strcpy( p_input_client->date_of_rent, date_of_rent);
    strcpy( p_input_client->hour_of_rent, hour_of_rent);
    strcpy( p_input_client->price_for_day, price_for_day);
    return input_client;
}


