#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char data[100];
    
    // Create a file using the system call
    system("touch file.txt");
    
    // Open the file in write mode
    file = fopen("file.txt", "w");
    
    if (file == NULL) {
        printf("Unable to create the file.\n");
        return 1;
    }
    
    // Read data from the user
    printf("Enter data to write to the file: ");
    fgets(data, sizeof(data), stdin);
    
    // Write the data to the file
    fprintf(file, "%s", data);
    
    // Close the file
    fclose(file);
    
    printf("Data written to the file successfully.\n");
    
    // Open the file in read mode
    file = fopen("file.txt", "r");
    
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }
    
    // Read and print the data from the file
    printf("Data read from the file:\n");
    while (fgets(data, sizeof(data), file) != NULL) {
        printf("%s", data);
    }
    
    // Close the file
    fclose(file);
    
    return 0;
}
