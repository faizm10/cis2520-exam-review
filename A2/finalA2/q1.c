/*
Name: Faiz Mustansar
Student ID: 1261489
Assignment: A2
Date: Oct 11, 2024
*/
/*
 * You will need to add all the cases
 * Call the appropriate functions
 * You would also need to save data to disc upon exit
 * File Format: plate,mileage,return_date
 * Error Handling needs to happen too
 */
#include "q1.h"

int main()
{
    // Initialize the three linked lists
    struct car *available_head = NULL;
    struct car *rented_head = NULL;
    struct car *repair_head = NULL;

    // Load lists from files
    read_file_into_list("available.txt", &available_head);
    read_file_into_list("rented.txt", &rented_head);
    read_file_into_list("repair.txt", &repair_head);

    int choice;
    char plate[8];
    int mileage, return_date;

    do
    {
        prompt();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Add a new car to the available-for-rent list
            printf("Enter Plate: ");
            scanf("%s", plate);
            printf("Enter Mileage: ");
            scanf("%d", &mileage);

            if (is_plate_in_list(available_head, plate) ||
                is_plate_in_list(rented_head, plate) ||
                is_plate_in_list(repair_head, plate))
            {
                printf("Error: Duplicate plate number.\n");
            }
            else
            {
                insert_to_list(&available_head, plate, mileage, -1);
                printf("Car %s added to available-for-rent list.\n", plate);
            }
            break;

        case 2: // Return a car to the available-for-rent list
            printf("Enter Plate: ");
            scanf("%s", plate);
            printf("Enter Mileage: ");
            scanf("%d", &mileage);

            struct car *returned = remove_car_from_list(&rented_head, plate);
            if (returned && mileage >= returned->mileage)
            {
                double profit = profit_calculator(returned->mileage, mileage);
                printf("Car %s returned with a charge of $%.2f.\n", plate, profit);
                insert_to_list(&available_head, plate, mileage, -1);
                free(returned);
            }
            else
            {
                printf("Error: Invalid mileage or car not found in rented list.\n");
            }
            break;

        case 3: // Return a car to the repair list
            printf("Enter Plate: ");
            scanf("%s", plate);
            printf("Enter Mileage: ");
            scanf("%d", &mileage);

            returned = remove_car_from_list(&rented_head, plate);
            if (returned && mileage >= returned->mileage)
            {
                printf("Car %s moved to repair list.\n", plate);
                insert_to_list(&repair_head, plate, mileage, -1);
                free(returned);
            }
            else
            {
                printf("Error: Invalid mileage or car not found in rented list.\n");
            }
            break;

        case 4: // Transfer a car from the repair list to available-for-rent
            printf("Enter Plate: ");
            scanf("%s", plate);

            struct car *repaired = remove_car_from_list(&repair_head, plate);
            if (repaired)
            {
                printf("Car %s moved to available-for-rent list.\n", plate);
                insert_to_list(&available_head, plate, repaired->mileage, -1);
                free(repaired);
            }
            else
            {
                printf("Error: Car not found in repair list.\n");
            }
            break;

        case 5: // Rent the first available car
        {
            printf("Enter Expected Return Date (YYMMDD): ");
            scanf("%d", &return_date);

            // Extract year, month, and day from return_date
            int year = return_date / 10000;
            int month = (return_date / 100) % 100;
            int day = return_date % 100;

            // Validate that month is between 1 and 12
            if (month < 1 || month > 12)
            {
                printf("Error: Invalid month %02d. Month must be between 1 and 12.\n", month);
                break;
            }

            // Validate that day is between 1 and 31
            if (day < 1 || day > 31)
            {
                printf("Error: Invalid day %02d. Day must be between 1 and 31.\n", day);
                break;
            }

            // If the date is valid, proceed with the rental
            struct car *to_rent = remove_first_from_list(&available_head);
            if (to_rent)
            {
                printf("Car %s rented, due back on %02d/%02d/%02d.\n", to_rent->plate, year, month, day);
                insert_to_list(&rented_head, to_rent->plate, to_rent->mileage, return_date);
                free(to_rent);
            }
            else
            {
                printf("Error: No cars available for rent.\n");
            }
            break;
        }

        case 6: // Print all lists
            printf("Available-for-rent list:\n");
            print_list(available_head);
            printf("Rented list:\n");
            print_list(rented_head);
            printf("In-repair list:\n");
            print_list(repair_head);
            break;

        case 7: // Save all lists to files and quit
            write_list_to_file("available.txt", available_head);
            write_list_to_file("rented.txt", rented_head);
            write_list_to_file("repair.txt", repair_head);

            free_list(&available_head);
            free_list(&rented_head);
            free_list(&repair_head);
            printf("Data saved. Exiting...\n");
            return 0;

        default:
            printf("Error: Invalid choice.\n");
            break;
        }
    } while (true);

    return 0;
}
