#include<stdio.h>

int main(){
    int processID[] = {0,1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(process_id)/sizeof(process_id[0]);  //Find number of processes
    int burst_time[] = {5,3,2,4,2,3,1,5,3,4};
    int exit_time[10],t=0;
    for(int i=0;i<n;i++){   // Function to calculate exit time
        t=t+burst_time[i];  // exit time of process = sum of burst time of all previous processes
        exit_time[i] = t;
    }
    for(int i=0;i<n;i++){
        printf("Executing process %d\n",process_id[i]);
    }
    for(int i=0;i<n;i++){
        printf("Process %d\t%d\t%d\n",process_id[i],burst_time[i],exit_time[i]);
    }
    return 0;
}