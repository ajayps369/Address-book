#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
	printf("+---------------------------------------------------------+\n");
    printf("+--------------------DETAILS OF PRESON--------------------+\n");
    printf("+---------------------------------------------------------+\n");
    printf("SL.NO\t NAME\t\tPHONE NO\t   EMAIL\t\n");    
    printf("+---------------------------------------------------------+\n");
    for(int i=0;i<addressBook->contactCount;i++)
    {
	    printf("%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    
}

void initialize(AddressBook *addressBook)
{
    // Load contacts from file during initialization (After files)
    addressBook->contactCount=0;
	loadContactsFromFile(addressBook);
	if(addressBook->contactCount==0)
	{
		populateAddressBook(addressBook);
	}
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
	if (addressBook->contactCount >= MAX_CONTACTS)
    {
        printf("ADDRESSBOOK IS FULL\n");
    	return;
	}
	printf("------ENTER PERSONAL DATA------\n");
	printf("Enter Name :");
	scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
	printf("Enter Phone No :");
label:scanf("%s",addressBook->contacts[addressBook->contactCount].phone);
	while(strlen(addressBook->contacts[addressBook->contactCount].phone)!=10)
    {
        printf("Enter valid Phone Number");
		goto label;
	}
	printf("Enter Email Id :");
	scanf("%s",addressBook->contacts[addressBook->contactCount].email);
	addressBook->contactCount++;
	printf("CONTACT CREATED SUCCESSFULLY\n");
	saveContactsToFile(addressBook);
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
	int flag=0;
	char data[40];
	int choice;
	printf("------SEARCH DETAILS OF A PERSON-----\n1.Name\n2.Phone Number\n3.Email\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: 
		printf("Enter Name:");
		scanf(" %[^\n]",data);
		for(int i=0;i<addressBook->contactCount;i++)
		{
			if(strcmp(data,addressBook->contacts[i].name)==0)
			{
				flag=1;
				printf("------------------DATA FOUND-------------------\n");
				printf("-----------------------------------------------\n");
				printf("NAME\t\t|PHONE NO\t|EMAIL ID\n");
				printf("-----------------------------------------------\n");
				printf("%s\t",addressBook->contacts[i].name);
				printf("%s\t",addressBook->contacts[i].phone);
				printf("%s\n",addressBook->contacts[i].email);
				break;
			}
		}
		if(flag==0)
		{
			printf("DATA NOT FOUND !!\n");
		}
		break;

		case 2: 
		printf("Enter phone number:");
		scanf(" %[^\n]",data);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(data,addressBook->contacts[i].phone)==0)
            {
                flag=1;
                printf("------------------DATA FOUND-------------------\n");
                printf("-----------------------------------------------\n");
                printf("NAME\t\t|PHONE NO\t|EMAIL ID\n");
                printf("-----------------------------------------------\n");
                printf("%s\t",addressBook->contacts[i].name);
                printf("%s\t",addressBook->contacts[i].phone);
                printf("%s\n",addressBook->contacts[i].email);
                break;
            }
        }
        if(flag==0)
        {
            printf("DATA NOT FOUND !!\n");
    	}
        break;

		case 3:
		 printf("Enter email:");
		scanf(" %[^\n]",data);
                	for(int i=0;i<addressBook->contactCount;i++)
                	{
                        	if(strcmp(data,addressBook->contacts[i].email)==0)
                        	{
                                	flag=1;
                                	printf("------------------DATA FOUND-------------------\n");
                                	printf("-----------------------------------------------\n");
                                	printf("NAME\t\t|PHONE NO\t|EMAIL ID\n");
                                	printf("-----------------------------------------------\n");
                                	printf("%s\t",addressBook->contacts[i].name);
                                	printf("%s\t",addressBook->contacts[i].phone);
                                	printf("%s\n",addressBook->contacts[i].email);
                                	break;
                        	}
                	}
                	if(flag==0)
                	{
                        	printf("DATA NOT FOUND !!\n");
                	}
                	break;

	}
}

void editContact(AddressBook *addressBook) {
    int choice, flag = 0;
    char searchKey[40], newValue[40];

    printf("<<<<<EDIT CONTACT>>>>>>\n1. Edit Name\n2. Edit Phone Number\n3. Edit Email\nEnter your choice: ");
    scanf("%d", &choice);

    printf("Enter the current Name/Phone/Email to search: ");
    scanf(" %[^\n]", searchKey);

    for (int i = 0; i < addressBook->contactCount; i++) 
	{
        if (strcmp(searchKey, addressBook->contacts[i].name) == 0 || strcmp(searchKey, addressBook->contacts[i].phone) == 0 || strcmp(searchKey, addressBook->contacts[i].email) == 0) 
		{
            flag = 1;

            printf("ENTER NEW DATA: ");
            scanf(" %[^\n]", newValue);

            if (choice == 1)
			{
                strcpy(addressBook->contacts[i].name, newValue);
            } 
			else if (choice == 2) 
			{
                strcpy(addressBook->contacts[i].phone, newValue);
            } 
			else if (choice == 3) 
			{
                strcpy(addressBook->contacts[i].email, newValue);
            } 
			else 
			{
                printf("Invalid choice.\n");
                return;
            }

            printf("CONTACT UPDATED SUCCESSFULLY\n");
            saveContactsToFile(addressBook);
            return;
        }
    }

    if(flag==0)
	{
        printf("DATA NOT FOUND !!\n");
    }
}


void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
	int flag=0;
	char data3[40];
	printf(">>>>>DELETE CONTACT<<<<<<\nEnter your valid Name/Phone/Email:");
	scanf(" %[^\n]",data3);
	for(int i=0;i<addressBook->contactCount;i++)
	{
		if(strcmp(data3,addressBook->contacts[i].name)==0||strcmp(data3,addressBook->contacts[i].phone)==0||strcmp(data3,addressBook->contacts[i].email)==0){
			flag=1;
                }
                if(flag==1)
                {
                        for (int j=i;j<addressBook->contactCount-1;j++)
                        {
                                strcpy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
				strcpy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
				strcpy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);
                        }
                        addressBook->contactCount--;
                        printf("CONTACT DELETED SUCCESSFULLY\n");
						saveContactsToFile(addressBook);
                        break;
                }
        }
        if(flag==0)
        {
                printf("Contact not found\n");
        }
}
