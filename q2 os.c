#include<stdio.h>

int main() {
    int i, j, k, n = 4, m = 3;
    int available[3] = {9, 3, 6};
    int max[4][3] = {{3, 2, 2}, {6, 1, 3}, {3, 1, 4}, {4, 2, 2}};
    int allocation[4][3] = {{1, 0, 0}, {6, 1, 2}, {2, 1, 1}, {0, 0, 2}};
    int need[4][3];
    int finish[4] = {0, 0, 0, 0};
    int safeSequence[4];
    int count = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int canBeAllocated = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        canBeAllocated = 0;
                        break;
                    }
                }
                if (canBeAllocated) {
                    for (j = 0; j < m; j++) {
                        available[j] += allocation[i][j];
                    }
                    finish[i] = 1;
                    safeSequence[count++] = i;
                }
            }
        }
    }

    if (count < n) {
        printf("The system is in an unsafe state.\n");
    } else {
        printf("The system is in a safe state.\n");
        printf("Safe sequence is: ");
        for (i = 0; i < n; i++) {
            printf("%d ", safeSequence[i]);
        }
        printf("\n");
    }

    return 0;
}
