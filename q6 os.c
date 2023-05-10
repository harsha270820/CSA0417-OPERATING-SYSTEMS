#include <stdio.h>

int main() {
    
    int max[3][3] = {{3, 6, 8}, {4, 3, 3}, {3, 4, 4}};
    int allocation[3][3] = {{3, 3, 3}, {2, 0, 3}, {1, 2, 4}};
    int available[3] = {1, 2, 0};
    int need[3][3];

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    
    int finish[3] = {0, 0, 0};

    
    int safe_seq[3];
    int num_safe = 0;


    int deadlock = 1;
    while (deadlock) {
        deadlock = 0;

        for (int i = 0; i < 3; i++) {
            if (!finish[i]) { 
                int can_finish = 1; 
                for (int j = 0; j < 3; j++) {
                    if (need[i][j] > available[j]) { 
                        can_finish = 0;
                        break;
                    }
                }
                if (can_finish) { 
                    for (int j = 0; j < 3; j++) {
                        available[j] += allocation[i][j]; 
                    }
                    finish[i] = 1; 
                    safe_seq[num_safe++] = i; 
                    deadlock = 0; 
                }
            }
        }
    }

    if (num_safe == 3) {
        printf("The system is not in a deadlock state.\n");
        printf("The safe sequence is: P%d -> P%d -> P%d\n", safe_seq[0]+1, safe_seq[1]+1, safe_seq[2]+1);
    } else {
        printf("The system is in a deadlock state.\n");
        printf("The deadlocked processes are: ");
        for (int i = 0; i < 3; i++) {
            if (!finish[i]) {
                printf("P%d ", i+1);
            }
        }
        printf("\n");
    }

    return 0;
}
