#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100 
#define MAX_NAME_LEN 20 
#define DIR_NAME "CSE" 


typedef struct {
    char name[MAX_NAME_LEN]; 
    int size; 
} File;

int main() {
    File files[MAX_FILES]; 
    int num_files = 0; 
    char input[MAX_NAME_LEN]; 
	int i;

    printf("Welcome to the single-level directory system!\n");
    printf("All files will be stored in the directory '%s'.\n", DIR_NAME);

    
    while (1) {
        printf("Enter a command ('add', 'list', or 'quit'): ");
        scanf("%s", input);

        
        if (strcmp(input, "add") == 0) {
            if (num_files >= MAX_FILES) {
                printf("Error: directory is full\n");
                continue;
            }
            printf("Enter the name of the file to add: ");
            scanf("%s", files[num_files].name);
            printf("Enter the size of the file in bytes: ");
            scanf("%d", &files[num_files].size);
            printf("File '%s' added.\n", files[num_files].name);
            num_files++;
        }

        
        else if (strcmp(input, "list") == 0) {
            if (num_files == 0) {
                printf("The directory is empty.\n");
            } else {
                printf("Files in the directory:\n");
                for (i = 0; i < num_files; i++) {
                    printf("%s (%d bytes)\n", files[i].name, files[i].size);
                }
            }
        }

     
        else if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }

       
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
