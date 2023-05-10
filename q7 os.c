#include <stdio.h>
#define MAX_FRAMES 3
#define MAX_REF_STRING 19

int main() {
    int frames[MAX_FRAMES]; 
    int ref_string[MAX_REF_STRING] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3}; // reference string
    int page_faults = 0; 
    int i, j, k, flag, oldest;

    
    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    
    for (i = 0; i < MAX_REF_STRING; i++) {
        flag = 0; 
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == ref_string[i]) { 
                flag = 1;
                break;
            }
        }
        if (!flag) { 
            page_faults++;
            oldest = 0; 
            for (j = 0; j < MAX_FRAMES; j++) {
                
                for (k = i - 1; k >= 0; k--) {
                    if (frames[j] == ref_string[k]) {
                        if (k < oldest) {
                            oldest = k;
                            break;
                        }
                    }
                }
            }
            frames[oldest] = ref_string[i]; 
        }
        printf("%d: ", ref_string[i]);
        for (j = 0; j < MAX_FRAMES; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Number of page faults: %d\n", page_faults);

    return 0;
}
