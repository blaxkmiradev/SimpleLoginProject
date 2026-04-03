#include <stdio.h>
#include <stdlib.h>
#include "login.h"

int main() {
    int choice;

    while (1) {
        printf("\n--- Simple Login System ---\n");
        printf("1. Register\n2. Login\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    printf("Login successful! Welcome.\n");
                } else {
                    printf("Invalid username or password.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
