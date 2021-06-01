
#include "Company.h"

bool initCompany(struct Company *cmp) {
    cmp->supplier_counter = 0;
    cmp->car_counter = 0;
    cmp->client_counter = 0;


    return true;
}

NodeSupplier  * new_sup_tree_node(struct NodeSupplier * root ,Supplier * temp_sup  ){
    struct NodeSupplier *temp;
    if (!root) {
        temp = ALLOC(NodeSupplier, 1);
        temp->right = NULL;
        temp->left = NULL;
        return temp;
    }
     if(strcmp(temp_sup->sum_of_deal,root->supplier_root->sum_of_deal)>0){
        root->right=new_sup_tree_node(root->right,temp_sup);
    } else{
        root->left=new_sup_tree_node(root->left,temp_sup);
    }
    return root;
}


bool addNewSupplier(Company *cmp) {

    struct NodeSupplier * temp_supplier;
    struct Supplier * input_sup;
    input_sup=supplier_constructor();
    temp_supplier= new_sup_tree_node(cmp->supplier_tree,input_sup);
    cmp->supplier_tree=temp_supplier;
    cmp->supplier_counter++;

    return true;
}

bool addNewCar(struct Company *cmp) {
    Car *final_car, *last;


    final_car = ALLOC(struct Car, 1);

    *final_car = car_constructor();

    if (strcmp(final_car->license_number, "empty") == 0) {
        del_car(final_car);
        printf(" The car was not added to the list! please try again \n \n \n");
        return false;
    }

    if (cmp->car_counter == 0 ||
        strcmp(cmp->car_head->production_year, final_car->production_year) > 0) {
        final_car->next = cmp->car_head;
        cmp->car_head = final_car;
        cmp->supplier_counter++;

    } else {
        final_car->next = NULL;
        last = cmp->car_head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = final_car;
    }
    cmp->car_counter++;
    printf(" The car Add to the list   \n");
    return true;
}



/*Add client to client list of the company */
bool addNewClient(struct Company *cmp) {
    Client *client;


    client = ALLOC(struct Client, 1);
    *client = client_constructor();
    if (strcmp(client->id, "empty") == 0) {
        printf(" The client was not added to the list! please try again \n \n \n");
        del_Client(client);
        return false;
    }

    client->next = cmp->client_head;
    cmp->client_head = client;
    cmp->client_counter++;

    printf(" The client Add to the list \n \n \n");

    return true;
}



bool deleteSupplier(struct Company *cmp, const char *supplier_name) {
    int index = 0;
    struct Supplier *temp = cmp->supplier_head, *prev;

    if (cmp->supplier_counter == 0) {
        return false;
    }
    if (temp != NULL && strcmp(cmp->supplier_head->supplier_name, supplier_name) == 0) {
        cmp->supplier_head = temp->next;
        cmp->supplier_counter--;
        del_Supplier(temp);
        return true;
    }
    while (temp != NULL && strcmp(temp->supplier_name, supplier_name) != 0) {
        prev = temp;
        temp = temp->next;
        index++;
    }

    if (index >= cmp->supplier_counter) {
        return false;
    }
    prev->next = temp->next;
    cmp->supplier_counter--;
    del_Supplier(temp);

    return true;
}

char *deleteAllSuppliers(struct Company *cmp) {
    struct Supplier *curr = cmp->supplier_head;
    struct Supplier *next;
    while (curr->next != NULL) {
        next = curr->next;
        if(del_Supplier(curr)) {
            cmp->supplier_counter--;
        }
        curr = next;
    }
    cmp->supplier_head = NULL;
    return "The Suppliers list delete";
}




/* Deletes a car from the list by license number*/
char *deleteCar(struct Company *cmp, const char *license_number) {
    int index = 0;
    struct Car *temp = cmp->car_head, *prev;

    if (cmp->car_counter == 0) {
        return " car list is empty,  delete fail \n";
    }
    if (temp != NULL && strcmp(cmp->car_head->license_number, license_number) == 0) {
        cmp->car_head = temp->next;
        cmp->car_counter--;
        del_car(temp);
        return " deleted Successfully\n";
    }
    while (temp != NULL && strcmp(temp->license_number, license_number) != 0) {
        prev = temp;
        temp = temp->next;
        index++;
    }

    if (index == cmp->car_counter) {
        return "supplier name was not found in the list";
    }
    prev->next = temp->next;
    cmp->car_counter--;
    del_car(temp);

    return " deleted car Successfully ";

}

/* Deletes a client from the list by id*/
bool deleteClient(struct Company *cmp, const char *id) {
    int index = 0;
    struct Client *temp = cmp->client_head, *prev;

    if (cmp->client_counter == 0) {
        return false;
    }
    if (temp != NULL && strcmp(cmp->client_head->id, id) == 0) {
        cmp->client_head = temp->next;
        cmp->client_counter--;
        del_Client(temp);
        return true;
    }
    while (temp != NULL && strcmp(temp->id, id) != 0) {
        prev = temp;
        temp = temp->next;
        index++;
    }

    if (index >= cmp->client_counter) {
        return false;
    }
    prev->next = temp->next;
    cmp->client_counter--;
    del_Client(temp);

    return true;
}


/* Deletes all cars from the list*/
char *deleteAllCars(struct Company *cmp) {

    struct Car *curr = cmp->car_head;
    struct Car *next;
    while (curr->next != NULL) {
        next = curr->next;
        del_car(curr);
        cmp->car_counter--;
        curr = next;
    }
    cmp->car_head = NULL;
    return "The car list delete";
}


char * deleteAllClients(struct Company *cmp) {
    struct Client *curr = cmp->client_head;
    struct Client *next;
    while (curr->next != NULL) {
        next = curr->next;
        del_Client(curr);
        cmp->client_counter--;
        curr = next;
    }
    cmp->client_head = NULL;
    return "The client list deleted";
}

bool inverseCarList(struct Company *cmp) {
    struct Car *prev = NULL;
    struct Car *curr = cmp->car_head;
    struct Car *next = NULL;
    if (cmp->car_head == NULL) {
        return false;
    }

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    cmp->car_head = prev;
    return true;
}





int carNumberWithGivenCapacity(struct Company *cmp ,const char * engine_capacity){
    int int2return = 0;
    int i;
    struct Car *curr = cmp->car_head;
    while(curr!=NULL) {
        for (i = 0; i < cmp->car_counter; i++) {
            if (strcmp(curr->engine_capacity, engine_capacity) == 0) {
                int2return++;
            }
            curr = curr->next;
        }
    }
    return int2return;
}


int carNumberWithGivenCapacity_Rec(struct NodeCar * temp ,const char * engine_capacity) {

    int num2return = 0;
    if(!temp) {
        return 0;
    }
    if(strcmp(temp->car_root->engine_capacity,engine_capacity)==0) {
        num2return++;
    }
    return (num2return+carNumberWithGivenCapacity_Rec(temp->left,engine_capacity)
    +carNumberWithGivenCapacity_Rec(temp->right,engine_capacity));
}

void printClientCarsForGivenRentDate(struct Company *cmp, const char *date) {
    struct Client *cli = cmp->client_head;
    int con = 0;
    while (cli!=NULL){
        if (strcmp(cli->date_of_rent, date) == 0) {
            printf("%d) %s %s\n", con + 1, cli->first_name, cli->last_name);
            con++;
        }
        cli = cli->next;
    }

    if(con==0){
        printf("their isn't any client with that date of rent.\n\n ");
    }
    printf("\n\n\n");
}


/*void help_three(struct Supplier* curr, struct  Supplier* prev, char ** deals,int index,int counter){
    struct Supplier * temp;
    if (counter==0){
        strcpy(deals[index],curr->number_of_deal);
        return;
    }
    counter--;
    if (strcmp(curr->number_of_deal,curr->next->number_of_deal)<0)
        help_three(curr->next,curr,deals,index,counter);

    if (prev==NULL){
        temp=curr->next;
        curr->next=curr->next->next;
        temp->next=curr;
        help_three(curr,temp,deals,index,counter);
        return;
    }
    // if next next == null to do !!

    prev->next=curr->next;
    temp=curr->next->next;
    curr->next->next=curr;
    curr->next=temp;
    help_three(curr,prev->next,deals,index,counter);

}

void sort_rec(Supplier* curr, Supplier* prev){

    if (curr->next==NULL){
        return;
    }



}*/

/*void threeGreatestSupplier_Rec(Company* cmp){
    char max1[SUM_OF_DEAL] = "00";
    char max2[SUM_OF_DEAL] = "00";
    char max3[SUM_OF_DEAL] = "00";
    char deals[3][6];
    struct Supplier *array[20];

    char * in0="412414";
    char * in1="444114";
    char * in2="131414";
    char * in3="158214";
    char * in4="100414";
    char * in5="954432";
    char * in6="887753";
    char * in7="323525";
    char * in8="005875";

    strcpy(array[0]->number_of_deal,in0);
    strcpy(array[1]->number_of_deal,in1);
    strcpy(array[2]->number_of_deal,in2);
    strcpy(array[3]->number_of_deal,in3);
    strcpy(array[4]->number_of_deal,in4);
    strcpy(array[5]->number_of_deal,in5);
    strcpy(array[6]->number_of_deal,in6);
    strcpy(array[7]->number_of_deal,in7);
    strcpy(array[8]->number_of_deal,in8);

    array[0]->next=array[1];
    array[1]->next=array[2];
    array[2]->next=array[3];
    array[3]->next=array[4];
    array[4]->next=array[5];
    array[5]->next=array[6];
    array[6]->next=array[7];
    array[7]->next=array[8];
    array[8]->next=NULL;

    help_three(array[0],NULL,deals,0,8);
    help_three(cmp->supplier_head,NULL,deals,1,cmp->supplier_counter);
    help_three(cmp->supplier_head,NULL,deals,2,cmp->supplier_counter);

    printf("Three suppliers with highest sums of deals:\n1) %s\n2) %s\n3) %s\n\n",deals[0],deals[1],deals[2]);
}*/

int clientNumberWithGivenCarYear(struct Company *cmp, const char * r_year){
   struct Car *car_temp = cmp->car_head;
   struct  Client *cli_temp = cmp->client_head;
   int num2return = 0;
   while(car_temp!=NULL){
       if(strcmp(car_temp->production_year,r_year)==0){
           if(strcmp(cli_temp->client_license_number,car_temp->license_number)==0){
               num2return++;
           }
       }
       car_temp = car_temp->next;
   }
    return num2return;
}
/*void three_help2(long max, struct Supplier *curr, int con){
    if(con > 3){
        return;
    }
    if(atoi(curr->sum_of_deal) == max){
        printf("%d. %s\n",con,curr->supplier_number);
        three_help2(max-1, curr->next, con+1);
    }
    else{
        three_help2(max-1, curr->next, con);
    }
}
void threeGreatestSupplier_Rec(Company* cmp){
    if(cmp->supplier_counter == 0) {
        return;
    }
        three_help2(9999999999,cmp->supplier_head,1);

}*/
/*void threeGreatestSuppliers(struct Company * cmp ){
    struct Supplier * temp = cmp->supplier_head;
    char num_sup_list[cmp->supplier_counter][SUPPLIER_NUMBER];
    char sum_sup_list[cmp->supplier_counter][SUM_OF_DEAL];
    char max[SUM_OF_DEAL] = "00";
    int i, j, k, int2print;
    for(i = 0;i < cmp->supplier_counter; i++){
        strcpy(num_sup_list[i],temp->supplier_number);
        strcpy(sum_sup_list[i],temp->sum_of_deal);
        temp = temp->next;
    }
    for(j = 0; j < 3;j++){
        for(k = 0; k < cmp->supplier_counter; k++){
            if(strcmp(sum_sup_list[k],max)>0){
                strcpy(max,sum_sup_list[k]);
                int2print = k;
            }
        }
        strcpy(sum_sup_list[int2print],"0");
        printf("%d. %s\n",j+1, num_sup_list[int2print]);
    }
    printf("\n\n\n");
}*/
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}
void threeGreatestSuppliers(struct Company * cmp ){
    struct Supplier * temp = cmp->supplier_head;
    char num_sup_list[50000][11];
    int sum_sup_list[50000];
    int sum_sup2[50000];
    int i;
    for(i = 0;i < cmp->supplier_counter; i++){
        strcpy(num_sup_list[i],temp->supplier_number);
        sum_sup_list[i] = atoi(temp->sum_of_deal);
        sum_sup2[i] = atoi(temp->sum_of_deal);
        temp = temp->next;
    }
    bubbleSort(sum_sup2, cmp->supplier_counter);
        for(i = 0; i < cmp->supplier_counter; i++){
            if(sum_sup_list[i]==sum_sup2[cmp->supplier_counter-1]){
                printf("1. %s\n",num_sup_list[i]);
            }
        }
    for(i = 0; i < cmp->supplier_counter; i++){
        if(sum_sup_list[i]==sum_sup2[cmp->supplier_counter-2]){
            printf("2. %s\n",num_sup_list[i]);
        }
    }
    for(i = 0; i < cmp->supplier_counter; i++){
        if(sum_sup_list[i]==sum_sup2[cmp->supplier_counter-3]){
            printf("3. %s\n",num_sup_list[i]);
        }
    }
    printf("\n\n\n");
}

void printSuppliers(struct Supplier * sup ){
    if(sup!=NULL){
         printf("supplier number: %s\nsupplier name: %s\nsupplier phone: %s\nnumber of deal: %s\nsum of deal: %s\n\n\n",sup->supplier_number, sup->supplier_name , sup->supplier_phone, sup->number_of_deal, sup->sum_of_deal);
         printSuppliers( sup->next );
    }
    else{
        printf("the supplier list of that company is empty.\n");
    }
}

