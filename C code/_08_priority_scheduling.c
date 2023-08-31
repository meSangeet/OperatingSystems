/*
Priority Scheduling 

Priority sceduling is a CPU algorithm used in OS to determine the order in which processes
are executed on a computer CPU. Each process is assigned a priority, which is typically an 
integer value associated with the process. The higher the priority the more important is
the process.


*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a process
struct Process {
    int id;
    int priority;
    int burst_time;
};

// Function to sort processes based on priority
void sortProcesses(struct Process *processes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Function to execute processes using priority scheduling
void executeProcesses(struct Process *processes, int n) {
    int total_time = 0;
    for (int i = 0; i < n; i++) {
        total_time += processes[i].burst_time;
        printf("Process %d (Priority: %d) is executed.\n", processes[i].id, processes[i].priority);
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
        printf("Enter priority and burst time for process %d: ", processes[i].id);
        scanf("%d %d", &processes[i].priority, &processes[i].burst_time);
    }

    // Sort processes based on priority
    sortProcesses(processes, n);

    printf("Executing processes using priority scheduling:\n");
    executeProcesses(processes, n);

    free(processes);
    return 0;
}

