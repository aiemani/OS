#include <stdio.h>

#define max(a,b) (a < b ? b : a)

typedef struct process{
  int arriving_time;
  int burst_time;
  int completion_time;
  int waiting_time;
  int turn_around_time;
} process;

// Global variables for the current ime position and the number of processes
int current_time, number_of_processes;

float mean_wt(process processes[]);
float mean_tat(process processes[]);
void schedule(process processes[]);
void print_table(process processes[]);

int main(){

  scanf("%d", &number_of_processes);
  process processes[number_of_processes];

  for (int i = 0; i < number_of_processes; i++) {
    scanf("%d %d", &processes[i].arriving_time, &processes[i].burst_time);
  }

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

  current_time = 0;

  for (int i = 0; i < number_of_processes; i++) {
    current_time = max(current_time, processes[i].arriving_time);

    processes[i].completion_time = processes[i].burst_time + current_time;
    processes[i].turn_around_time = processes[i].completion_time - processes[i].arriving_time;
    processes[i].waiting_time = processes[i].turn_around_time - processes[i].burst_time;

    current_time = processes[i].completion_time;
  }
}

void print_table(process processes[]) {
  printf("%-5s%-4s%-4s%-4s%-4s%-4s\n", "Id", "AT", "BT", "CT", "WT", "TAT");

  for (int i = 0; i < number_of_processes; i++) {
    printf("%-5d%-4d", i, processes[i].arriving_time);
    printf("%-4d%-4d", processes[i].burst_time, processes[i].completion_time);
    printf("%-4d%-4d\n", processes[i].waiting_time, processes[i].turn_around_time);
  }

  printf("\nAverage waiting time: %.2f\n", mean_wt(processes));
  printf("Average turn around time: %.2f\n", mean_tat(processes));
}