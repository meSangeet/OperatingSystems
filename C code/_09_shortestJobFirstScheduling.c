/*
Shortest Job First Scheduling Algorithm

SJF is a CPU scheduling algorithm used in OS to schedule processes for execution on
a computer's CPU. The basic idea behind the SJF algorithm is to prioritize the execution
of processes based on the burst time, which is the amount of time a process requires to 
complete its execution.
*/

#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int burst_time;
};

void sortProcesses(struct Process *processes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void executeProcesses(struct Process *processes, int n) {
    int total_time = 0;
    for (int i = 0; i < n; i++) {
        total_time += processes[i].burst_time;
        printf("Process %d is executed. Burst Time: %d\n", processes[i].id, processes[i].burst_time);
    }
    printf("Total execution time: %d\n", total_time);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process *processes = (struct Process *)malloc(n * sizeof(struct Process));

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
    }

    // Sort processes based on burst time
    sortProcesses(processes, n);

    printf("Executing processes using Shortest Job First:\n");
    executeProcesses(processes, n);

    free(processes);
    return 0;
}
