//
//  main.c
//  PHONE BOOK
//
//  Created by aslam habib on 10/05/25.
//
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char phone[15];
};

struct Contact phonebook[MAX];
int count = 0;

void addContact() {
    if (count < MAX) {
        printf("Enter Name: ");
        scanf(" %[^\n]", phonebook[count].name);
        printf("Enter Phone Number: ");
        scanf(" %[^\n]", phonebook[count].phone);
        count++;
        printf("Contact added successfully.\n");
    } else {
        printf("Phonebook is full.\n");
    }
}

void viewContacts() {
    if (count == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, phonebook[i].name, phonebook[i].phone);
    }
}

void searchContact() {
    char search[50];
    printf("Enter name or phone to search: ");
    scanf(" %[^\n]", search);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(phonebook[i].name, search) || strstr(phonebook[i].phone, search)) {
            printf("Found: %s - %s\n", phonebook[i].name, phonebook[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("No contact found.\n");
    }
}

void deleteContact() {
    char name[50];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                phonebook[j] = phonebook[j + 1];
            }
            count--;
            printf("Contact deleted.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void editContact() {
    char name[50];
    printf("Enter the name of the contact to edit: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Enter new name: ");
            scanf(" %[^\n]", phonebook[i].name);
            printf("Enter new phone number: ");
            scanf(" %[^\n]", phonebook[i].phone);
            printf("Contact updated.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    int choice;
    do {
        printf("\nPhonebook Menu\n");
        printf("1. Add Contact\n2. View Contacts\n3. Search Contact\n4. Edit Contact\n5. Delete Contact\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: editContact(); break;
            case 5: deleteContact(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);
    return 0;
}
