#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../data/users.txt" // optional, just for clarity
#include "login.h"

#define FILENAME "../data/users.txt"

void registerUser() {
    char username[50], password[50];
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter new username: ");
    scanf("%s", username);
    printf("Enter new password: ");
    scanf("%s", password);

    fprintf(file, "%s %s\n", username, password);
    fclose(file);
    printf("Registration successful!\n");
}

int loginUser() {
    char username[50], password[50];
    char fileUser[50], filePass[50];
    int found = 0;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("No users registered yet!\n");
        return 0;
    }

    while (fscanf(file, "%s %s", fileUser, filePass) != EOF) {
        if (strcmp(username, fileUser) == 0 && strcmp(password, filePass) == 0) {
            found = 1;
            break;
        }
    }

    fclose(file);
    return found;
}
