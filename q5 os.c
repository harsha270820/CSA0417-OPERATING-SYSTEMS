#include <stdio.h>

struct process {
    int pid;
    int at; 
    int bt; 
    int wt;
    int tat; 
    int rt; 
};

int main() {
    int n = 4; 
    struct process p[n];
    int t = 0; 
    int completed = 0; 

    for (int i = 0; i < n; i++) {
        p[i].pid = i+1;
        printf("Enter the arrival time and burst time for P%d: ", p[i].pid);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt; 
        p[i].wt = 0; 
        p[i].tat = 0; 
    }


    while (completed < n) {
        int shortest = -1;
        int min_rt = 99999;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= t && p[i].rt < min_rt && p[i].rt > 0) {
                shortest = i;
                min_rt = p[i].rt;
            }
        }
        if (shortest == -1) { 
            t++;
            continue;
        }
        p[shortest].rt--; 
        t++;
        if (p[shortest].rt == 0) { 
            completed++;
            p[shortest].tat = t - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
        }
    }


    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
    }

    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }
    avg_wt /= n;
    avg_tat /= n;
    printf("\nAverage Waiting Time: %.2f ms\n", avg_wt);
    printf("Average Turnaround Time: %.2f ms\n", avg_tat);

    return 0;
}
