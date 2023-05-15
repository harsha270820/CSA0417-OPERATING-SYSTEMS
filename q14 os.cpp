#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10 
#define MAX_REFERENCES 100 


int find_optimal_page(int pages[], int num_pages, int references[], int num_references, int start_index) {
    int i, j;
    int max_index = -1;
    int max_distance = -1;
    for (i = 0; i < num_pages; i++) {
        int page = pages[i];
        int distance = -1;
        for (j = start_index; j < num_references; j++) {
            if (references[j] == page) {
                distance = j - start_index;
                break;
            }
        }
        if (distance == -1) {
            return i; 
        }
        if (distance > max_distance) {
            max_distance = distance;
            max_index = i;
        }
    }
    return max_index;
}

int main() {
    int num_frames;
    int frames[MAX_FRAMES];
    int num_references;
    int references[MAX_REFERENCES];
    int faults = 0;
    int i, j;

    // get input from user
    printf("Enter the number of page frames: ");
    scanf("%d", &num_frames);
    printf("Enter the number of page references: ");
    scanf("%d", &num_references);
    printf("Enter the page reference sequence:\n");
    for (i = 0; i < num_references; i++) {
        scanf("%d", &references[i]);
    }

  
    for (i = 0; i < num_frames; i++) {
        frames[i] = -1;
    }


    for (i = 0; i < num_references; i++) {
        int page = references[i];

        
        int hit = 0;
        for (j = 0; j < num_frames; j++) {
            if (frames[j] == page) {
                hit = 1;
                break;
            }
        }

        
        if (!hit) {
            faults++;

          
            int replace_index = find_optimal_page(frames, num_frames, references, num_references, i);

          
            frames[replace_index] = page;
        }
    }

   
    printf("Number of page faults: %d\n", faults);

    return 0;
}
