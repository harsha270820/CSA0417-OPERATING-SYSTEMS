#include<stdio.h>

struct Process {
    char pid[3];
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

void calculateAverageTimes(struct Process processes[], int n) {
    int i, total_waiting_time = 0, total_turnaround_time = 0;
    

    struct Process temp;
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    
  
    for (i = 0; i < n; i++) {
        if (i == 0) {
            processes[i].waiting_time = 0;
        } else {
            processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        }
        
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    
    
    float average_waiting_time = (float) total_waiting_time / n;
    float average_turnaround_time = (float) total_turnaround_time / n;
    
   
    printf("Average Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);
}

int main() {
  
    struct Process processes[] = {
        { "P1", 30, 2 },
        { "P2", 5, 1 },
        { "P3", 12, 3 }
    };
    
    int n = sizeof(processes) / sizeof(processes[0]);
    
    
    calculateAverageTimes(processes, n);
    
    return 0;
}
