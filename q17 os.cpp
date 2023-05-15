#include <stdio.h>

#define MAX_N 10

int main()
{
    int n = 3;
    int bt[] = {24, 3, 3};
    int wt[n], tat[n], rt[n];
    int tq = 4;
    int total_wt = 0, total_tat = 0, time = 0, completed = 0;

    for (int i = 0; i < n; i++) {
        rt[i] = bt[i]; 
    }

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                if (rt[i] <= tq) {
                    time += rt[i]; 
                    rt[i] = 0;
                    completed++;

                    
                    wt[i] = time - bt[i];
                    tat[i] = time;
                } else {
                    time += tq; 
                    rt[i] -= tq;
                }
            }
        }
    }

    
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    double avg_wt = (double)total_wt / n;
    double avg_tat = (double)total_tat / n;

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time: %lf\n", avg_wt);
    printf("Average Turnaround Time: %lf\n", avg_tat);

    return 0;
}
