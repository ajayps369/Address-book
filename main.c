/*
 * Title : Addressbook
 * Author : Ajay P S
 * Date : October 2024
 * Description : Tool to manage contacts with operations like add, edit, delete, and search using structured file
 saving. Demonstrated knowledge in structures, file systems, and menu-driven programming.
 * */
#include <stdio.h>
#include "contact.h"

int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
		 //system("clear");
                createContact(&addressBook);
                break;
            case 2:
		 //system("clear");
                searchContact(&addressBook);
                break;
            case 3:
		 //system("clear");
                editContact(&addressBook);
                break;
            case 4:
		 //system("clear");
                deleteContact(&addressBook);
                break;
            case 5:
		 //system("clear");		
                listContacts(&addressBook);
                break;
            case 6:
		 //system("clear");
                printf("SAVING AND EXITING\n");
                //saveContactsToFile(&addressBook);
                break;
            default:
		 //system("clear");
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    
       return 0;
}
