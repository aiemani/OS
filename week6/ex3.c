#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define max(a,b) (a < b ? b : a)
#define min(a,b) (a > b ? b : a)

// Structure that represents a process
typedef struct process {
  // Enumerating the process
  int pid;

  // Flag: 1 if the process is finished, 0 otherwise
  int done;

  // Required metrics
  int arriving_time;
  int burst_time;
  int completion_time;
  int waiting_time;
  int turn_around_time;
} process;

// Global variable for the number of processes
int number_of_processes;

// Global variable for the quantum time
int quantum;

// Evaluate values "Average waiting time" and "Average turn around time"
float mean_wt(process processes[]);
float mean_tat(process processes[]);

// Key scheduling function
void schedule(process processes[]);

// Just printing function
void print_table(process processes[]);

// Sorting processes by arriving and burst time
void sort_processes(process processes[]);

// Main function
int main(){

  // Reading the quantum
  scanf("%d", &quantum);

  // Reading the number of processes
  scanf("%d", &number_of_processes);

  // Creating an array of processes
  process processes[number_of_processes];

  // Filling in the format "Arriving_time Burst_time" for each process,
  //    process ID is just its ordinal number
  for (int i = 0; i < number_of_processes; i++) {
    processes[i].pid = i;
    scanf("%d %d", &processes[i].arriving_time, &processes[i].burst_time);
  }

  // Perform scheduling and printing
  schedule(processes);
  print_table(processes);

  return 0;
}

float mean_wt(process processes[]) {
  float sum = 0;

  for (int i = 0; i < number_of_processes; i++) {
    sum = sum + (float) processes[i].waiting_time;
  }

  return sum / number_of_processes;
}

float mean_tat(process processes[]) {
  float sum = 0;

  for (int i = 0; i < number_of_processes; i++) {
    sum = sum + (float) processes[i].turn_around_time;
  }

  return sum / number_of_processes;
}

void schedule(process processes[]) {

  // We gonna use approach based on a current time
  int current_time = 0;

  // TRUE if some processes are not yet executed, FALSE otherwise
  int can_process = 1;

  // Now we need to sort all the processes in advance
  sort_processes(processes);

  while(can_process) {

    can_process = 0;

    for (int i = 0; i < number_of_processes; i++) {

      // At each iteration, the current time is
      //   either the same time after previous process exacution
      //   or the arriving time of the next process (if our "CPU" is idle)
      current_time = max(current_time, processes[i].arriving_time);

      // Updating necessary values
      processes[i].completion_time = min(processes[i].burst_time, quantum) + current_time;
      processes[i].turn_around_time = processes[i].completion_time - processes[i].arriving_time;
      processes[i].waiting_time = processes[i].turn_around_time - min(processes[i].burst_time, quantum);

      // Busrt time should be decreased for the next processing
      processes[i].burst_time = processes[i].burst_time - min(processes[i].burst_time, quantum);

      // If it becomes 0, the process is completely executed
      if (processes[i].burst_time == 0) {
        processes[i].done = TRUE;
      }

      // Current time now is the completion time of just executed process
      current_time = processes[i].completion_time;
    }

    // Checking if some processes are not executed yet
    for (int i = 0; i < number_of_processes; i++) {
      if (processes[i].done == FALSE) {
        can_process = TRUE;
      }
    }

  }
}

// Sorting algorithm for processes
void sort_processes(process processes[]) {
  for (int i = 0 ; i < number_of_processes - 1; i++) {
    for (int j = 0 ; j < number_of_processes - i - 1; j++) {
      // Comparing by arriving time first
      if (processes[j].arriving_time > processes[j+1].arriving_time) {
        process temp = processes[j];
        processes[j] = processes[j+1];
        processes[j+1] = temp;
      } else if (processes[j].arriving_time == processes[j+1].arriving_time) {
        // Then by burst time
        if (processes[j].burst_time > processes[j+1].burst_time){
          process temp = processes[j];
          processes[j] = processes[j+1];
          processes[j+1] = temp;
        }
      }
    }
  }
}

void print_table(process processes[]) {
  printf("==========================\n");
  printf("%-5s%-4s%-4s%-4s%-4s%-4s\n", "Id", "AT", "BT", "CT", "WT", "TAT");

  for (int i = 0; i < number_of_processes; i++) {
    printf("%-5d%-4d", processes[i].pid, processes[i].arriving_time);
    printf("%-4d%-4d", processes[i].burst_time, processes[i].completion_time);
    printf("%-4d%-4d\n", processes[i].waiting_time, processes[i].turn_around_time);
  }

  printf("\nAverage waiting time: %.2f\n", mean_wt(processes));
  printf("Average turn around time: %.2f\n", mean_tat(processes));
  printf("==========================\n");
  printf("**************************\n");
}
