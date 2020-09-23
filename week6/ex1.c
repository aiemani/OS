#include <stdio.h>

#define max(a,b) (a < b ? b : a)

// Structure that represents a process
typedef struct process{
  // Required metrics
  int arriving_time;
  int burst_time;
  int completion_time;
  int waiting_time;
  int turn_around_time;
} process;

// Global variable for the number of processes
int number_of_processes;

// Evaluate values "Average waiting time" and "Average turn around time"
float mean_wt(process processes[]);
float mean_tat(process processes[]);

// Key scheduling function
void schedule(process processes[]);

// Just printing function
void print_table(process processes[]);

int main(){

  // Reading the number of processes
  scanf("%d", &number_of_processes);

  // Creating an array of processes
  process processes[number_of_processes];

  // Filling in the format "Arriving_time Burst_time" for each process
  for (int i = 0; i < number_of_processes; i++) {
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

  for (int i = 0; i < number_of_processes; i++) {

    // At each iteration, the current time is 
    //   either the same time after previous process exacution
    //   or the arriving time of the next process (if our "CPU" is idle)
    current_time = max(current_time, processes[i].arriving_time);

    // Updating necessary values
    processes[i].completion_time = processes[i].burst_time + current_time;
    processes[i].turn_around_time = processes[i].completion_time - processes[i].arriving_time;
    processes[i].waiting_time = processes[i].turn_around_time - processes[i].burst_time;

    // Current time now is the completion time of just executed process
    current_time = processes[i].completion_time;
  }
}

void print_table(process processes[]) {
  printf("==========================\n");
  printf("%-5s%-4s%-4s%-4s%-4s%-4s\n", "Id", "AT", "BT", "CT", "WT", "TAT");

  for (int i = 0; i < number_of_processes; i++) {
    printf("%-5d%-4d", i, processes[i].arriving_time);
    printf("%-4d%-4d", processes[i].burst_time, processes[i].completion_time);
    printf("%-4d%-4d\n", processes[i].waiting_time, processes[i].turn_around_time);
  }

  printf("\nAverage waiting time: %.2f\n", mean_wt(processes));
  printf("Average turn around time: %.2f\n", mean_tat(processes));
  printf("==========================\n");
  printf("**************************\n");
}