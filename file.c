#include <stdio.h>
#include<string.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *fp = fopen("contact.csv", "w");
    if (fp == NULL) 
    {
        perror("Failed to open file for saving");
        return;
    }
    for (int i=0;i<addressBook->contactCount;++i) 
    {
        fprintf(fp,"%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fp);
    printf("CONTACT SAVED SUCCESSFULLY\n");
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fp = fopen("contact.csv", "r");
    if (fp==NULL) 
    {
        printf("NO CONTACTS SAVED\n");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) 
    {
        char *newline = strchr(buffer, '\n');
        if (newline != NULL) 
        {
            *newline = '\0';
        }

        Contact newContact;
        char *token = strtok(buffer, "\t");
        if (token != NULL) 
        {
            strcpy(newContact.name, token);
            printf("\t");
        }
        token = strtok(NULL, "\t");
        if (token != NULL) 
        {
            strcpy(newContact.phone, token);
        }
        token = strtok(NULL, "\t");
        if (token != NULL) 
        {
            strcpy(newContact.email, token);
        }

        if (addressBook->contactCount < MAX_CONTACTS) 
        {
            addressBook->contacts[addressBook->contactCount++] = newContact;
        } 
        else 
        {
            printf("ADDRESSBOOK IS FULL\n");
            break;
        }
    }
    fclose(fp);
    printf("CONTACT LOADES SUCCESSFYLLY\n");
}
