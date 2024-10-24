/*
Name: Faiz Mustansar
Student ID: 1261489
Assignment: A2
Date: Oct 11, 2024
*/
#include "q1.h"


/* function will display the primary user interface
    This is already done for you*/
void prompt(void){

  printf("1. Add a new car to the available-for-rent list,\n");
  printf("2. Add a returned car to the available-for-rent list,\n");
  printf("3. Add a returned car to the repair list,\n");
  printf("4. Transfer a car from the repair list to the available-for-rent list,\n");
  printf("5. Rent the first available car,\n");
  printf("6. Print all the lists,\n");
  printf("7. Quit.\n");
  printf("Enter your choice: ");
}

/**
 * Inserts a new car into the linked list.
 * @param head Pointer to the head of the list.
 * @param plate Character array containing the car's license plate.
 * @param mileage Integer representing the car's mileage.
 * @param return_date Integer representing the car's return date, you can have -1 represent no return date.
 * @return Pointer to the newly added car in the list.
 */
struct car * insert_to_list(struct car ** head, char plate[], int mileage, int return_date){

    struct car *new_car = (struct car*)malloc(sizeof(struct car));
    strcpy(new_car->plate, plate);
    new_car->mileage = mileage;
    new_car->return_date = return_date;
    new_car->next = NULL;

    if (*head == NULL || (*head)->mileage > mileage) {
        new_car->next = *head;
        *head = new_car;
    } else {
        struct car *current = *head;
        while (current->next != NULL && current->next->mileage <= mileage) {
            current = current->next;
        }
        new_car->next = current->next;
        current->next = new_car;
    }
    return new_car;
}

/**
 * Prints all the cars in the list.
 * @param head Pointer to the head of the list.
 * This function prints out the car details, it should not print return date if it does not exist.
 */
void print_list(struct car *head){

    struct car *current = head;
    while (current != NULL) {
        printf("Plate: %s, Mileage: %d, Return Date: %d\n",
               current->plate, current->mileage, current->return_date);
        current = current->next;
    }
}

/**
 * Checks if a car's plate is already in the list.
 * @param head Pointer to the head of the list.
 * @param plate Character array containing the car's license plate.
 * @return Boolean value indicating if the plate is found.
 */
bool is_plate_in_list(struct car * head, char plate[]){

    struct car *current = head;
    while (current != NULL) {
        if (strcmp(current->plate, plate) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

/**
 * Swaps two cars in the list.
 * @param a Pointer to the first car.
 * @param b Pointer to the second car.
 * Swaps the plate, mileage, and return date of two cars.
 */
void swap(struct car *a, struct car *b){
    return;
}

/**
 * Sorts the list of cars based on mileage or return date.
 * @param head Pointer to the head of the list.
 * @param sort_by_mileage Boolean to sort by mileage.
 * @param sort_by_return_date Boolean to sort by return date.
 */
void sort_list(struct car ** head, bool sort_by_mileage, bool sort_by_return_date){

    if (*head == NULL) return;

    struct car *i, *j;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if ((sort_by_mileage && i->mileage > j->mileage) ||
                (sort_by_return_date && i->return_date > j->return_date)) {
                // Swap the data between i and j
                char temp_plate[8];
                strcpy(temp_plate, i->plate);
                strcpy(i->plate, j->plate);
                strcpy(j->plate, temp_plate);

                int temp_mileage = i->mileage;
                i->mileage = j->mileage;
                j->mileage = temp_mileage;

                int temp_return_date = i->return_date;
                i->return_date = j->return_date;
                j->return_date = temp_return_date;
            }
        }
    }
}

/**
 * Removes a car from the list by its plate number.
 * @param head Pointer to the head of the list.
 * @param plate Character array containing the car's license plate.
 * @return Pointer to the removed car.
 */
struct car * remove_car_from_list(struct car **head, char plate[]){

    struct car *current = *head, *prev = NULL;
    while (current != NULL && strcmp(current->plate, plate) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) return NULL;  // Not found
    if (prev == NULL) *head = current->next;
    else prev->next = current->next;
    return current;
}

/**
 * Removes the first car from the list.
 * @param head Pointer to the head of the list.
 * @return Pointer to the removed car.
 */
struct car * remove_first_from_list(struct car **head){

    if (*head == NULL) return NULL;
    struct car *first = *head;
    *head = first->next;
    first->next = NULL;  // Prevent dangling pointer
    return first;
}

/**
 * Calculates the profit based on the mileage difference.
 * @param initial_mileage Integer representing the car's starting mileage.
 * @param final_mileage Integer representing the car's final mileage.
 * @return Double value representing the calculated profit.
 */
double profit_calculator(int initial_mileage, int final_mileage){

    int distance = final_mileage - initial_mileage;
    double profit = 80.0;
    if (distance > 200) {
        profit += (distance - 200) * 0.15;
    }
    return profit;
}

/**
 * Writes the list of cars to a file.
 * The file would be in the format: plate,mileage,return_date
 * @param filename Character array with the file name.
 * @param head Pointer to the head of the list.
 * Writes the details of each car in the list to a file.
 */
void write_list_to_file(char *filename, struct car *head){

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", filename);
        return;
    }

    struct car *current = head;
    while (current != NULL) {
        fprintf(file, "%s,%d,%d\n", current->plate, current->mileage, current->return_date);
        current = current->next;
    }
    fclose(file);
}

/**
 * Reads car details from a file and adds them to the list.
 * The file would be in the format: plate,mileage,return_date
 * @param filename Character array with the file name.
 * @param head Pointer to the head of the list.
 * Reads data from the file and inserts each car into the list.
 */
void read_file_into_list(char *filename, struct car **head){

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s for reading.\n", filename);
        return;
    }

    char plate[8];
    int mileage, return_date;

    while (fscanf(file, "%7[^,],%d,%d\n", plate, &mileage, &return_date) == 3) {
        insert_to_list(head, plate, mileage, return_date);
    }
    fclose(file);
}

/**
 * Prints the date in the format of year/month/day.
 * @param date Integer representing the date in YYMMDD format.
 */
void date(int date){
    
    int year = date / 10000;
    int month = (date / 100) % 100;
    int day = date % 100;
    printf("%02d/%02d/%02d\n", year, month, day);
}

/**
 * Frees all the memory allocated for the cars in the list.
 * @param head Pointer to the head of the list.
 * Frees each car node in the list.
 */
void free_list(struct car ** head){
    struct car *current = *head;
    while (current != NULL) {
        struct car *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}