#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 3
#define MAX_FILES 3

typedef struct {
    char name[50];
    int fileCount;
    char files[MAX_FILES][50];
} UserDirectory;

UserDirectory users[MAX_USERS];

void createUserDirectory(char *username) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (users[i].name[0] == '\0') {
            strcpy(users[i].name, username);
            users[i].fileCount = 0;
            printf("User directory '%s' created.\n", username);
            return;
        }
    }
    printf("Maximum number of users reached.\n");
}

void createFile(char *username, char *filename) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].name, username) == 0) {
            if (users[i].fileCount < MAX_FILES) {
                strcpy(users[i].files[users[i].fileCount], filename);
                users[i].fileCount++;
                printf("File '%s' created in user directory '%s'.\n", filename, username);
                return;
            } else {
                printf("Maximum number of files reached for user directory '%s'.\n", username);
                return;
            }
        }
    }
    printf("User directory '%s' not found.\n", username);
}

int main() {
    createUserDirectory("user1");
    createUserDirectory("user2");
    createUserDirectory("user3");

    createFile("user1", "file1");
    createFile("user1", "file2");
    createFile("user1", "file3");

    createFile("user2", "file4");
    createFile("user2", "file5");

    createFile("user3", "file6");
    createFile("user3", "file7");

    return 0;
}
