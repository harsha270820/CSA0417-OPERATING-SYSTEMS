#include <stdio.h>

int main()
{
    int n = 3;
    int bt[] = {10, 15, 25};
    int wt[n], tat[n], avg_wt, avg_tat;

    wt[0] = 0; 
    
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    
    avg_wt = 0;
    avg_tat = 0;

    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time: %d\n", avg_wt);
    printf("Average Turnaround Time: %d\n", avg_tat);

    return 0;
}
