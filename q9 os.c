#include <stdio.h>

#define NUM_PROCESSES 3

struct process {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    struct process processes[NUM_PROCESSES] = {{0, 0, 2, 0, 0}, {1, 0, 4, 0, 0}, {2, 0, 8, 0, 0}};
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < NUM_PROCESSES; i++) {
        struct process p = processes[i];

        
        p.waiting_time = current_time - p.arrival_time;
        if (p.waiting_time < 0) {
            p.waiting_time = 0;
        }

        
        p.turnaround_time = p.waiting_time + p.burst_time;

        
        total_waiting_time += p.waiting_time;
        total_turnaround_time += p.turnaround_time;

        
        current_time += p.burst_time;

        
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p.id, p.arrival_time, p.burst_time, p.waiting_time, p.turnaround_time);
    }

    float avg_waiting_time = (float) total_waiting_time / NUM_PROCESSES;
    float avg_turnaround_time = (float) total_turnaround_time / NUM_PROCESSES;
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);

    return 0;
}
