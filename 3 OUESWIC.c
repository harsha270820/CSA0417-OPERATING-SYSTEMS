#include <stdio.h>

void SJF(int n, int burst_time[]) {
    int i, j, temp, completion_time[n], waiting_time[n], turnaround_time[n];

    completion_time[0] = burst_time[0];
    waiting_time[0] = 0;
    turnaround_time[0] = burst_time[0];

    for (i = 0; i < n - 1; i++) {
        int min_index = i;
        for (j = i + 1; j < n; j++) {
            if (burst_time[j] < burst_time[min_index]) {
                min_index = j;
            }
        }
        
        temp = burst_time[min_index];
        burst_time[min_index] = burst_time[i];
        burst_time[i] = temp;
    }

    for (i = 1; i < n; i++) {
        completion_time[i] = completion_time[i-1] + burst_time[i];
        turnaround_time[i] = completion_time[i] - burst_time[i-1];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
    }

    float avg_waiting_time = 0.0, avg_turnaround_time = 0.0;
    for (i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("Process\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], completion_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    int n = 4, burst_time[] = {6, 8, 7, 3};

    SJF(n, burst_time);

    return 0;
}
